
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

std::vector<tree::TerminalNode *> TMSlangParser::ProgramContext::NEWLINE() {
  return getTokens(TMSlangParser::NEWLINE);
}

tree::TerminalNode* TMSlangParser::ProgramContext::NEWLINE(size_t i) {
  return getToken(TMSlangParser::NEWLINE, i);
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
    setState(16); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(16);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TMSlangParser::T__2:
        case TMSlangParser::T__3:
        case TMSlangParser::T__17:
        case TMSlangParser::T__20:
        case TMSlangParser::T__21:
        case TMSlangParser::COLON:
        case TMSlangParser::IF:
        case TMSlangParser::LEFTBRACE:
        case TMSlangParser::LET:
        case TMSlangParser::BoolLiteral:
        case TMSlangParser::ID:
        case TMSlangParser::TimePointLiteral:
        case TMSlangParser::DurationLiteral:
        case TMSlangParser::IntegerLiteral:
        case TMSlangParser::StringLiteral: {
          setState(14);
          execute_line();
          break;
        }

        case TMSlangParser::NEWLINE: {
          setState(15);
          match(TMSlangParser::NEWLINE);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(18); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TMSlangParser::T__2)
      | (1ULL << TMSlangParser::T__3)
      | (1ULL << TMSlangParser::T__17)
      | (1ULL << TMSlangParser::T__20)
      | (1ULL << TMSlangParser::T__21)
      | (1ULL << TMSlangParser::COLON)
      | (1ULL << TMSlangParser::IF)
      | (1ULL << TMSlangParser::LEFTBRACE)
      | (1ULL << TMSlangParser::LET)
      | (1ULL << TMSlangParser::BoolLiteral)
      | (1ULL << TMSlangParser::ID)
      | (1ULL << TMSlangParser::TimePointLiteral)
      | (1ULL << TMSlangParser::DurationLiteral)
      | (1ULL << TMSlangParser::IntegerLiteral)
      | (1ULL << TMSlangParser::StringLiteral)
      | (1ULL << TMSlangParser::NEWLINE))) != 0));
   
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
    setState(23);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(20);
      mgmt_command();
      break;
    }

    case 2: {
      setState(21);
      varDef();
      break;
    }

    case 3: {
      setState(22);
      triggerDef();
      break;
    }

    default:
      break;
    }
    setState(25);
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
    setState(27);
    match(TMSlangParser::COLON);
    setState(28);
    dynamic_cast<Mgmt_commandContext *>(_localctx)->command_name = cmd_arg();
    setState(32);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TMSlangParser::TEXTARG

    || _la == TMSlangParser::StringLiteral) {
      setState(29);
      dynamic_cast<Mgmt_commandContext *>(_localctx)->cmd_argContext = cmd_arg();
      dynamic_cast<Mgmt_commandContext *>(_localctx)->args.push_back(dynamic_cast<Mgmt_commandContext *>(_localctx)->cmd_argContext);
      setState(34);
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
    setState(37);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TMSlangParser::StringLiteral: {
        _localctx = dynamic_cast<Cmd_argContext *>(_tracker.createInstance<TMSlangParser::QuotedArgContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(35);
        match(TMSlangParser::StringLiteral);
        break;
      }

      case TMSlangParser::TEXTARG: {
        _localctx = dynamic_cast<Cmd_argContext *>(_tracker.createInstance<TMSlangParser::PlainArgContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(36);
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

tree::TerminalNode* TMSlangParser::GlobalVarDefContext::LET() {
  return getToken(TMSlangParser::LET, 0);
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

tree::TerminalNode* TMSlangParser::SessionVarDefContext::LET() {
  return getToken(TMSlangParser::LET, 0);
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
    setState(48);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<TMSlangParser::SessionVarDefContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(39);
      match(TMSlangParser::LET);
      setState(40);
      match(TMSlangParser::ID);
      setState(41);
      match(TMSlangParser::T__0);
      setState(42);
      expr(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<TMSlangParser::GlobalVarDefContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(43);
      match(TMSlangParser::LET);
      setState(44);
      match(TMSlangParser::GLOBAL);
      setState(45);
      match(TMSlangParser::ID);
      setState(46);
      match(TMSlangParser::T__0);
      setState(47);
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
    setState(50);
    dynamic_cast<TriggerDefContext *>(_localctx)->signal = expr(0);
    setState(53);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TMSlangParser::POUND) {
      setState(51);
      match(TMSlangParser::POUND);
      setState(52);
      dynamic_cast<TriggerDefContext *>(_localctx)->trigger_name = cmd_arg();
    }
    setState(55);
    match(TMSlangParser::RIGHTARROW);
    setState(56);
    dynamic_cast<TriggerDefContext *>(_localctx)->exprContext = expr(0);
    dynamic_cast<TriggerDefContext *>(_localctx)->action.push_back(dynamic_cast<TriggerDefContext *>(_localctx)->exprContext);
    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TMSlangParser::T__1) {
      setState(57);
      match(TMSlangParser::T__1);
      setState(58);
      dynamic_cast<TriggerDefContext *>(_localctx)->exprContext = expr(0);
      dynamic_cast<TriggerDefContext *>(_localctx)->action.push_back(dynamic_cast<TriggerDefContext *>(_localctx)->exprContext);
      setState(63);
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
//----------------- BoolExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::BoolExprContext::BoolLiteral() {
  return getToken(TMSlangParser::BoolLiteral, 0);
}

TMSlangParser::BoolExprContext::BoolExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::BoolExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitBoolExpr(this);
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

tree::TerminalNode* TMSlangParser::IfExprContext::IF() {
  return getToken(TMSlangParser::IF, 0);
}

std::vector<TMSlangParser::ExprContext *> TMSlangParser::IfExprContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::IfExprContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

tree::TerminalNode* TMSlangParser::IfExprContext::ELSE() {
  return getToken(TMSlangParser::ELSE, 0);
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
//----------------- LogicExprContext ------------------------------------------------------------------

std::vector<TMSlangParser::ExprContext *> TMSlangParser::LogicExprContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::LogicExprContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

TMSlangParser::LogicExprContext::LogicExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::LogicExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitLogicExpr(this);
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
//----------------- NegExprContext ------------------------------------------------------------------

TMSlangParser::ExprContext* TMSlangParser::NegExprContext::expr() {
  return getRuleContext<TMSlangParser::ExprContext>(0);
}

TMSlangParser::NegExprContext::NegExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::NegExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitNegExpr(this);
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

TMSlangParser::ExprContext* TMSlangParser::AssignExprContext::expr() {
  return getRuleContext<TMSlangParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> TMSlangParser::AssignExprContext::ID() {
  return getTokens(TMSlangParser::ID);
}

tree::TerminalNode* TMSlangParser::AssignExprContext::ID(size_t i) {
  return getToken(TMSlangParser::ID, i);
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
//----------------- ParanExprContext ------------------------------------------------------------------

TMSlangParser::ExprContext* TMSlangParser::ParanExprContext::expr() {
  return getRuleContext<TMSlangParser::ExprContext>(0);
}

TMSlangParser::ParanExprContext::ParanExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::ParanExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitParanExpr(this);
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

tree::TerminalNode* TMSlangParser::LocalVarDefExprContext::LET() {
  return getToken(TMSlangParser::LET, 0);
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
//----------------- NotExprContext ------------------------------------------------------------------

TMSlangParser::ExprContext* TMSlangParser::NotExprContext::expr() {
  return getRuleContext<TMSlangParser::ExprContext>(0);
}

TMSlangParser::NotExprContext::NotExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::NotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitNotExpr(this);
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
    setState(134);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<NegExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(65);
      match(TMSlangParser::T__2);
      setState(66);
      expr(23);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<NotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(67);
      match(TMSlangParser::T__3);
      setState(68);
      expr(22);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<LocalVarDefExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(69);
      match(TMSlangParser::LET);
      setState(70);
      match(TMSlangParser::ID);
      setState(71);
      match(TMSlangParser::T__0);
      setState(72);
      expr(16);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<AssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(73);
      dynamic_cast<AssignExprContext *>(_localctx)->idToken = match(TMSlangParser::ID);
      dynamic_cast<AssignExprContext *>(_localctx)->id.push_back(dynamic_cast<AssignExprContext *>(_localctx)->idToken);
      setState(80);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TMSlangParser::T__15) {
        setState(74);
        match(TMSlangParser::T__15);
        setState(75);
        dynamic_cast<AssignExprContext *>(_localctx)->idToken = match(TMSlangParser::ID);
        dynamic_cast<AssignExprContext *>(_localctx)->id.push_back(dynamic_cast<AssignExprContext *>(_localctx)->idToken);
        setState(78);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == TMSlangParser::T__15) {
          setState(76);
          match(TMSlangParser::T__15);
          setState(77);
          dynamic_cast<AssignExprContext *>(_localctx)->idToken = match(TMSlangParser::ID);
          dynamic_cast<AssignExprContext *>(_localctx)->id.push_back(dynamic_cast<AssignExprContext *>(_localctx)->idToken);
        }
      }
      setState(82);
      match(TMSlangParser::T__0);
      setState(83);
      expr(15);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(84);
      match(TMSlangParser::ID);
      setState(85);
      match(TMSlangParser::T__17);
      setState(94);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TMSlangParser::T__2)
        | (1ULL << TMSlangParser::T__3)
        | (1ULL << TMSlangParser::T__17)
        | (1ULL << TMSlangParser::T__20)
        | (1ULL << TMSlangParser::T__21)
        | (1ULL << TMSlangParser::IF)
        | (1ULL << TMSlangParser::LEFTBRACE)
        | (1ULL << TMSlangParser::LET)
        | (1ULL << TMSlangParser::BoolLiteral)
        | (1ULL << TMSlangParser::ID)
        | (1ULL << TMSlangParser::TimePointLiteral)
        | (1ULL << TMSlangParser::DurationLiteral)
        | (1ULL << TMSlangParser::IntegerLiteral)
        | (1ULL << TMSlangParser::StringLiteral))) != 0)) {
        setState(86);
        dynamic_cast<CallExprContext *>(_localctx)->exprContext = expr(0);
        dynamic_cast<CallExprContext *>(_localctx)->args.push_back(dynamic_cast<CallExprContext *>(_localctx)->exprContext);
        setState(91);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == TMSlangParser::T__18) {
          setState(87);
          match(TMSlangParser::T__18);
          setState(88);
          dynamic_cast<CallExprContext *>(_localctx)->exprContext = expr(0);
          dynamic_cast<CallExprContext *>(_localctx)->args.push_back(dynamic_cast<CallExprContext *>(_localctx)->exprContext);
          setState(93);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(96);
      match(TMSlangParser::T__19);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<GroupExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(97);
      match(TMSlangParser::LEFTBRACE);
      setState(106);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TMSlangParser::T__2)
        | (1ULL << TMSlangParser::T__3)
        | (1ULL << TMSlangParser::T__17)
        | (1ULL << TMSlangParser::T__20)
        | (1ULL << TMSlangParser::T__21)
        | (1ULL << TMSlangParser::IF)
        | (1ULL << TMSlangParser::LEFTBRACE)
        | (1ULL << TMSlangParser::LET)
        | (1ULL << TMSlangParser::BoolLiteral)
        | (1ULL << TMSlangParser::ID)
        | (1ULL << TMSlangParser::TimePointLiteral)
        | (1ULL << TMSlangParser::DurationLiteral)
        | (1ULL << TMSlangParser::IntegerLiteral)
        | (1ULL << TMSlangParser::StringLiteral))) != 0)) {
        setState(98);
        dynamic_cast<GroupExprContext *>(_localctx)->exprContext = expr(0);
        dynamic_cast<GroupExprContext *>(_localctx)->inner.push_back(dynamic_cast<GroupExprContext *>(_localctx)->exprContext);
        setState(103);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(99);
            match(TMSlangParser::T__1);
            setState(100);
            dynamic_cast<GroupExprContext *>(_localctx)->exprContext = expr(0);
            dynamic_cast<GroupExprContext *>(_localctx)->inner.push_back(dynamic_cast<GroupExprContext *>(_localctx)->exprContext); 
          }
          setState(105);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
        }
      }
      setState(109);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TMSlangParser::T__1) {
        setState(108);
        match(TMSlangParser::T__1);
      }
      setState(111);
      match(TMSlangParser::RIGHTBRACE);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<IDExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(112);
      match(TMSlangParser::ID);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<LaterExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(113);
      match(TMSlangParser::T__20);
      setState(114);
      expr(9);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<CurrentExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(115);
      match(TMSlangParser::T__21);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<ParanExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(116);
      match(TMSlangParser::T__17);
      setState(117);
      expr(0);
      setState(118);
      match(TMSlangParser::T__19);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<IfExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(120);
      match(TMSlangParser::IF);
      setState(121);
      match(TMSlangParser::T__17);
      setState(122);
      dynamic_cast<IfExprContext *>(_localctx)->cond = expr(0);
      setState(123);
      match(TMSlangParser::T__19);
      setState(124);
      dynamic_cast<IfExprContext *>(_localctx)->then = expr(0);
      setState(127);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
      case 1: {
        setState(125);
        match(TMSlangParser::ELSE);
        setState(126);
        dynamic_cast<IfExprContext *>(_localctx)->epart = expr(0);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<TimePointLExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(129);
      match(TMSlangParser::TimePointLiteral);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<DurationLExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(130);
      match(TMSlangParser::DurationLiteral);
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<StringLExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(131);
      match(TMSlangParser::StringLiteral);
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<IntLExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(132);
      match(TMSlangParser::IntegerLiteral);
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<BoolExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(133);
      match(TMSlangParser::BoolLiteral);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(163);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(161);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(136);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(137);
          dynamic_cast<MulExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == TMSlangParser::T__4

          || _la == TMSlangParser::T__5)) {
            dynamic_cast<MulExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(138);
          expr(22);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(139);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(140);
          dynamic_cast<AddExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == TMSlangParser::T__2

          || _la == TMSlangParser::T__6)) {
            dynamic_cast<AddExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(141);
          expr(21);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(142);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(143);
          dynamic_cast<RelExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << TMSlangParser::T__7)
            | (1ULL << TMSlangParser::T__8)
            | (1ULL << TMSlangParser::T__9)
            | (1ULL << TMSlangParser::T__10))) != 0))) {
            dynamic_cast<RelExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(144);
          expr(20);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EqlExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(145);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(146);
          dynamic_cast<EqlExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == TMSlangParser::T__11

          || _la == TMSlangParser::T__12)) {
            dynamic_cast<EqlExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(147);
          expr(19);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<LogicExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(148);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(149);
          dynamic_cast<LogicExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == TMSlangParser::T__13

          || _la == TMSlangParser::T__14)) {
            dynamic_cast<LogicExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(150);
          dynamic_cast<LogicExprContext *>(_localctx)->rhs = expr(18);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<PeriodicExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(151);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(152);
          match(TMSlangParser::T__16);
          setState(153);
          expr(0);
          setState(156);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
          case 1: {
            setState(154);
            match(TMSlangParser::T__16);
            setState(155);
            dynamic_cast<PeriodicExprContext *>(_localctx)->end = expr(0);
            break;
          }

          default:
            break;
          }
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<FieldExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(158);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(159);
          match(TMSlangParser::T__15);
          setState(160);
          match(TMSlangParser::ID);
          break;
        }

        default:
          break;
        } 
      }
      setState(165);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
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
    case 0: return precpred(_ctx, 21);
    case 1: return precpred(_ctx, 20);
    case 2: return precpred(_ctx, 19);
    case 3: return precpred(_ctx, 18);
    case 4: return precpred(_ctx, 17);
    case 5: return precpred(_ctx, 14);
    case 6: return precpred(_ctx, 13);

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
  "", "'='", "';'", "'-'", "'!'", "'*'", "'/'", "'+'", "'<'", "'>'", "'<='", 
  "'>='", "'=='", "'!='", "'||'", "'&&'", "'.'", "'@'", "'('", "','", "')'", 
  "'>>'", "'<.>'", "':'", "", "'if'", "'else'", "'#'", "'{'", "'}'", "", 
  "'let'", "'session'", "'global'"
};

std::vector<std::string> TMSlangParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "COLON", "TEXTARG", "IF", "ELSE", "POUND", "LEFTBRACE", 
  "RIGHTBRACE", "RIGHTARROW", "LET", "SESSION", "GLOBAL", "BoolLiteral", 
  "ID", "TimePointLiteral", "DurationLiteral", "DurationFragment", "IntegerLiteral", 
  "StringLiteral", "WS", "ESCAPEDNEWLINE", "NEWLINE_SKIP", "NEWLINE", "ERRORCHAR"
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
       0x3, 0x2f, 0xa9, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 0x13, 0xa, 
       0x2, 0xd, 0x2, 0xe, 0x2, 0x14, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
       0x3, 0x1a, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x7, 0x4, 0x21, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x24, 0xb, 0x4, 
       0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x28, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
       0x6, 0x5, 0x6, 0x33, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 
       0x7, 0x38, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 
       0x7, 0x3e, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x41, 0xb, 0x7, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x5, 0x8, 0x51, 0xa, 0x8, 0x5, 0x8, 0x53, 0xa, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 
       0x5c, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x5f, 0xb, 0x8, 0x5, 0x8, 0x61, 
       0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 
       0x8, 0x68, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x6b, 0xb, 0x8, 0x5, 0x8, 
       0x6d, 0xa, 0x8, 0x3, 0x8, 0x5, 0x8, 0x70, 0xa, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x5, 0x8, 0x82, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x89, 0xa, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 
       0x9f, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0xa4, 0xa, 
       0x8, 0xc, 0x8, 0xe, 0x8, 0xa7, 0xb, 0x8, 0x3, 0x8, 0x2, 0x3, 0xe, 
       0x9, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x2, 0x7, 0x3, 0x2, 0x7, 
       0x8, 0x4, 0x2, 0x5, 0x5, 0x9, 0x9, 0x3, 0x2, 0xa, 0xd, 0x3, 0x2, 
       0xe, 0xf, 0x3, 0x2, 0x10, 0x11, 0x2, 0xc9, 0x2, 0x12, 0x3, 0x2, 0x2, 
       0x2, 0x4, 0x19, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1d, 0x3, 0x2, 0x2, 0x2, 
       0x8, 0x27, 0x3, 0x2, 0x2, 0x2, 0xa, 0x32, 0x3, 0x2, 0x2, 0x2, 0xc, 
       0x34, 0x3, 0x2, 0x2, 0x2, 0xe, 0x88, 0x3, 0x2, 0x2, 0x2, 0x10, 0x13, 
       0x5, 0x4, 0x3, 0x2, 0x11, 0x13, 0x7, 0x2e, 0x2, 0x2, 0x12, 0x10, 
       0x3, 0x2, 0x2, 0x2, 0x12, 0x11, 0x3, 0x2, 0x2, 0x2, 0x13, 0x14, 0x3, 
       0x2, 0x2, 0x2, 0x14, 0x12, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x3, 0x2, 
       0x2, 0x2, 0x15, 0x3, 0x3, 0x2, 0x2, 0x2, 0x16, 0x1a, 0x5, 0x6, 0x4, 
       0x2, 0x17, 0x1a, 0x5, 0xa, 0x6, 0x2, 0x18, 0x1a, 0x5, 0xc, 0x7, 0x2, 
       0x19, 0x16, 0x3, 0x2, 0x2, 0x2, 0x19, 0x17, 0x3, 0x2, 0x2, 0x2, 0x19, 
       0x18, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 
       0x7, 0x2e, 0x2, 0x2, 0x1c, 0x5, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x7, 
       0x19, 0x2, 0x2, 0x1e, 0x22, 0x5, 0x8, 0x5, 0x2, 0x1f, 0x21, 0x5, 
       0x8, 0x5, 0x2, 0x20, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 0x24, 0x3, 0x2, 
       0x2, 0x2, 0x22, 0x20, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x3, 0x2, 0x2, 
       0x2, 0x23, 0x7, 0x3, 0x2, 0x2, 0x2, 0x24, 0x22, 0x3, 0x2, 0x2, 0x2, 
       0x25, 0x28, 0x7, 0x2a, 0x2, 0x2, 0x26, 0x28, 0x7, 0x1a, 0x2, 0x2, 
       0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x27, 0x26, 0x3, 0x2, 0x2, 0x2, 0x28, 
       0x9, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x7, 0x21, 0x2, 0x2, 0x2a, 0x2b, 
       0x7, 0x25, 0x2, 0x2, 0x2b, 0x2c, 0x7, 0x3, 0x2, 0x2, 0x2c, 0x33, 
       0x5, 0xe, 0x8, 0x2, 0x2d, 0x2e, 0x7, 0x21, 0x2, 0x2, 0x2e, 0x2f, 
       0x7, 0x23, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x25, 0x2, 0x2, 0x30, 0x31, 
       0x7, 0x3, 0x2, 0x2, 0x31, 0x33, 0x5, 0xe, 0x8, 0x2, 0x32, 0x29, 0x3, 
       0x2, 0x2, 0x2, 0x32, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x33, 0xb, 0x3, 0x2, 
       0x2, 0x2, 0x34, 0x37, 0x5, 0xe, 0x8, 0x2, 0x35, 0x36, 0x7, 0x1d, 
       0x2, 0x2, 0x36, 0x38, 0x5, 0x8, 0x5, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 
       0x2, 0x37, 0x38, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x3, 0x2, 0x2, 0x2, 
       0x39, 0x3a, 0x7, 0x20, 0x2, 0x2, 0x3a, 0x3f, 0x5, 0xe, 0x8, 0x2, 
       0x3b, 0x3c, 0x7, 0x4, 0x2, 0x2, 0x3c, 0x3e, 0x5, 0xe, 0x8, 0x2, 0x3d, 
       0x3b, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x41, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3d, 
       0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 0x2, 0x40, 0xd, 0x3, 
       0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x8, 0x8, 
       0x1, 0x2, 0x43, 0x44, 0x7, 0x5, 0x2, 0x2, 0x44, 0x89, 0x5, 0xe, 0x8, 
       0x19, 0x45, 0x46, 0x7, 0x6, 0x2, 0x2, 0x46, 0x89, 0x5, 0xe, 0x8, 
       0x18, 0x47, 0x48, 0x7, 0x21, 0x2, 0x2, 0x48, 0x49, 0x7, 0x25, 0x2, 
       0x2, 0x49, 0x4a, 0x7, 0x3, 0x2, 0x2, 0x4a, 0x89, 0x5, 0xe, 0x8, 0x12, 
       0x4b, 0x52, 0x7, 0x25, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0x12, 0x2, 0x2, 
       0x4d, 0x50, 0x7, 0x25, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x12, 0x2, 0x2, 
       0x4f, 0x51, 0x7, 0x25, 0x2, 0x2, 0x50, 0x4e, 0x3, 0x2, 0x2, 0x2, 
       0x50, 0x51, 0x3, 0x2, 0x2, 0x2, 0x51, 0x53, 0x3, 0x2, 0x2, 0x2, 0x52, 
       0x4c, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 
       0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x7, 0x3, 0x2, 0x2, 0x55, 0x89, 0x5, 
       0xe, 0x8, 0x11, 0x56, 0x57, 0x7, 0x25, 0x2, 0x2, 0x57, 0x60, 0x7, 
       0x14, 0x2, 0x2, 0x58, 0x5d, 0x5, 0xe, 0x8, 0x2, 0x59, 0x5a, 0x7, 
       0x15, 0x2, 0x2, 0x5a, 0x5c, 0x5, 0xe, 0x8, 0x2, 0x5b, 0x59, 0x3, 
       0x2, 0x2, 0x2, 0x5c, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 
       0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x61, 0x3, 0x2, 0x2, 
       0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x60, 0x58, 0x3, 0x2, 0x2, 0x2, 
       0x60, 0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x3, 0x2, 0x2, 0x2, 0x62, 
       0x89, 0x7, 0x16, 0x2, 0x2, 0x63, 0x6c, 0x7, 0x1e, 0x2, 0x2, 0x64, 
       0x69, 0x5, 0xe, 0x8, 0x2, 0x65, 0x66, 0x7, 0x4, 0x2, 0x2, 0x66, 0x68, 
       0x5, 0xe, 0x8, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6b, 0x3, 
       0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 
       0x2, 0x2, 0x6a, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 
       0x2, 0x6c, 0x64, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 
       0x6d, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x70, 0x7, 0x4, 0x2, 0x2, 0x6f, 
       0x6e, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 
       0x3, 0x2, 0x2, 0x2, 0x71, 0x89, 0x7, 0x1f, 0x2, 0x2, 0x72, 0x89, 
       0x7, 0x25, 0x2, 0x2, 0x73, 0x74, 0x7, 0x17, 0x2, 0x2, 0x74, 0x89, 
       0x5, 0xe, 0x8, 0xb, 0x75, 0x89, 0x7, 0x18, 0x2, 0x2, 0x76, 0x77, 
       0x7, 0x14, 0x2, 0x2, 0x77, 0x78, 0x5, 0xe, 0x8, 0x2, 0x78, 0x79, 
       0x7, 0x16, 0x2, 0x2, 0x79, 0x89, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 
       0x7, 0x1b, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x14, 0x2, 0x2, 0x7c, 0x7d, 
       0x5, 0xe, 0x8, 0x2, 0x7d, 0x7e, 0x7, 0x16, 0x2, 0x2, 0x7e, 0x81, 
       0x5, 0xe, 0x8, 0x2, 0x7f, 0x80, 0x7, 0x1c, 0x2, 0x2, 0x80, 0x82, 
       0x5, 0xe, 0x8, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 
       0x2, 0x2, 0x2, 0x82, 0x89, 0x3, 0x2, 0x2, 0x2, 0x83, 0x89, 0x7, 0x26, 
       0x2, 0x2, 0x84, 0x89, 0x7, 0x27, 0x2, 0x2, 0x85, 0x89, 0x7, 0x2a, 
       0x2, 0x2, 0x86, 0x89, 0x7, 0x29, 0x2, 0x2, 0x87, 0x89, 0x7, 0x24, 
       0x2, 0x2, 0x88, 0x42, 0x3, 0x2, 0x2, 0x2, 0x88, 0x45, 0x3, 0x2, 0x2, 
       0x2, 0x88, 0x47, 0x3, 0x2, 0x2, 0x2, 0x88, 0x4b, 0x3, 0x2, 0x2, 0x2, 
       0x88, 0x56, 0x3, 0x2, 0x2, 0x2, 0x88, 0x63, 0x3, 0x2, 0x2, 0x2, 0x88, 
       0x72, 0x3, 0x2, 0x2, 0x2, 0x88, 0x73, 0x3, 0x2, 0x2, 0x2, 0x88, 0x75, 
       0x3, 0x2, 0x2, 0x2, 0x88, 0x76, 0x3, 0x2, 0x2, 0x2, 0x88, 0x7a, 0x3, 
       0x2, 0x2, 0x2, 0x88, 0x83, 0x3, 0x2, 0x2, 0x2, 0x88, 0x84, 0x3, 0x2, 
       0x2, 0x2, 0x88, 0x85, 0x3, 0x2, 0x2, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 
       0x2, 0x88, 0x87, 0x3, 0x2, 0x2, 0x2, 0x89, 0xa5, 0x3, 0x2, 0x2, 0x2, 
       0x8a, 0x8b, 0xc, 0x17, 0x2, 0x2, 0x8b, 0x8c, 0x9, 0x2, 0x2, 0x2, 
       0x8c, 0xa4, 0x5, 0xe, 0x8, 0x18, 0x8d, 0x8e, 0xc, 0x16, 0x2, 0x2, 
       0x8e, 0x8f, 0x9, 0x3, 0x2, 0x2, 0x8f, 0xa4, 0x5, 0xe, 0x8, 0x17, 
       0x90, 0x91, 0xc, 0x15, 0x2, 0x2, 0x91, 0x92, 0x9, 0x4, 0x2, 0x2, 
       0x92, 0xa4, 0x5, 0xe, 0x8, 0x16, 0x93, 0x94, 0xc, 0x14, 0x2, 0x2, 
       0x94, 0x95, 0x9, 0x5, 0x2, 0x2, 0x95, 0xa4, 0x5, 0xe, 0x8, 0x15, 
       0x96, 0x97, 0xc, 0x13, 0x2, 0x2, 0x97, 0x98, 0x9, 0x6, 0x2, 0x2, 
       0x98, 0xa4, 0x5, 0xe, 0x8, 0x14, 0x99, 0x9a, 0xc, 0x10, 0x2, 0x2, 
       0x9a, 0x9b, 0x7, 0x13, 0x2, 0x2, 0x9b, 0x9e, 0x5, 0xe, 0x8, 0x2, 
       0x9c, 0x9d, 0x7, 0x13, 0x2, 0x2, 0x9d, 0x9f, 0x5, 0xe, 0x8, 0x2, 
       0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 
       0xa4, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0xc, 0xf, 0x2, 0x2, 0xa1, 0xa2, 
       0x7, 0x12, 0x2, 0x2, 0xa2, 0xa4, 0x7, 0x25, 0x2, 0x2, 0xa3, 0x8a, 
       0x3, 0x2, 0x2, 0x2, 0xa3, 0x8d, 0x3, 0x2, 0x2, 0x2, 0xa3, 0x90, 0x3, 
       0x2, 0x2, 0x2, 0xa3, 0x93, 0x3, 0x2, 0x2, 0x2, 0xa3, 0x96, 0x3, 0x2, 
       0x2, 0x2, 0xa3, 0x99, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa0, 0x3, 0x2, 0x2, 
       0x2, 0xa4, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 
       0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xf, 0x3, 0x2, 0x2, 0x2, 0xa7, 
       0xa5, 0x3, 0x2, 0x2, 0x2, 0x16, 0x12, 0x14, 0x19, 0x22, 0x27, 0x32, 
       0x37, 0x3f, 0x50, 0x52, 0x5d, 0x60, 0x69, 0x6c, 0x6f, 0x81, 0x88, 
       0x9e, 0xa3, 0xa5, 
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
