#include "TypeChecker.h"

namespace tmshell {

using var_t = std::unique_ptr<IVariableValue>;

TypeChecker::TypeChecker():builtinCom(this) {}

TypeChecker::TypeChecker(RegisterExecutor & reuse_session):builtinCom(this) {
  defaultScope = reuse_session.defaultScope; // make a copy.
}

antlrcpp::Any TypeChecker::visitProgram(TMSlangParser::ProgramContext *context){
  return visitChildren(context);
}

antlrcpp::Any TypeChecker::visitExecute_line(TMSlangParser::Execute_lineContext *context){
  visitChildren(context);
  stack.clear();
  return nullptr;
}

antlrcpp::Any TypeChecker::visitMgmt_command(TMSlangParser::Mgmt_commandContext *context) {
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
  builtinCom.call(cmd_name, args, true);
  return nullptr;
}

antlrcpp::Any TypeChecker::visitQuotedArg(TMSlangParser::QuotedArgContext *context) {
  std::string content = context->getText();
  content = unescape_string(content);
  push_stack_v(content);
  return nullptr;
}

antlrcpp::Any TypeChecker::visitPlainArg(TMSlangParser::PlainArgContext *context) {
  std::string content = context->getText();
  push_stack_v(content);
  return nullptr;
}

antlrcpp::Any TypeChecker::visitSessionVarDef(TMSlangParser::SessionVarDefContext *context) { 
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

antlrcpp::Any TypeChecker::visitGlobalVarDef(TMSlangParser::GlobalVarDefContext *context) {  
  visitChildren(context);
  auto v = pop_stack();
  try {
    fakeGlobalScope.addSymbol(context->ID()->getText(), *v);
  } catch (ExecutionError const & e) {
    error(context, e);
  }
  push_stack_v();
  return nullptr;
}

inline static bool in(std::string const & input, std::vector<std::string> const & list) {
  return std::find(list.begin(), list.end(), input) != list.end();
}

antlrcpp::Any TypeChecker::visitTriggerDef(TMSlangParser::TriggerDefContext *context) {
  context->signal->accept(this);
  if (context->trigger_name!= nullptr ) {
    context->trigger_name->accept(this);
    pop_stack();
  }
  scope = actionScope;
  context->action->accept(this);
  pop_stack();
  auto signal = pop_stack();
  if (!in(signal->getTypeName(), {"string", "time_point", "periodic"})) {
    error(context, "signal type invalid");
  }
  scope = defaultScope;
  return nullptr;
}

inline static bool setEqual(std::multiset<std::string> lhs, std::multiset<std::string> rhs) {
  return lhs==rhs;
}

antlrcpp::Any TypeChecker::visitMulExpr(TMSlangParser::MulExprContext *context) {  
  visitChildren(context);
  auto v2 = pop_stack();
  auto v1 = pop_stack();
  auto v1t = v1->getTypeName();
  auto v2t = v2->getTypeName();
  auto opr = context->op->getText();
  if (setEqual({v1t, v2t}, {"int", "int"})) {
    push_stack_v(1);
  } else if (setEqual({v1t, v2t}, {"int", "duration"}) && opr=="*") {
    push_stack_v(Duration(1));
  } else {
    error(context, "cannot add " + v1t+ "  and " + v2t);
  }
  return nullptr;
}

antlrcpp::Any TypeChecker::visitIDExpr(TMSlangParser::IDExprContext *context) {
  std::unique_ptr<IVariableValue> target;
  try {
    target = scope.getSymbol(context->ID()->getText());
  } catch (ExecutionError const &) {
    try {
      target = fakeGlobalScope.getSymbol(context->ID()->getText());
    } catch (ExecutionError const & e) {
      error(context, e);
    }
  }
  push_stack(*target);
  return nullptr;
}

antlrcpp::Any TypeChecker::visitBoolExpr(TMSlangParser::BoolExprContext *context) {
  if (context->getText() == "true") {
    push_stack_v(true);
  } else {
    push_stack_v(false);
  }
  return nullptr;
}

antlrcpp::Any TypeChecker::visitEqlExpr(TMSlangParser::EqlExprContext *context) {  
  visitChildren(context);
  auto v2 = pop_stack();
  auto v1 = pop_stack();
  auto v1t = v1->getTypeName();
  auto v2t = v2->getTypeName();
  if (v1t != v2t || v1t=="void") {
    error(context, "cannot compare " + v1t + " and " + v2t);
  }
  push_stack_v(true);
  return nullptr;
}

antlrcpp::Any TypeChecker::visitIfExpr(TMSlangParser::IfExprContext *context) {
  visitChildren(context);
  if (context->epart!=nullptr) {
    auto e2 = pop_stack();
  }
  auto e1 = pop_stack();
  auto cond = pop_stack();

  if (cond->getTypeName() != "bool") {
    error(context, "condition is not a bool.");
  }

  push_stack_v();
  return nullptr;
}

antlrcpp::Any TypeChecker::visitRelExpr(TMSlangParser::RelExprContext *context) {
  visitChildren(context);
  auto v2 = pop_stack();
  auto v1 = pop_stack();
  auto v1t = v1->getTypeName();
  auto v2t = v2->getTypeName();

  if (v1t != v2t || v1t=="void") {
    error(context, "cannot compare " + v1t + " and " + v2t);
  }

  if (v1t != v2t || IVariableValue::is<StructValue>(v1.get())) {
    error(context, "cannot compare " + v1t + " and " + v2t);
  }

  push_stack_v(true);
  return nullptr;
}

antlrcpp::Any TypeChecker::visitLogicExpr(TMSlangParser::LogicExprContext *context) {  
  visitChildren(context);
  auto v2 = pop_stack();
  auto v1 = pop_stack();
  auto v1t = v1->getTypeName();
  auto v2t = v2->getTypeName();

  if (v1t != "bool" || v2t != "bool") {
    error(context, "Both must be bool: " + v1t + ", " + v2t);
  }

  push_stack_v(true);
  return nullptr;
}

antlrcpp::Any TypeChecker::visitPeriodicExpr(TMSlangParser::PeriodicExprContext *context) {
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

antlrcpp::Any TypeChecker::visitNegExpr(TMSlangParser::NegExprContext *context) {  
  visitChildren(context);
  auto v1 = pop_stack();
  auto v1t = v1->getTypeName();
  if (!in(v1t, {"int", "duration"})) {
    error(context, "NegExpr type error");
  }
  push_stack(*v1);
  return nullptr;
}

antlrcpp::Any TypeChecker::visitAddExpr(TMSlangParser::AddExprContext *context) {  
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
    // pass
  } else {
    error(context, "Addexpr type error");
  }

  push_stack(*v1);
  return nullptr;
  
}

antlrcpp::Any TypeChecker::visitDurationLExpr(TMSlangParser::DurationLExprContext *context) {  
  auto d = to_Duration(context->getText());
  push_stack_v(d);
  return nullptr;
}

antlrcpp::Any TypeChecker::visitAssignExpr(TMSlangParser::AssignExprContext *context) {  
  visitChildren(context);
  auto v1 = pop_stack();
  auto v1t = v1->getTypeName();

  auto id1 = context->id[0]->getText();
  var_t v;
  
  try {
    v = scope.getSymbol(context->id[0]->getText());
  } catch (ExecutionError const &) {
    try {
      v = fakeGlobalScope.getSymbol(context->id[0]->getText());
    } catch (ExecutionError const & e) {
      error(context, e);
    }
  }

  if (context->id.size() > 1) {
    for (int i = 1; i < context->id.size(); i++) {
      if (dynamic_cast<StructValue *>(v.get())) {
        v = dynamic_cast<StructValue *>(v.get()) -> getField(context->id[i]->getText()) -> copy();
      } else {
        error(context, "assignExpr type error");
      }
    }
  }
  
  if (v->getTypeName() != v1t) {
    error(context, "assignExpr type error.");
  } else {
    push_stack(*v1);
    return nullptr;
  }

  return nullptr;

}

antlrcpp::Any TypeChecker::visitGroupExpr(TMSlangParser::GroupExprContext *context) {  
  visitChildren(context);
  for (int i=0; i < context->inner.size()-1; i++) {
    pop_stack();
  }
  return  nullptr;
}

antlrcpp::Any TypeChecker::visitTimePointLExpr(TMSlangParser::TimePointLExprContext *context) {  
  push_stack_v(
    to_TimePoint(context->getText())
  );
  return nullptr;
}

antlrcpp::Any TypeChecker::visitStringLExpr(TMSlangParser::StringLExprContext *context) {  
  push_stack_v(
    unescape_string(context->getText())
  );
  return nullptr;
}

antlrcpp::Any TypeChecker::visitLaterExpr(TMSlangParser::LaterExprContext *context) {  
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

antlrcpp::Any TypeChecker::visitCurrentExpr(TMSlangParser::CurrentExprContext *) {  
  push_stack_v(
    std::chrono::system_clock::now()
  );
  return nullptr;
}

antlrcpp::Any TypeChecker::visitIntLExpr(TMSlangParser::IntLExprContext *context) {  
  std::stringstream ss(context->getText());
  int t;
  ss>>t;
  push_stack_v(t);
  return nullptr;
}

antlrcpp::Any TypeChecker::visitLocalVarDefExpr(TMSlangParser::LocalVarDefExprContext *context) {  
  visitChildren(context);
  auto v1 = pop_stack();
  scope.addSymbol(context->ID()->getText(), *v1);
  push_stack_v();
  return nullptr;
}

antlrcpp::Any TypeChecker::visitCallExpr(TMSlangParser::CallExprContext *context) {  
  visitChildren(context);

  size_t argc = context->args.size();
  std::vector<var_t> argv;
  argv.resize(argc);
  std::vector<IVariableValue *> in_argv; 
  in_argv.resize(argc);
  for (size_t i = argc - 1; i -- > 0; ) {
    argv[i] = std::move(pop_stack());
    in_argv[i] = argv[i].get();
  }
  auto out = builtinFuncCtx.call(context->ID()->getText(), in_argv, true);
  push_stack(*out);
  return nullptr;
}

antlrcpp::Any TypeChecker::visitNotExpr(TMSlangParser::NotExprContext *context) {  
  visitChildren(context);
  auto v1 = pop_stack();
  auto v1t = v1->getTypeName();
  if (v1t != "bool") {
    error(context, "NotExpr only accept bool.");
  }
  
  push_stack_v(!iv_get<bool>(*v1));
  return nullptr;
}

antlrcpp::Any TypeChecker::visitFieldExpr(TMSlangParser::FieldExprContext *context) {  
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

antlrcpp::Any TypeChecker::visitParanExpr(TMSlangParser::ParanExprContext *context) {
  visitChildren(context);
  return nullptr;
}


} // namespace tmshell