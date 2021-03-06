#include "RegisterExecutor.h"
#include "EventStorage.h"
#include "InternalClock.h"
#include "TypeChecker.h"

namespace tmshell {

std::string runRegister(std::string const & input, RegisterExecutor *reuse) {
  ParserInstance parser(input);
  auto* tree = parser.parseProgram();
  if (!parser.isComleted()) {
    throw ExecutionError(parser.getLastError());
  }

  if (!reuse) {
    TypeChecker tcker;
    tree->accept(&tcker);
  } else {
    TypeChecker tcker(*reuse);
    tree->accept(&tcker);
  }

  if (reuse != nullptr) {
    reuse->log.clear(); // clear the output of last run.
    tree->accept(reuse);
    return reuse->log;
  } else {
    RegisterExecutor re;
    tree->accept(&re);
    return re.log;
  }
  
} 

using var_t = std::unique_ptr<IVariableValue>;

using var_t = std::unique_ptr<IVariableValue>;

antlrcpp::Any RegisterExecutor::visitProgram(TMSlangParser::ProgramContext *context){
  return visitChildren(context);
}

antlrcpp::Any RegisterExecutor::visitExecute_line(TMSlangParser::Execute_lineContext *context){
  visitChildren(context);
  stack.clear();
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitMgmt_command(TMSlangParser::Mgmt_commandContext *context) {
  size_t arg_count = context->args.size();
  visitChildren(context);
  std::vector<std::string> args;
  args.resize(arg_count);
  for (size_t i=arg_count; i-- >0;) {
    auto v = pop_stack();
    auto strv = dynamic_cast<StringValue *>(v.get())->get();
    args[i] = strv;
  }
  std::string cmd_name = dynamic_cast<StringValue *>(pop_stack().get())->get();
  builtinCom.call(cmd_name, args);
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitQuotedArg(TMSlangParser::QuotedArgContext *context) {
  std::string content = context->getText();
  content = unescape_string(content);
  push_stack_v(content);
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitPlainArg(TMSlangParser::PlainArgContext *context) {
  std::string content = context->getText();
  push_stack_v(content);
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitSessionVarDef(TMSlangParser::SessionVarDefContext *context) { 
  visitChildren(context);
  auto v = pop_stack();
  try {
    scope.addSymbol(context->ID()->getText(), *v);
  } catch (ExecutionError const & e) {
    error(context, e);
  }
  push_stack_v();
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitGlobalVarDef(TMSlangParser::GlobalVarDefContext *context) {  
  visitChildren(context);
  auto v = pop_stack();
  try {
    scope.addGlobal(context->ID()->getText(), *v);
  } catch (ExecutionError const & e) {
    error(context, e);
  }
  push_stack_v();
  return nullptr;
}

inline static bool in(std::string const & input, std::vector<std::string> const & list) {
  return std::find(list.begin(), list.end(), input) != list.end();
}

antlrcpp::Any RegisterExecutor::visitTriggerDef(TMSlangParser::TriggerDefContext *context) {
  context->signal->accept(this);
  auto sig = pop_stack();
  auto sigt = sig->getTypeName();
  
  std::string triggerName="<unnamed>";
  if (context->trigger_name!=nullptr) {
    context->trigger_name->accept(this);
    auto name = pop_stack();
    triggerName = iv_get<std::string>(*name);
  }

  auto & ev_s = EventStorage::getInstance();
  if (sigt == "string") {
    StringEvent se;
    se.signal = iv_get<std::string>(*sig);
    se.name = triggerName;
    se.action = getText(context->action); 
    se.unique_id = ev_s.get_unique_id();
    std::lock_guard<std::mutex> lock(ev_s.objmtx);
    ev_s.str_events.push_back(se);
  } else if (sigt == "time_point") {
    TimerEvent te;
    te.name = triggerName;
    te.unique_id = ev_s.get_unique_id();
    te.action = getText(context->action);
    te.haveRepeat = false;
    te.startTime = iv_get<TimePoint>(*sig);
    te.nextTriggerTime = te.startTime;
    std::lock_guard<std::mutex> lock(ev_s.objmtx);
    if (context->signal->getText() == "<.>"){
      ev_s.immediate_events.push_back(te);
    } else {
      ev_s.tm_events.push_back(te);
    }
  } else if (sigt == "periodic") {
    TimerEvent te;
    te.name = triggerName;
    te.unique_id = ev_s.get_unique_id();
    te.action = getText(context->action);
    te.haveRepeat = true;
    auto sigr = dynamic_cast<StructValue *>(sig.get());
    te.startTime = iv_get<TimePoint>(sigr->getField("start"));
    te.endTime = iv_get<TimePoint>(sigr->getField("end"));
    te.period = iv_get<Duration>(sigr->getField("period"));
    
    std::lock_guard<std::mutex> lock(InternalClock::getInstance().objmtx);
    std::lock_guard<std::mutex> lock2(ev_s.objmtx);
    te.update(InternalClock::getInstance().getLastTickPlayTime(), 
            InternalClock::getInstance().getScaler());
    ev_s.tm_events.push_back(te);
  } 

  return nullptr;
}

inline static bool setEqual(std::multiset<std::string> lhs, std::multiset<std::string> rhs) {
  return lhs==rhs;
}

antlrcpp::Any RegisterExecutor::visitMulExpr(TMSlangParser::MulExprContext *context) {    
  visitChildren(context);
  auto v2 = pop_stack();
  auto v1 = pop_stack();
  auto v1t = v1->getTypeName();
  auto v2t = v2->getTypeName();
  auto opr = context->op->getText();
  if (setEqual({v1t, v2t}, {"int", "int"})) {
    
    if (opr=="/") {
      push_stack_v(iv_get<int>(*v1)/iv_get<int>(*v2));
    } else if (opr == "*") {
      push_stack_v(iv_get<int>(*v1)*iv_get<int>(*v2));
    }

  } else if (setEqual({v1t, v2t}, {"int", "duration"}) && opr=="*") {
    
    if (v1t == "duration") {
      push_stack_v(iv_get<Duration>(*v1)*iv_get<int>(*v2));
    } else {
      push_stack_v(iv_get<int>(*v1)*iv_get<Duration>(*v2));
    }
  
  } else {
    error(context, "cannot add " + v1t+ " and " + v2t);
  }
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitIDExpr(TMSlangParser::IDExprContext *context) {
  var_t target;
  try {
    target = scope.getSymbol(context->ID()->getText());
  } catch (ExecutionError const & e) {
    error(context, e);
  }
  push_stack(*target);
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitBoolExpr(TMSlangParser::BoolExprContext *context) {
  if (context->getText() == "true") {
    push_stack_v(true);
  } else {
    push_stack_v(false);
  }
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitEqlExpr(TMSlangParser::EqlExprContext *context) {  
  visitChildren(context);
  auto v2 = pop_stack();
  auto v1 = pop_stack();
  auto v1t = v1->getTypeName();
  auto v2t = v2->getTypeName();
  auto opr = context->op->getText();
  if (v1t != v2t || v1t=="void" || v2t=="void") {
    error(context, "cannot compare " + v1t + " and " + v2t);
  }

  if (opr == "==") {
    auto out = (v1->to_string() == v2->to_string()); 
    push_stack_v(out); 
  }

  if (opr == "!=") {
    auto out = (v1->to_string() != v2->to_string()); 
    push_stack_v(out); 
  }
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitIfExpr(TMSlangParser::IfExprContext *context) {
  context->cond->accept(this);
  auto cond = pop_stack();

  if (cond->getTypeName() != "bool") {
    error(context, "condition is not a bool.");
  }

  bool cond_result = iv_get<bool>(*cond);
  if (cond_result) {
    context->then->accept(this);
  } else if (context->epart != nullptr) {
    context->epart->accept(this);
  }

  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitRelExpr(TMSlangParser::RelExprContext *context) {
  visitChildren(context);
  auto v2 = pop_stack();
  auto v1 = pop_stack();
  auto v1t = v1->getTypeName();
  auto v2t = v2->getTypeName();
  auto opr = context->op->getText();
  if (v1t != v2t || v1t=="void" || v1t == "bool") {
    error(context, "cannot compare " + v1t + " and " + v2t);
  }

  if (v1t != v2t || IVariableValue::is<StructValue>(v1.get())) {
    error(context, "cannot compare " + v1t + " and " + v2t);
  }

#define TMSHELL_AE__L(T, tn, op) \
  if (v1t==(tn)) { \
    auto out = (iv_get<T>(*v1) op iv_get<T>(*v2)); \
    push_stack_v(out); \
  }

#define TMSHELL_AE_ALL_SIMPLE__L(op) \
  TMSHELL_AE__L(int, "int", op) \
  TMSHELL_AE__L(std::string, "string", op) \
  TMSHELL_AE__L(TimePoint, "time_point", op) \
  TMSHELL_AE__L(Duration, "duration", op) 

  if (opr == "<") {
    TMSHELL_AE_ALL_SIMPLE__L(<)
  } else if (opr == ">") {
    TMSHELL_AE_ALL_SIMPLE__L(>)
  } else if (opr == "<=") {
    TMSHELL_AE_ALL_SIMPLE__L(<=)
  } else if (opr == ">=") {
    TMSHELL_AE_ALL_SIMPLE__L(>=)
  }
#undef TMSHELL_AE_ALL_SIMPLE__L
#undef TMSHELL_AE__L

  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitLogicExpr(TMSlangParser::LogicExprContext *context) {  
  context->lhs->accept(this);
  auto v1 = pop_stack();
  auto v1t = v1->getTypeName();
  auto opr = context->op->getText();

  if (v1t != "bool") {
    error(context, "Must be bool: " + v1t);
  }
  auto v1r = iv_get<bool>(*v1);

  if (opr == "||" && v1r) {
    push_stack_v(true);
    return nullptr;
  }

  if (opr == "&&" && (!v1r)) {
    push_stack_v(false);
    return nullptr;
  }
  
  context->rhs->accept(this);
  auto v2 = pop_stack();
  auto v2t = v2->getTypeName();
  if (v2t != "bool") {
    error(context, "Must be bool: " + v2t);
  }
  auto v2r = iv_get<bool>(*v2);
  push_stack_v(v2r);
  
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitPeriodicExpr(TMSlangParser::PeriodicExprContext *context) {
  visitChildren(context);
  StructValue prio("periodic");
  prio.addField("end", TimePointValue(TimePoint::max()));
  var_t v1,v2,v3;
  if (context->end != nullptr) {
    v3 = pop_stack();
    if (v3->getTypeName() != "time_point") {
      goto err;
    }
    prio.setField("end", *v3);
  }

  v2 = pop_stack();
  if (v2->getTypeName() != "duration") {
    goto err;
  }
  prio.addField("period", *v2);

  v1 = pop_stack();
  if (v1->getTypeName() != "time_point") {
    goto err;
  }
  prio.addField("start", *v1);

  push_stack(prio);
  return nullptr;

err:
  error(context, "Periodic type error");
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitNegExpr(TMSlangParser::NegExprContext *context) {  
  visitChildren(context);
  auto v1 = pop_stack();
  auto v1t = v1->getTypeName();
  if (!in(v1t, {"int", "duration"})) {
    error(context, "NegExpr type error");
  }

  if (v1t == "int") {
    push_stack_v(-iv_get<int>(*v1));
  } else if (v1t == "duration") {
    push_stack_v(-iv_get<Duration>(*v1));
  }

  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitAddExpr(TMSlangParser::AddExprContext *context) {  
  visitChildren(context);
  auto v2 = pop_stack();
  auto v1 = pop_stack();
  auto v1t = v1->getTypeName();
  auto v2t = v2->getTypeName();

  auto op = context->op->getText();
  if (op == "+") {
    if (v1t == "string" || v2t == "string") {
      push_stack_v(v1->to_string() + v2->to_string());
      return nullptr;
    }
  }

  if (v1t == v2t && (v1t=="int" || v1t=="duration")) {
    if (v1t == "int") {
      if (op == "-") {
        push_stack_v(iv_get<int>(*v1) - iv_get<int>(*v2));
      } else {
        push_stack_v(iv_get<int>(*v1) + iv_get<int>(*v2));
      } 
    } else if (v1t == "duration") {
      if (op == "-") {
        push_stack_v(iv_get<Duration>(*v1) - iv_get<Duration>(*v2));
      } else {
        push_stack_v(iv_get<Duration>(*v1) + iv_get<Duration>(*v2));
      }
    }
  } else if (v1t == "time_point" && v2t == "duration"){
      if (op == "-") {
        push_stack_v(iv_get<TimePoint>(*v1) - iv_get<Duration>(*v2));
      } else {
        push_stack_v(iv_get<TimePoint>(*v1) + iv_get<Duration>(*v2));
      }
  } else if (v1t == "duration" && v2t == "time_point" && op == "+") {
    push_stack_v(iv_get<Duration>(*v1) + iv_get<TimePoint>(*v2));
  } else {
    error(context, "Addexpr type error");
  }

  return nullptr;
  
}

antlrcpp::Any RegisterExecutor::visitDurationLExpr(TMSlangParser::DurationLExprContext *context) {  
  auto d = to_Duration(context->getText());
  push_stack_v(d);
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitAssignExpr(TMSlangParser::AssignExprContext *context) {  
  visitChildren(context);
  auto v1 = pop_stack();
  auto v1t = v1->getTypeName();
  
  std::vector<std::string> ids;
  for (auto iter: context->id) {
    ids.push_back(iter->getText());
  }

  try {
    scope.setStructSymbol(ids, *v1);
  } catch (ExecutionError const & e) {
    error(context, e);
  }

  push_stack_v();
  return nullptr;

}

antlrcpp::Any RegisterExecutor::visitGroupExpr(TMSlangParser::GroupExprContext *context) {  
  visitChildren(context);
  if (context->inner.size() == 0) {
    push_stack_v();
  }
  auto ret = pop_stack();
  for (int i=0; i < context->inner.size()-1; i++) {
    pop_stack();
  }
  push_stack(*ret);
  return  nullptr;
}

antlrcpp::Any RegisterExecutor::visitTimePointLExpr(TMSlangParser::TimePointLExprContext *context) {  
  push_stack_v(
    to_TimePoint(context->getText())
  );
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitStringLExpr(TMSlangParser::StringLExprContext *context) {  
  push_stack_v(
    unescape_string(context->getText())
  );
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitLaterExpr(TMSlangParser::LaterExprContext *context) {  
  visitChildren(context);
  auto v1 = pop_stack();
  auto v1t = v1->getTypeName();
  if (v1t != "duration") {
    error(context, "LaterExpr expr must be duration.");
  }
    
  push_stack_v(
    std::chrono::system_clock::now() + iv_get<Duration>(*v1)
  );
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitCurrentExpr(TMSlangParser::CurrentExprContext *) {  
  push_stack_v(
    std::chrono::system_clock::now()
  );
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitIntLExpr(TMSlangParser::IntLExprContext *context) {  
  std::stringstream ss(context->getText());
  int t;
  ss>>t;
  push_stack_v(t);
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitLocalVarDefExpr(TMSlangParser::LocalVarDefExprContext *context) {  
  visitChildren(context);
  auto v1 = pop_stack();
  scope.addSymbol(context->ID()->getText(), *v1);
  push_stack_v();
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitCallExpr(TMSlangParser::CallExprContext *context) {  
  visitChildren(context);

  size_t argc = context->args.size();
  std::vector<var_t> argv;
  argv.resize(argc);
  std::vector<IVariableValue *> in_argv; 
  in_argv.resize(argc);
  for (size_t i = argc; i-- > 0;) {
    argv[i] = std::move(pop_stack());
    in_argv[i] = argv[i].get();
  }
  auto out = builtinFuncCtx.call(context->ID()->getText(), in_argv);
  push_stack(*out);
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitNotExpr(TMSlangParser::NotExprContext *context) {  
  visitChildren(context);
  auto v1 = pop_stack();
  auto v1t = v1->getTypeName();
  if (v1t != "bool") {
    error(context, "NotExpr only accept bool.");
  }
  
  push_stack_v(!iv_get<bool>(*v1));
  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitFieldExpr(TMSlangParser::FieldExprContext *context) {  
  visitChildren(context);
  auto v1 = pop_stack();
  auto *v1r = dynamic_cast<StructValue *> (v1.get());
  if (v1r == nullptr) {
    error(context, "lhs is not a struct value.");
  }

  try {
    push_stack(*v1r->getField(context->ID()->getText()));
  } catch (ExecutionError const & e) {
    error(context, e);
  }

  return nullptr;
}

antlrcpp::Any RegisterExecutor::visitParanExpr(TMSlangParser::ParanExprContext *context) {
  visitChildren(context);
  return nullptr;
}

} // namespace tmshell