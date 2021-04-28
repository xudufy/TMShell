
// Generated from C:/projects/TMShell/grammar/TMSlang.g4 by ANTLR 4.9.2


#include "TMSlangVisitor.h"

#include "TMSlangParser.h"


using namespace antlrcpp;
using namespace tmshell;
using namespace antlr4;

TMSlangParser::TMSlangParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

TMSlangParser::~TMSlangParser() {
  delete _interpreter;
}

std::string TMSlangParser::getGrammarFileName() const {
  return "TMSlang.g4";
}

const std::vector<std::string>& TMSlangParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& TMSlangParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

TMSlangParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TMSlangParser::Execute_lineContext *> TMSlangParser::ProgramContext::execute_line() {
  return getRuleContexts<TMSlangParser::Execute_lineContext>();
}

TMSlangParser::Execute_lineContext* TMSlangParser::ProgramContext::execute_line(size_t i) {
  return getRuleContext<TMSlangParser::Execute_lineContext>(i);
}


size_t TMSlangParser::ProgramContext::getRuleIndex() const {
  return TMSlangParser::RuleProgram;
}


antlrcpp::Any TMSlangParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

TMSlangParser::ProgramContext* TMSlangParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, TMSlangParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(15); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(14);
      execute_line();
      setState(17); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TMSlangParser::T__11)
      | (1ULL << TMSlangParser::T__20)
      | (1ULL << TMSlangParser::T__21)
      | (1ULL << TMSlangParser::COLON)
      | (1ULL << TMSlangParser::LEFTBRACE)
      | (1ULL << TMSlangParser::VAR)
      | (1ULL << TMSlangParser::ID)
      | (1ULL << TMSlangParser::TimePointLiteral)
      | (1ULL << TMSlangParser::DurationLiteral)
      | (1ULL << TMSlangParser::IntegerLiteral)
      | (1ULL << TMSlangParser::StringLiteral))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Execute_lineContext ------------------------------------------------------------------

TMSlangParser::Execute_lineContext::Execute_lineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TMSlangParser::Execute_lineContext::NEWLINE() {
  return getToken(TMSlangParser::NEWLINE, 0);
}

TMSlangParser::Mgmt_commandContext* TMSlangParser::Execute_lineContext::mgmt_command() {
  return getRuleContext<TMSlangParser::Mgmt_commandContext>(0);
}

TMSlangParser::VarDefContext* TMSlangParser::Execute_lineContext::varDef() {
  return getRuleContext<TMSlangParser::VarDefContext>(0);
}

TMSlangParser::TriggerDefContext* TMSlangParser::Execute_lineContext::triggerDef() {
  return getRuleContext<TMSlangParser::TriggerDefContext>(0);
}


size_t TMSlangParser::Execute_lineContext::getRuleIndex() const {
  return TMSlangParser::RuleExecute_line;
}


antlrcpp::Any TMSlangParser::Execute_lineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitExecute_line(this);
  else
    return visitor->visitChildren(this);
}

TMSlangParser::Execute_lineContext* TMSlangParser::execute_line() {
  Execute_lineContext *_localctx = _tracker.createInstance<Execute_lineContext>(_ctx, getState());
  enterRule(_localctx, 2, TMSlangParser::RuleExecute_line);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(22);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(19);
      mgmt_command();
      break;
    }

    case 2: {
      setState(20);
      varDef();
      break;
    }

    case 3: {
      setState(21);
      triggerDef();
      break;
    }

    default:
      break;
    }
    setState(24);
    match(TMSlangParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mgmt_commandContext ------------------------------------------------------------------

TMSlangParser::Mgmt_commandContext::Mgmt_commandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TMSlangParser::Mgmt_commandContext::COLON() {
  return getToken(TMSlangParser::COLON, 0);
}

std::vector<TMSlangParser::Cmd_argContext *> TMSlangParser::Mgmt_commandContext::cmd_arg() {
  return getRuleContexts<TMSlangParser::Cmd_argContext>();
}

TMSlangParser::Cmd_argContext* TMSlangParser::Mgmt_commandContext::cmd_arg(size_t i) {
  return getRuleContext<TMSlangParser::Cmd_argContext>(i);
}


size_t TMSlangParser::Mgmt_commandContext::getRuleIndex() const {
  return TMSlangParser::RuleMgmt_command;
}


antlrcpp::Any TMSlangParser::Mgmt_commandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitMgmt_command(this);
  else
    return visitor->visitChildren(this);
}

TMSlangParser::Mgmt_commandContext* TMSlangParser::mgmt_command() {
  Mgmt_commandContext *_localctx = _tracker.createInstance<Mgmt_commandContext>(_ctx, getState());
  enterRule(_localctx, 4, TMSlangParser::RuleMgmt_command);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    match(TMSlangParser::COLON);
    setState(27);
    dynamic_cast<Mgmt_commandContext *>(_localctx)->command_name = cmd_arg();
    setState(31);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TMSlangParser::TEXTARG

    || _la == TMSlangParser::StringLiteral) {
      setState(28);
      dynamic_cast<Mgmt_commandContext *>(_localctx)->cmd_argContext = cmd_arg();
      dynamic_cast<Mgmt_commandContext *>(_localctx)->args.push_back(dynamic_cast<Mgmt_commandContext *>(_localctx)->cmd_argContext);
      setState(33);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cmd_argContext ------------------------------------------------------------------

TMSlangParser::Cmd_argContext::Cmd_argContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TMSlangParser::Cmd_argContext::getRuleIndex() const {
  return TMSlangParser::RuleCmd_arg;
}

void TMSlangParser::Cmd_argContext::copyFrom(Cmd_argContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PlainArgContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::PlainArgContext::TEXTARG() {
  return getToken(TMSlangParser::TEXTARG, 0);
}

TMSlangParser::PlainArgContext::PlainArgContext(Cmd_argContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::PlainArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitPlainArg(this);
  else
    return visitor->visitChildren(this);
}
//----------------- QuotedArgContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::QuotedArgContext::StringLiteral() {
  return getToken(TMSlangParser::StringLiteral, 0);
}

TMSlangParser::QuotedArgContext::QuotedArgContext(Cmd_argContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::QuotedArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitQuotedArg(this);
  else
    return visitor->visitChildren(this);
}
TMSlangParser::Cmd_argContext* TMSlangParser::cmd_arg() {
  Cmd_argContext *_localctx = _tracker.createInstance<Cmd_argContext>(_ctx, getState());
  enterRule(_localctx, 6, TMSlangParser::RuleCmd_arg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(36);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TMSlangParser::StringLiteral: {
        _localctx = dynamic_cast<Cmd_argContext *>(_tracker.createInstance<TMSlangParser::QuotedArgContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(34);
        match(TMSlangParser::StringLiteral);
        break;
      }

      case TMSlangParser::TEXTARG: {
        _localctx = dynamic_cast<Cmd_argContext *>(_tracker.createInstance<TMSlangParser::PlainArgContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(35);
        match(TMSlangParser::TEXTARG);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

TMSlangParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TMSlangParser::VarDefContext::getRuleIndex() const {
  return TMSlangParser::RuleVarDef;
}

void TMSlangParser::VarDefContext::copyFrom(VarDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- GlobalVarDefContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::GlobalVarDefContext::VAR() {
  return getToken(TMSlangParser::VAR, 0);
}

tree::TerminalNode* TMSlangParser::GlobalVarDefContext::GLOBAL() {
  return getToken(TMSlangParser::GLOBAL, 0);
}

tree::TerminalNode* TMSlangParser::GlobalVarDefContext::ID() {
  return getToken(TMSlangParser::ID, 0);
}

TMSlangParser::ExprContext* TMSlangParser::GlobalVarDefContext::expr() {
  return getRuleContext<TMSlangParser::ExprContext>(0);
}

TMSlangParser::GlobalVarDefContext::GlobalVarDefContext(VarDefContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::GlobalVarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitGlobalVarDef(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SessionVarDefContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::SessionVarDefContext::VAR() {
  return getToken(TMSlangParser::VAR, 0);
}

tree::TerminalNode* TMSlangParser::SessionVarDefContext::ID() {
  return getToken(TMSlangParser::ID, 0);
}

TMSlangParser::ExprContext* TMSlangParser::SessionVarDefContext::expr() {
  return getRuleContext<TMSlangParser::ExprContext>(0);
}

TMSlangParser::SessionVarDefContext::SessionVarDefContext(VarDefContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::SessionVarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitSessionVarDef(this);
  else
    return visitor->visitChildren(this);
}
TMSlangParser::VarDefContext* TMSlangParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 8, TMSlangParser::RuleVarDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(47);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<TMSlangParser::SessionVarDefContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(38);
      match(TMSlangParser::VAR);
      setState(39);
      match(TMSlangParser::ID);
      setState(40);
      match(TMSlangParser::T__0);
      setState(41);
      expr(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<TMSlangParser::GlobalVarDefContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(42);
      match(TMSlangParser::VAR);
      setState(43);
      match(TMSlangParser::GLOBAL);
      setState(44);
      match(TMSlangParser::ID);
      setState(45);
      match(TMSlangParser::T__0);
      setState(46);
      expr(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TriggerDefContext ------------------------------------------------------------------

TMSlangParser::TriggerDefContext::TriggerDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TMSlangParser::TriggerDefContext::RIGHTARROW() {
  return getToken(TMSlangParser::RIGHTARROW, 0);
}

std::vector<TMSlangParser::ExprContext *> TMSlangParser::TriggerDefContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::TriggerDefContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

tree::TerminalNode* TMSlangParser::TriggerDefContext::POUND() {
  return getToken(TMSlangParser::POUND, 0);
}

TMSlangParser::Cmd_argContext* TMSlangParser::TriggerDefContext::cmd_arg() {
  return getRuleContext<TMSlangParser::Cmd_argContext>(0);
}


size_t TMSlangParser::TriggerDefContext::getRuleIndex() const {
  return TMSlangParser::RuleTriggerDef;
}


antlrcpp::Any TMSlangParser::TriggerDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitTriggerDef(this);
  else
    return visitor->visitChildren(this);
}

TMSlangParser::TriggerDefContext* TMSlangParser::triggerDef() {
  TriggerDefContext *_localctx = _tracker.createInstance<TriggerDefContext>(_ctx, getState());
  enterRule(_localctx, 10, TMSlangParser::RuleTriggerDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    dynamic_cast<TriggerDefContext *>(_localctx)->signal = expr(0);
    setState(52);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TMSlangParser::POUND) {
      setState(50);
      match(TMSlangParser::POUND);
      setState(51);
      dynamic_cast<TriggerDefContext *>(_localctx)->trigger_name = cmd_arg();
    }
    setState(54);
    match(TMSlangParser::RIGHTARROW);
    setState(55);
    dynamic_cast<TriggerDefContext *>(_localctx)->action = expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

TMSlangParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TMSlangParser::ExprContext::getRuleIndex() const {
  return TMSlangParser::RuleExpr;
}

void TMSlangParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MulExprContext ------------------------------------------------------------------

std::vector<TMSlangParser::ExprContext *> TMSlangParser::MulExprContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::MulExprContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

TMSlangParser::MulExprContext::MulExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::MulExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitMulExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IDExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::IDExprContext::ID() {
  return getToken(TMSlangParser::ID, 0);
}

TMSlangParser::IDExprContext::IDExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::IDExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitIDExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqlExprContext ------------------------------------------------------------------

std::vector<TMSlangParser::ExprContext *> TMSlangParser::EqlExprContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::EqlExprContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

TMSlangParser::EqlExprContext::EqlExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::EqlExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitEqlExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfExprContext ------------------------------------------------------------------

std::vector<TMSlangParser::ExprContext *> TMSlangParser::IfExprContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::IfExprContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

TMSlangParser::IfExprContext::IfExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::IfExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitIfExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelExprContext ------------------------------------------------------------------

std::vector<TMSlangParser::ExprContext *> TMSlangParser::RelExprContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::RelExprContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

TMSlangParser::RelExprContext::RelExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::RelExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitRelExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PeriodicExprContext ------------------------------------------------------------------

std::vector<TMSlangParser::ExprContext *> TMSlangParser::PeriodicExprContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::PeriodicExprContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

TMSlangParser::PeriodicExprContext::PeriodicExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::PeriodicExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitPeriodicExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddExprContext ------------------------------------------------------------------

std::vector<TMSlangParser::ExprContext *> TMSlangParser::AddExprContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::AddExprContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

TMSlangParser::AddExprContext::AddExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::AddExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitAddExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DurationLExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::DurationLExprContext::DurationLiteral() {
  return getToken(TMSlangParser::DurationLiteral, 0);
}

TMSlangParser::DurationLExprContext::DurationLExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::DurationLExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitDurationLExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::AssignExprContext::ID() {
  return getToken(TMSlangParser::ID, 0);
}

TMSlangParser::ExprContext* TMSlangParser::AssignExprContext::expr() {
  return getRuleContext<TMSlangParser::ExprContext>(0);
}

TMSlangParser::AssignExprContext::AssignExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::AssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GroupExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::GroupExprContext::LEFTBRACE() {
  return getToken(TMSlangParser::LEFTBRACE, 0);
}

tree::TerminalNode* TMSlangParser::GroupExprContext::RIGHTBRACE() {
  return getToken(TMSlangParser::RIGHTBRACE, 0);
}

std::vector<TMSlangParser::ExprContext *> TMSlangParser::GroupExprContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::GroupExprContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

TMSlangParser::GroupExprContext::GroupExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::GroupExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitGroupExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TimePointLExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::TimePointLExprContext::TimePointLiteral() {
  return getToken(TMSlangParser::TimePointLiteral, 0);
}

TMSlangParser::TimePointLExprContext::TimePointLExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::TimePointLExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitTimePointLExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringLExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::StringLExprContext::StringLiteral() {
  return getToken(TMSlangParser::StringLiteral, 0);
}

TMSlangParser::StringLExprContext::StringLExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::StringLExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitStringLExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LaterExprContext ------------------------------------------------------------------

TMSlangParser::ExprContext* TMSlangParser::LaterExprContext::expr() {
  return getRuleContext<TMSlangParser::ExprContext>(0);
}

TMSlangParser::LaterExprContext::LaterExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::LaterExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitLaterExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CurrentExprContext ------------------------------------------------------------------

TMSlangParser::CurrentExprContext::CurrentExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::CurrentExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitCurrentExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntLExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::IntLExprContext::IntegerLiteral() {
  return getToken(TMSlangParser::IntegerLiteral, 0);
}

TMSlangParser::IntLExprContext::IntLExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::IntLExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitIntLExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LocalVarDefExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::LocalVarDefExprContext::VAR() {
  return getToken(TMSlangParser::VAR, 0);
}

tree::TerminalNode* TMSlangParser::LocalVarDefExprContext::ID() {
  return getToken(TMSlangParser::ID, 0);
}

TMSlangParser::ExprContext* TMSlangParser::LocalVarDefExprContext::expr() {
  return getRuleContext<TMSlangParser::ExprContext>(0);
}

TMSlangParser::LocalVarDefExprContext::LocalVarDefExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::LocalVarDefExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitLocalVarDefExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::CallExprContext::ID() {
  return getToken(TMSlangParser::ID, 0);
}

std::vector<TMSlangParser::ExprContext *> TMSlangParser::CallExprContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::CallExprContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

TMSlangParser::CallExprContext::CallExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::CallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitCallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FieldExprContext ------------------------------------------------------------------

TMSlangParser::ExprContext* TMSlangParser::FieldExprContext::expr() {
  return getRuleContext<TMSlangParser::ExprContext>(0);
}

tree::TerminalNode* TMSlangParser::FieldExprContext::ID() {
  return getToken(TMSlangParser::ID, 0);
}

TMSlangParser::FieldExprContext::FieldExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::FieldExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitFieldExpr(this);
  else
    return visitor->visitChildren(this);
}

TMSlangParser::ExprContext* TMSlangParser::expr() {
   return expr(0);
}

TMSlangParser::ExprContext* TMSlangParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TMSlangParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  TMSlangParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, TMSlangParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(105);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<IfExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(58);
      match(TMSlangParser::T__11);
      setState(59);
      match(TMSlangParser::T__12);
      setState(60);
      expr(0);
      setState(61);
      match(TMSlangParser::T__13);
      setState(62);
      expr(0);
      setState(65);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
      case 1: {
        setState(63);
        match(TMSlangParser::T__14);
        setState(64);
        expr(0);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<LocalVarDefExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(67);
      match(TMSlangParser::VAR);
      setState(68);
      match(TMSlangParser::ID);
      setState(69);
      match(TMSlangParser::T__0);
      setState(70);
      expr(13);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<AssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(71);
      match(TMSlangParser::ID);
      setState(72);
      match(TMSlangParser::T__0);
      setState(73);
      expr(12);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(74);
      match(TMSlangParser::ID);
      setState(75);
      match(TMSlangParser::T__12);
      setState(84);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TMSlangParser::T__11)
        | (1ULL << TMSlangParser::T__20)
        | (1ULL << TMSlangParser::T__21)
        | (1ULL << TMSlangParser::LEFTBRACE)
        | (1ULL << TMSlangParser::VAR)
        | (1ULL << TMSlangParser::ID)
        | (1ULL << TMSlangParser::TimePointLiteral)
        | (1ULL << TMSlangParser::DurationLiteral)
        | (1ULL << TMSlangParser::IntegerLiteral)
        | (1ULL << TMSlangParser::StringLiteral))) != 0)) {
        setState(76);
        expr(0);
        setState(81);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == TMSlangParser::T__18) {
          setState(77);
          match(TMSlangParser::T__18);
          setState(78);
          expr(0);
          setState(83);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(86);
      match(TMSlangParser::T__13);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<GroupExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(87);
      match(TMSlangParser::LEFTBRACE);
      setState(93);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TMSlangParser::T__11)
        | (1ULL << TMSlangParser::T__20)
        | (1ULL << TMSlangParser::T__21)
        | (1ULL << TMSlangParser::LEFTBRACE)
        | (1ULL << TMSlangParser::VAR)
        | (1ULL << TMSlangParser::ID)
        | (1ULL << TMSlangParser::TimePointLiteral)
        | (1ULL << TMSlangParser::DurationLiteral)
        | (1ULL << TMSlangParser::IntegerLiteral)
        | (1ULL << TMSlangParser::StringLiteral))) != 0)) {
        setState(88);
        expr(0);
        setState(89);
        match(TMSlangParser::T__19);
        setState(95);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(96);
      match(TMSlangParser::RIGHTBRACE);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<IDExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(97);
      match(TMSlangParser::ID);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<LaterExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(98);
      match(TMSlangParser::T__20);
      setState(99);
      expr(6);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<CurrentExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(100);
      match(TMSlangParser::T__21);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<TimePointLExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(101);
      match(TMSlangParser::TimePointLiteral);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<DurationLExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(102);
      match(TMSlangParser::DurationLiteral);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<StringLExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(103);
      match(TMSlangParser::StringLiteral);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<IntLExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(104);
      match(TMSlangParser::IntegerLiteral);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(131);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(129);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(107);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(108);
          _la = _input->LA(1);
          if (!(_la == TMSlangParser::T__1

          || _la == TMSlangParser::T__2)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(109);
          expr(19);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(110);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(111);
          _la = _input->LA(1);
          if (!(_la == TMSlangParser::T__3

          || _la == TMSlangParser::T__4)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(112);
          expr(18);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(113);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(114);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << TMSlangParser::T__5)
            | (1ULL << TMSlangParser::T__6)
            | (1ULL << TMSlangParser::T__7)
            | (1ULL << TMSlangParser::T__8))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(115);
          expr(17);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EqlExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(116);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(117);
          _la = _input->LA(1);
          if (!(_la == TMSlangParser::T__9

          || _la == TMSlangParser::T__10)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(118);
          expr(16);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<PeriodicExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(119);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(120);
          match(TMSlangParser::T__15);
          setState(121);
          expr(0);
          setState(124);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
          case 1: {
            setState(122);
            match(TMSlangParser::T__16);
            setState(123);
            expr(0);
            break;
          }

          default:
            break;
          }
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<FieldExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(126);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(127);
          match(TMSlangParser::T__17);
          setState(128);
          match(TMSlangParser::ID);
          break;
        }

        default:
          break;
        } 
      }
      setState(133);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool TMSlangParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TMSlangParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 18);
    case 1: return precpred(_ctx, 17);
    case 2: return precpred(_ctx, 16);
    case 3: return precpred(_ctx, 15);
    case 4: return precpred(_ctx, 11);
    case 5: return precpred(_ctx, 10);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> TMSlangParser::_decisionToDFA;
atn::PredictionContextCache TMSlangParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN TMSlangParser::_atn;
std::vector<uint16_t> TMSlangParser::_serializedATN;

std::vector<std::string> TMSlangParser::_ruleNames = {
  "program", "execute_line", "mgmt_command", "cmd_arg", "varDef", "triggerDef", 
  "expr"
};

std::vector<std::string> TMSlangParser::_literalNames = {
  "", "'='", "'*'", "'/'", "'+'", "'-'", "'<'", "'>'", "'<='", "'>='", "'=='", 
  "'!='", "'if'", "'('", "')'", "'else'", "'<<<'", "'>>>'", "'.'", "','", 
  "';'", "'>>'", "'<.>'", "':'", "'#'", "'{'", "'}'", "'=>'", "", "'var'", 
  "'session'", "'global'"
};

std::vector<std::string> TMSlangParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "COLON", "POUND", "LEFTBRACE", "RIGHTBRACE", "RIGHTARROW", 
  "TEXTARG", "VAR", "SESSION", "GLOBAL", "ID", "TimePointLiteral", "DurationLiteral", 
  "DurationFragment", "IntegerLiteral", "StringLiteral", "WS", "ESCAPEDNEWLINE", 
  "NEWLINE_SKIP", "NEWLINE", "ERRORCHAR"
};

dfa::Vocabulary TMSlangParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> TMSlangParser::_tokenNames;

TMSlangParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x2c, 0x89, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x3, 0x2, 0x6, 0x2, 0x12, 0xa, 0x2, 0xd, 
       0x2, 0xe, 0x2, 0x13, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x19, 
       0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 
       0x4, 0x20, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x23, 0xb, 0x4, 0x3, 0x5, 
       0x3, 0x5, 0x5, 0x5, 0x27, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
       0x6, 0x32, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x37, 
       0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 
       0x44, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x7, 0x8, 0x52, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x55, 0xb, 0x8, 
       0x5, 0x8, 0x57, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x7, 0x8, 0x5e, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x61, 0xb, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x6c, 0xa, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x7f, 0xa, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x84, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 
       0x87, 0xb, 0x8, 0x3, 0x8, 0x2, 0x3, 0xe, 0x9, 0x2, 0x4, 0x6, 0x8, 
       0xa, 0xc, 0xe, 0x2, 0x6, 0x3, 0x2, 0x4, 0x5, 0x3, 0x2, 0x6, 0x7, 
       0x3, 0x2, 0x8, 0xb, 0x3, 0x2, 0xc, 0xd, 0x2, 0x9e, 0x2, 0x11, 0x3, 
       0x2, 0x2, 0x2, 0x4, 0x18, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1c, 0x3, 0x2, 
       0x2, 0x2, 0x8, 0x26, 0x3, 0x2, 0x2, 0x2, 0xa, 0x31, 0x3, 0x2, 0x2, 
       0x2, 0xc, 0x33, 0x3, 0x2, 0x2, 0x2, 0xe, 0x6b, 0x3, 0x2, 0x2, 0x2, 
       0x10, 0x12, 0x5, 0x4, 0x3, 0x2, 0x11, 0x10, 0x3, 0x2, 0x2, 0x2, 0x12, 
       0x13, 0x3, 0x2, 0x2, 0x2, 0x13, 0x11, 0x3, 0x2, 0x2, 0x2, 0x13, 0x14, 
       0x3, 0x2, 0x2, 0x2, 0x14, 0x3, 0x3, 0x2, 0x2, 0x2, 0x15, 0x19, 0x5, 
       0x6, 0x4, 0x2, 0x16, 0x19, 0x5, 0xa, 0x6, 0x2, 0x17, 0x19, 0x5, 0xc, 
       0x7, 0x2, 0x18, 0x15, 0x3, 0x2, 0x2, 0x2, 0x18, 0x16, 0x3, 0x2, 0x2, 
       0x2, 0x18, 0x17, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 0x3, 0x2, 0x2, 0x2, 
       0x1a, 0x1b, 0x7, 0x2b, 0x2, 0x2, 0x1b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x1c, 
       0x1d, 0x7, 0x19, 0x2, 0x2, 0x1d, 0x21, 0x5, 0x8, 0x5, 0x2, 0x1e, 
       0x20, 0x5, 0x8, 0x5, 0x2, 0x1f, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x23, 
       0x3, 0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x3, 
       0x2, 0x2, 0x2, 0x22, 0x7, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 
       0x2, 0x2, 0x24, 0x27, 0x7, 0x27, 0x2, 0x2, 0x25, 0x27, 0x7, 0x1e, 
       0x2, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x25, 0x3, 0x2, 0x2, 
       0x2, 0x27, 0x9, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x7, 0x1f, 0x2, 0x2, 
       0x29, 0x2a, 0x7, 0x22, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0x3, 0x2, 0x2, 
       0x2b, 0x32, 0x5, 0xe, 0x8, 0x2, 0x2c, 0x2d, 0x7, 0x1f, 0x2, 0x2, 
       0x2d, 0x2e, 0x7, 0x21, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0x22, 0x2, 0x2, 
       0x2f, 0x30, 0x7, 0x3, 0x2, 0x2, 0x30, 0x32, 0x5, 0xe, 0x8, 0x2, 0x31, 
       0x28, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x32, 0xb, 
       0x3, 0x2, 0x2, 0x2, 0x33, 0x36, 0x5, 0xe, 0x8, 0x2, 0x34, 0x35, 0x7, 
       0x1a, 0x2, 0x2, 0x35, 0x37, 0x5, 0x8, 0x5, 0x2, 0x36, 0x34, 0x3, 
       0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x3, 0x2, 
       0x2, 0x2, 0x38, 0x39, 0x7, 0x1d, 0x2, 0x2, 0x39, 0x3a, 0x5, 0xe, 
       0x8, 0x2, 0x3a, 0xd, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x8, 0x8, 0x1, 
       0x2, 0x3c, 0x3d, 0x7, 0xe, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0xf, 0x2, 0x2, 
       0x3e, 0x3f, 0x5, 0xe, 0x8, 0x2, 0x3f, 0x40, 0x7, 0x10, 0x2, 0x2, 
       0x40, 0x43, 0x5, 0xe, 0x8, 0x2, 0x41, 0x42, 0x7, 0x11, 0x2, 0x2, 
       0x42, 0x44, 0x5, 0xe, 0x8, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 
       0x44, 0x3, 0x2, 0x2, 0x2, 0x44, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 
       0x7, 0x1f, 0x2, 0x2, 0x46, 0x47, 0x7, 0x22, 0x2, 0x2, 0x47, 0x48, 
       0x7, 0x3, 0x2, 0x2, 0x48, 0x6c, 0x5, 0xe, 0x8, 0xf, 0x49, 0x4a, 0x7, 
       0x22, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x3, 0x2, 0x2, 0x4b, 0x6c, 0x5, 
       0xe, 0x8, 0xe, 0x4c, 0x4d, 0x7, 0x22, 0x2, 0x2, 0x4d, 0x56, 0x7, 
       0xf, 0x2, 0x2, 0x4e, 0x53, 0x5, 0xe, 0x8, 0x2, 0x4f, 0x50, 0x7, 0x15, 
       0x2, 0x2, 0x50, 0x52, 0x5, 0xe, 0x8, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 
       0x2, 0x52, 0x55, 0x3, 0x2, 0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 0x2, 
       0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 0x54, 0x57, 0x3, 0x2, 0x2, 0x2, 0x55, 
       0x53, 0x3, 0x2, 0x2, 0x2, 0x56, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 
       0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x6c, 0x7, 
       0x10, 0x2, 0x2, 0x59, 0x5f, 0x7, 0x1b, 0x2, 0x2, 0x5a, 0x5b, 0x5, 
       0xe, 0x8, 0x2, 0x5b, 0x5c, 0x7, 0x16, 0x2, 0x2, 0x5c, 0x5e, 0x3, 
       0x2, 0x2, 0x2, 0x5d, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x61, 0x3, 0x2, 
       0x2, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 0x2, 
       0x2, 0x60, 0x62, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 0x2, 
       0x62, 0x6c, 0x7, 0x1c, 0x2, 0x2, 0x63, 0x6c, 0x7, 0x22, 0x2, 0x2, 
       0x64, 0x65, 0x7, 0x17, 0x2, 0x2, 0x65, 0x6c, 0x5, 0xe, 0x8, 0x8, 
       0x66, 0x6c, 0x7, 0x18, 0x2, 0x2, 0x67, 0x6c, 0x7, 0x23, 0x2, 0x2, 
       0x68, 0x6c, 0x7, 0x24, 0x2, 0x2, 0x69, 0x6c, 0x7, 0x27, 0x2, 0x2, 
       0x6a, 0x6c, 0x7, 0x26, 0x2, 0x2, 0x6b, 0x3b, 0x3, 0x2, 0x2, 0x2, 
       0x6b, 0x45, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x6b, 
       0x4c, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x63, 
       0x3, 0x2, 0x2, 0x2, 0x6b, 0x64, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x66, 0x3, 
       0x2, 0x2, 0x2, 0x6b, 0x67, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x68, 0x3, 0x2, 
       0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6a, 0x3, 0x2, 0x2, 
       0x2, 0x6c, 0x85, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0xc, 0x14, 0x2, 
       0x2, 0x6e, 0x6f, 0x9, 0x2, 0x2, 0x2, 0x6f, 0x84, 0x5, 0xe, 0x8, 0x15, 
       0x70, 0x71, 0xc, 0x13, 0x2, 0x2, 0x71, 0x72, 0x9, 0x3, 0x2, 0x2, 
       0x72, 0x84, 0x5, 0xe, 0x8, 0x14, 0x73, 0x74, 0xc, 0x12, 0x2, 0x2, 
       0x74, 0x75, 0x9, 0x4, 0x2, 0x2, 0x75, 0x84, 0x5, 0xe, 0x8, 0x13, 
       0x76, 0x77, 0xc, 0x11, 0x2, 0x2, 0x77, 0x78, 0x9, 0x5, 0x2, 0x2, 
       0x78, 0x84, 0x5, 0xe, 0x8, 0x12, 0x79, 0x7a, 0xc, 0xd, 0x2, 0x2, 
       0x7a, 0x7b, 0x7, 0x12, 0x2, 0x2, 0x7b, 0x7e, 0x5, 0xe, 0x8, 0x2, 
       0x7c, 0x7d, 0x7, 0x13, 0x2, 0x2, 0x7d, 0x7f, 0x5, 0xe, 0x8, 0x2, 
       0x7e, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7f, 
       0x84, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0xc, 0xc, 0x2, 0x2, 0x81, 0x82, 
       0x7, 0x14, 0x2, 0x2, 0x82, 0x84, 0x7, 0x22, 0x2, 0x2, 0x83, 0x6d, 
       0x3, 0x2, 0x2, 0x2, 0x83, 0x70, 0x3, 0x2, 0x2, 0x2, 0x83, 0x73, 0x3, 
       0x2, 0x2, 0x2, 0x83, 0x76, 0x3, 0x2, 0x2, 0x2, 0x83, 0x79, 0x3, 0x2, 
       0x2, 0x2, 0x83, 0x80, 0x3, 0x2, 0x2, 0x2, 0x84, 0x87, 0x3, 0x2, 0x2, 
       0x2, 0x85, 0x83, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x3, 0x2, 0x2, 0x2, 
       0x86, 0xf, 0x3, 0x2, 0x2, 0x2, 0x87, 0x85, 0x3, 0x2, 0x2, 0x2, 0x10, 
       0x13, 0x18, 0x21, 0x26, 0x31, 0x36, 0x43, 0x53, 0x56, 0x5f, 0x6b, 
       0x7e, 0x83, 0x85, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

TMSlangParser::Initializer TMSlangParser::_init;
