
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

TMSlangParser::ClassDefContext* TMSlangParser::ProgramContext::classDef() {
  return getRuleContext<TMSlangParser::ClassDefContext>(0);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(18);
    dynamic_cast<ProgramContext *>(_localctx)->classDefContext = classDef();
    dynamic_cast<ProgramContext *>(_localctx)->classes.push_back(dynamic_cast<ProgramContext *>(_localctx)->classDefContext);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDefContext ------------------------------------------------------------------

TMSlangParser::ClassDefContext::ClassDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TMSlangParser::ClassDefContext::CLASS() {
  return getToken(TMSlangParser::CLASS, 0);
}

TMSlangParser::ClassBodyContext* TMSlangParser::ClassDefContext::classBody() {
  return getRuleContext<TMSlangParser::ClassBodyContext>(0);
}

std::vector<tree::TerminalNode *> TMSlangParser::ClassDefContext::TYPE() {
  return getTokens(TMSlangParser::TYPE);
}

tree::TerminalNode* TMSlangParser::ClassDefContext::TYPE(size_t i) {
  return getToken(TMSlangParser::TYPE, i);
}

tree::TerminalNode* TMSlangParser::ClassDefContext::INHERITS() {
  return getToken(TMSlangParser::INHERITS, 0);
}


size_t TMSlangParser::ClassDefContext::getRuleIndex() const {
  return TMSlangParser::RuleClassDef;
}


antlrcpp::Any TMSlangParser::ClassDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitClassDef(this);
  else
    return visitor->visitChildren(this);
}

TMSlangParser::ClassDefContext* TMSlangParser::classDef() {
  ClassDefContext *_localctx = _tracker.createInstance<ClassDefContext>(_ctx, getState());
  enterRule(_localctx, 2, TMSlangParser::RuleClassDef);
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
    setState(20);
    match(TMSlangParser::CLASS);
    setState(21);
    dynamic_cast<ClassDefContext *>(_localctx)->className = match(TMSlangParser::TYPE);
    setState(24);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TMSlangParser::INHERITS) {
      setState(22);
      match(TMSlangParser::INHERITS);
      setState(23);
      dynamic_cast<ClassDefContext *>(_localctx)->inherits = match(TMSlangParser::TYPE);
    }
    setState(26);
    classBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassBodyContext ------------------------------------------------------------------

TMSlangParser::ClassBodyContext::ClassBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TMSlangParser::ClassBodyContext::LBRACE() {
  return getToken(TMSlangParser::LBRACE, 0);
}

tree::TerminalNode* TMSlangParser::ClassBodyContext::RBRACE() {
  return getToken(TMSlangParser::RBRACE, 0);
}

std::vector<TMSlangParser::VariableDeclContext *> TMSlangParser::ClassBodyContext::variableDecl() {
  return getRuleContexts<TMSlangParser::VariableDeclContext>();
}

TMSlangParser::VariableDeclContext* TMSlangParser::ClassBodyContext::variableDecl(size_t i) {
  return getRuleContext<TMSlangParser::VariableDeclContext>(i);
}

std::vector<TMSlangParser::MethodContext *> TMSlangParser::ClassBodyContext::method() {
  return getRuleContexts<TMSlangParser::MethodContext>();
}

TMSlangParser::MethodContext* TMSlangParser::ClassBodyContext::method(size_t i) {
  return getRuleContext<TMSlangParser::MethodContext>(i);
}


size_t TMSlangParser::ClassBodyContext::getRuleIndex() const {
  return TMSlangParser::RuleClassBody;
}


antlrcpp::Any TMSlangParser::ClassBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitClassBody(this);
  else
    return visitor->visitChildren(this);
}

TMSlangParser::ClassBodyContext* TMSlangParser::classBody() {
  ClassBodyContext *_localctx = _tracker.createInstance<ClassBodyContext>(_ctx, getState());
  enterRule(_localctx, 4, TMSlangParser::RuleClassBody);
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
    setState(28);
    match(TMSlangParser::LBRACE);
    setState(35);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TMSlangParser::ID) {
      setState(31);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
      case 1: {
        setState(29);
        dynamic_cast<ClassBodyContext *>(_localctx)->variableDeclContext = variableDecl();
        dynamic_cast<ClassBodyContext *>(_localctx)->variables.push_back(dynamic_cast<ClassBodyContext *>(_localctx)->variableDeclContext);
        break;
      }

      case 2: {
        setState(30);
        dynamic_cast<ClassBodyContext *>(_localctx)->methodContext = method();
        dynamic_cast<ClassBodyContext *>(_localctx)->methods.push_back(dynamic_cast<ClassBodyContext *>(_localctx)->methodContext);
        break;
      }

      default:
        break;
      }
      setState(37);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(38);
    match(TMSlangParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodContext ------------------------------------------------------------------

TMSlangParser::MethodContext::MethodContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TMSlangParser::MethodContext::ID() {
  return getToken(TMSlangParser::ID, 0);
}

tree::TerminalNode* TMSlangParser::MethodContext::LPAR() {
  return getToken(TMSlangParser::LPAR, 0);
}

tree::TerminalNode* TMSlangParser::MethodContext::RPAR() {
  return getToken(TMSlangParser::RPAR, 0);
}

tree::TerminalNode* TMSlangParser::MethodContext::COLON() {
  return getToken(TMSlangParser::COLON, 0);
}

tree::TerminalNode* TMSlangParser::MethodContext::LBRACE() {
  return getToken(TMSlangParser::LBRACE, 0);
}

TMSlangParser::ExprContext* TMSlangParser::MethodContext::expr() {
  return getRuleContext<TMSlangParser::ExprContext>(0);
}

tree::TerminalNode* TMSlangParser::MethodContext::RBRACE() {
  return getToken(TMSlangParser::RBRACE, 0);
}

TMSlangParser::TypeNameContext* TMSlangParser::MethodContext::typeName() {
  return getRuleContext<TMSlangParser::TypeNameContext>(0);
}

std::vector<TMSlangParser::FormalContext *> TMSlangParser::MethodContext::formal() {
  return getRuleContexts<TMSlangParser::FormalContext>();
}

TMSlangParser::FormalContext* TMSlangParser::MethodContext::formal(size_t i) {
  return getRuleContext<TMSlangParser::FormalContext>(i);
}

std::vector<TMSlangParser::VariableDeclContext *> TMSlangParser::MethodContext::variableDecl() {
  return getRuleContexts<TMSlangParser::VariableDeclContext>();
}

TMSlangParser::VariableDeclContext* TMSlangParser::MethodContext::variableDecl(size_t i) {
  return getRuleContext<TMSlangParser::VariableDeclContext>(i);
}

std::vector<tree::TerminalNode *> TMSlangParser::MethodContext::COMMA() {
  return getTokens(TMSlangParser::COMMA);
}

tree::TerminalNode* TMSlangParser::MethodContext::COMMA(size_t i) {
  return getToken(TMSlangParser::COMMA, i);
}


size_t TMSlangParser::MethodContext::getRuleIndex() const {
  return TMSlangParser::RuleMethod;
}


antlrcpp::Any TMSlangParser::MethodContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitMethod(this);
  else
    return visitor->visitChildren(this);
}

TMSlangParser::MethodContext* TMSlangParser::method() {
  MethodContext *_localctx = _tracker.createInstance<MethodContext>(_ctx, getState());
  enterRule(_localctx, 6, TMSlangParser::RuleMethod);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(40);
    match(TMSlangParser::ID);
    setState(41);
    match(TMSlangParser::LPAR);
    setState(50);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TMSlangParser::ID) {
      setState(42);
      dynamic_cast<MethodContext *>(_localctx)->formalContext = formal();
      dynamic_cast<MethodContext *>(_localctx)->formals.push_back(dynamic_cast<MethodContext *>(_localctx)->formalContext);
      setState(47);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TMSlangParser::COMMA) {
        setState(43);
        match(TMSlangParser::COMMA);
        setState(44);
        dynamic_cast<MethodContext *>(_localctx)->formalContext = formal();
        dynamic_cast<MethodContext *>(_localctx)->formals.push_back(dynamic_cast<MethodContext *>(_localctx)->formalContext);
        setState(49);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(52);
    match(TMSlangParser::RPAR);
    setState(53);
    match(TMSlangParser::COLON);
    setState(54);
    dynamic_cast<MethodContext *>(_localctx)->type = typeName();
    setState(55);
    match(TMSlangParser::LBRACE);
    setState(59);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(56);
        dynamic_cast<MethodContext *>(_localctx)->variableDeclContext = variableDecl();
        dynamic_cast<MethodContext *>(_localctx)->vars.push_back(dynamic_cast<MethodContext *>(_localctx)->variableDeclContext); 
      }
      setState(61);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
    setState(62);
    expr(0);
    setState(63);
    match(TMSlangParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclContext ------------------------------------------------------------------

TMSlangParser::VariableDeclContext::VariableDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TMSlangParser::VariableDeclContext::ID() {
  return getToken(TMSlangParser::ID, 0);
}

tree::TerminalNode* TMSlangParser::VariableDeclContext::COLON() {
  return getToken(TMSlangParser::COLON, 0);
}

tree::TerminalNode* TMSlangParser::VariableDeclContext::SEMICOLON() {
  return getToken(TMSlangParser::SEMICOLON, 0);
}

TMSlangParser::TypeNameContext* TMSlangParser::VariableDeclContext::typeName() {
  return getRuleContext<TMSlangParser::TypeNameContext>(0);
}

tree::TerminalNode* TMSlangParser::VariableDeclContext::LESSDASH() {
  return getToken(TMSlangParser::LESSDASH, 0);
}

TMSlangParser::ExprContext* TMSlangParser::VariableDeclContext::expr() {
  return getRuleContext<TMSlangParser::ExprContext>(0);
}


size_t TMSlangParser::VariableDeclContext::getRuleIndex() const {
  return TMSlangParser::RuleVariableDecl;
}


antlrcpp::Any TMSlangParser::VariableDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitVariableDecl(this);
  else
    return visitor->visitChildren(this);
}

TMSlangParser::VariableDeclContext* TMSlangParser::variableDecl() {
  VariableDeclContext *_localctx = _tracker.createInstance<VariableDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, TMSlangParser::RuleVariableDecl);
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
    setState(65);
    match(TMSlangParser::ID);
    setState(66);
    match(TMSlangParser::COLON);
    setState(67);
    dynamic_cast<VariableDeclContext *>(_localctx)->type = typeName();
    setState(70);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TMSlangParser::LESSDASH) {
      setState(68);
      match(TMSlangParser::LESSDASH);
      setState(69);
      dynamic_cast<VariableDeclContext *>(_localctx)->initializer = expr(0);
    }
    setState(72);
    match(TMSlangParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalContext ------------------------------------------------------------------

TMSlangParser::FormalContext::FormalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TMSlangParser::FormalContext::COLON() {
  return getToken(TMSlangParser::COLON, 0);
}

tree::TerminalNode* TMSlangParser::FormalContext::ID() {
  return getToken(TMSlangParser::ID, 0);
}

TMSlangParser::TypeNameContext* TMSlangParser::FormalContext::typeName() {
  return getRuleContext<TMSlangParser::TypeNameContext>(0);
}


size_t TMSlangParser::FormalContext::getRuleIndex() const {
  return TMSlangParser::RuleFormal;
}


antlrcpp::Any TMSlangParser::FormalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitFormal(this);
  else
    return visitor->visitChildren(this);
}

TMSlangParser::FormalContext* TMSlangParser::formal() {
  FormalContext *_localctx = _tracker.createInstance<FormalContext>(_ctx, getState());
  enterRule(_localctx, 10, TMSlangParser::RuleFormal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    dynamic_cast<FormalContext *>(_localctx)->name = match(TMSlangParser::ID);
    setState(75);
    match(TMSlangParser::COLON);
    setState(76);
    dynamic_cast<FormalContext *>(_localctx)->type = typeName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

TMSlangParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TMSlangParser::TypeNameContext::TYPE() {
  return getToken(TMSlangParser::TYPE, 0);
}

tree::TerminalNode* TMSlangParser::TypeNameContext::INT() {
  return getToken(TMSlangParser::INT, 0);
}

tree::TerminalNode* TMSlangParser::TypeNameContext::BOOL() {
  return getToken(TMSlangParser::BOOL, 0);
}


size_t TMSlangParser::TypeNameContext::getRuleIndex() const {
  return TMSlangParser::RuleTypeName;
}


antlrcpp::Any TMSlangParser::TypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitTypeName(this);
  else
    return visitor->visitChildren(this);
}

TMSlangParser::TypeNameContext* TMSlangParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 12, TMSlangParser::RuleTypeName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(81);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TMSlangParser::TYPE: {
        enterOuterAlt(_localctx, 1);
        setState(78);
        dynamic_cast<TypeNameContext *>(_localctx)->classType = match(TMSlangParser::TYPE);
        break;
      }

      case TMSlangParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(79);
        dynamic_cast<TypeNameContext *>(_localctx)->intType = match(TMSlangParser::INT);
        break;
      }

      case TMSlangParser::BOOL: {
        enterOuterAlt(_localctx, 3);
        setState(80);
        dynamic_cast<TypeNameContext *>(_localctx)->boolType = match(TMSlangParser::BOOL);
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

//----------------- WhileExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::WhileExprContext::WHILE() {
  return getToken(TMSlangParser::WHILE, 0);
}

tree::TerminalNode* TMSlangParser::WhileExprContext::LOOP() {
  return getToken(TMSlangParser::LOOP, 0);
}

tree::TerminalNode* TMSlangParser::WhileExprContext::POOL() {
  return getToken(TMSlangParser::POOL, 0);
}

std::vector<TMSlangParser::ExprContext *> TMSlangParser::WhileExprContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::WhileExprContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

TMSlangParser::WhileExprContext::WhileExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::WhileExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitWhileExpr(this);
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
//----------------- IfExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::IfExprContext::IF() {
  return getToken(TMSlangParser::IF, 0);
}

tree::TerminalNode* TMSlangParser::IfExprContext::THEN() {
  return getToken(TMSlangParser::THEN, 0);
}

tree::TerminalNode* TMSlangParser::IfExprContext::ELSE() {
  return getToken(TMSlangParser::ELSE, 0);
}

tree::TerminalNode* TMSlangParser::IfExprContext::FI() {
  return getToken(TMSlangParser::FI, 0);
}

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
//----------------- TrueExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::TrueExprContext::TRUE() {
  return getToken(TMSlangParser::TRUE, 0);
}

TMSlangParser::TrueExprContext::TrueExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::TrueExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitTrueExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IsNullExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::IsNullExprContext::ISNULL() {
  return getToken(TMSlangParser::ISNULL, 0);
}

TMSlangParser::ExprContext* TMSlangParser::IsNullExprContext::expr() {
  return getRuleContext<TMSlangParser::ExprContext>(0);
}

TMSlangParser::IsNullExprContext::IsNullExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::IsNullExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitIsNullExpr(this);
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

tree::TerminalNode* TMSlangParser::RelExprContext::LESS() {
  return getToken(TMSlangParser::LESS, 0);
}

tree::TerminalNode* TMSlangParser::RelExprContext::LEQ() {
  return getToken(TMSlangParser::LEQ, 0);
}

tree::TerminalNode* TMSlangParser::RelExprContext::GTR() {
  return getToken(TMSlangParser::GTR, 0);
}

tree::TerminalNode* TMSlangParser::RelExprContext::GEQ() {
  return getToken(TMSlangParser::GEQ, 0);
}

TMSlangParser::RelExprContext::RelExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::RelExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitRelExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultExprContext ------------------------------------------------------------------

std::vector<TMSlangParser::ExprContext *> TMSlangParser::MultExprContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::MultExprContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

tree::TerminalNode* TMSlangParser::MultExprContext::STAR() {
  return getToken(TMSlangParser::STAR, 0);
}

tree::TerminalNode* TMSlangParser::MultExprContext::SLASH() {
  return getToken(TMSlangParser::SLASH, 0);
}

TMSlangParser::MultExprContext::MultExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::MultExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitMultExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FullMethodCallContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::FullMethodCallContext::DOT() {
  return getToken(TMSlangParser::DOT, 0);
}

tree::TerminalNode* TMSlangParser::FullMethodCallContext::LPAR() {
  return getToken(TMSlangParser::LPAR, 0);
}

tree::TerminalNode* TMSlangParser::FullMethodCallContext::RPAR() {
  return getToken(TMSlangParser::RPAR, 0);
}

std::vector<TMSlangParser::ExprContext *> TMSlangParser::FullMethodCallContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::FullMethodCallContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

tree::TerminalNode* TMSlangParser::FullMethodCallContext::ID() {
  return getToken(TMSlangParser::ID, 0);
}

std::vector<tree::TerminalNode *> TMSlangParser::FullMethodCallContext::COMMA() {
  return getTokens(TMSlangParser::COMMA);
}

tree::TerminalNode* TMSlangParser::FullMethodCallContext::COMMA(size_t i) {
  return getToken(TMSlangParser::COMMA, i);
}

TMSlangParser::FullMethodCallContext::FullMethodCallContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::FullMethodCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitFullMethodCall(this);
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

tree::TerminalNode* TMSlangParser::AddExprContext::PLUS() {
  return getToken(TMSlangParser::PLUS, 0);
}

tree::TerminalNode* TMSlangParser::AddExprContext::MINUS() {
  return getToken(TMSlangParser::MINUS, 0);
}

TMSlangParser::AddExprContext::AddExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::AddExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitAddExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UMinusExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::UMinusExprContext::MINUS() {
  return getToken(TMSlangParser::MINUS, 0);
}

TMSlangParser::ExprContext* TMSlangParser::UMinusExprContext::expr() {
  return getRuleContext<TMSlangParser::ExprContext>(0);
}

TMSlangParser::UMinusExprContext::UMinusExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::UMinusExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitUMinusExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::AssignExprContext::ID() {
  return getToken(TMSlangParser::ID, 0);
}

tree::TerminalNode* TMSlangParser::AssignExprContext::LESSDASH() {
  return getToken(TMSlangParser::LESSDASH, 0);
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
//----------------- FalseExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::FalseExprContext::FALSE() {
  return getToken(TMSlangParser::FALSE, 0);
}

TMSlangParser::FalseExprContext::FalseExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::FalseExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitFalseExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NullExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::NullExprContext::NULLL() {
  return getToken(TMSlangParser::NULLL, 0);
}

TMSlangParser::NullExprContext::NullExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::NullExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitNullExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprListContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::ExprListContext::LBRACE() {
  return getToken(TMSlangParser::LBRACE, 0);
}

tree::TerminalNode* TMSlangParser::ExprListContext::RBRACE() {
  return getToken(TMSlangParser::RBRACE, 0);
}

std::vector<tree::TerminalNode *> TMSlangParser::ExprListContext::SEMICOLON() {
  return getTokens(TMSlangParser::SEMICOLON);
}

tree::TerminalNode* TMSlangParser::ExprListContext::SEMICOLON(size_t i) {
  return getToken(TMSlangParser::SEMICOLON, i);
}

std::vector<TMSlangParser::ExprContext *> TMSlangParser::ExprListContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::ExprListContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

TMSlangParser::ExprListContext::ExprListContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::ExprListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitExprList(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqExprContext ------------------------------------------------------------------

std::vector<TMSlangParser::ExprContext *> TMSlangParser::EqExprContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::EqExprContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

tree::TerminalNode* TMSlangParser::EqExprContext::EQUAL() {
  return getToken(TMSlangParser::EQUAL, 0);
}

tree::TerminalNode* TMSlangParser::EqExprContext::NEQ() {
  return getToken(TMSlangParser::NEQ, 0);
}

TMSlangParser::EqExprContext::EqExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::EqExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitEqExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SelectContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::SelectContext::SELECT() {
  return getToken(TMSlangParser::SELECT, 0);
}

tree::TerminalNode* TMSlangParser::SelectContext::END() {
  return getToken(TMSlangParser::END, 0);
}

std::vector<TMSlangParser::SelectAltContext *> TMSlangParser::SelectContext::selectAlt() {
  return getRuleContexts<TMSlangParser::SelectAltContext>();
}

TMSlangParser::SelectAltContext* TMSlangParser::SelectContext::selectAlt(size_t i) {
  return getRuleContext<TMSlangParser::SelectAltContext>(i);
}

TMSlangParser::SelectContext::SelectContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::SelectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitSelect(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NewExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::NewExprContext::NEW() {
  return getToken(TMSlangParser::NEW, 0);
}

tree::TerminalNode* TMSlangParser::NewExprContext::TYPE() {
  return getToken(TMSlangParser::TYPE, 0);
}

TMSlangParser::NewExprContext::NewExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::NewExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitNewExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StrExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::StrExprContext::STRING() {
  return getToken(TMSlangParser::STRING, 0);
}

TMSlangParser::StrExprContext::StrExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::StrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitStrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::NotExprContext::TILDE() {
  return getToken(TMSlangParser::TILDE, 0);
}

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
//----------------- IntExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::IntExprContext::INTEGER() {
  return getToken(TMSlangParser::INTEGER, 0);
}

TMSlangParser::IntExprContext::IntExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::IntExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitIntExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LocalMethodCallContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::LocalMethodCallContext::LPAR() {
  return getToken(TMSlangParser::LPAR, 0);
}

tree::TerminalNode* TMSlangParser::LocalMethodCallContext::RPAR() {
  return getToken(TMSlangParser::RPAR, 0);
}

tree::TerminalNode* TMSlangParser::LocalMethodCallContext::ID() {
  return getToken(TMSlangParser::ID, 0);
}

std::vector<TMSlangParser::ExprContext *> TMSlangParser::LocalMethodCallContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::LocalMethodCallContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> TMSlangParser::LocalMethodCallContext::COMMA() {
  return getTokens(TMSlangParser::COMMA);
}

tree::TerminalNode* TMSlangParser::LocalMethodCallContext::COMMA(size_t i) {
  return getToken(TMSlangParser::COMMA, i);
}

TMSlangParser::LocalMethodCallContext::LocalMethodCallContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::LocalMethodCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitLocalMethodCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

tree::TerminalNode* TMSlangParser::ParenExprContext::LPAR() {
  return getToken(TMSlangParser::LPAR, 0);
}

TMSlangParser::ExprContext* TMSlangParser::ParenExprContext::expr() {
  return getRuleContext<TMSlangParser::ExprContext>(0);
}

tree::TerminalNode* TMSlangParser::ParenExprContext::RPAR() {
  return getToken(TMSlangParser::RPAR, 0);
}

TMSlangParser::ParenExprContext::ParenExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any TMSlangParser::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitParenExpr(this);
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
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, TMSlangParser::RuleExpr, precedence);

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
    setState(150);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<LocalMethodCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(84);
      dynamic_cast<LocalMethodCallContext *>(_localctx)->methodName = match(TMSlangParser::ID);
      setState(85);
      match(TMSlangParser::LPAR);
      setState(94);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TMSlangParser::FALSE)
        | (1ULL << TMSlangParser::IF)
        | (1ULL << TMSlangParser::ISNULL)
        | (1ULL << TMSlangParser::NEW)
        | (1ULL << TMSlangParser::NULLL)
        | (1ULL << TMSlangParser::SELECT)
        | (1ULL << TMSlangParser::TRUE)
        | (1ULL << TMSlangParser::WHILE)
        | (1ULL << TMSlangParser::LBRACE)
        | (1ULL << TMSlangParser::LPAR)
        | (1ULL << TMSlangParser::MINUS)
        | (1ULL << TMSlangParser::TILDE)
        | (1ULL << TMSlangParser::INTEGER)
        | (1ULL << TMSlangParser::ID)
        | (1ULL << TMSlangParser::STRING))) != 0)) {
        setState(86);
        dynamic_cast<LocalMethodCallContext *>(_localctx)->exprContext = expr(0);
        dynamic_cast<LocalMethodCallContext *>(_localctx)->args.push_back(dynamic_cast<LocalMethodCallContext *>(_localctx)->exprContext);
        setState(91);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == TMSlangParser::COMMA) {
          setState(87);
          match(TMSlangParser::COMMA);
          setState(88);
          dynamic_cast<LocalMethodCallContext *>(_localctx)->exprContext = expr(0);
          dynamic_cast<LocalMethodCallContext *>(_localctx)->args.push_back(dynamic_cast<LocalMethodCallContext *>(_localctx)->exprContext);
          setState(93);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(96);
      match(TMSlangParser::RPAR);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<IfExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(97);
      match(TMSlangParser::IF);
      setState(98);
      dynamic_cast<IfExprContext *>(_localctx)->condition = expr(0);
      setState(99);
      match(TMSlangParser::THEN);
      setState(100);
      dynamic_cast<IfExprContext *>(_localctx)->thenExp = expr(0);
      setState(101);
      match(TMSlangParser::ELSE);
      setState(102);
      dynamic_cast<IfExprContext *>(_localctx)->elseExp = expr(0);
      setState(103);
      match(TMSlangParser::FI);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<WhileExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(105);
      match(TMSlangParser::WHILE);
      setState(106);
      dynamic_cast<WhileExprContext *>(_localctx)->condition = expr(0);
      setState(107);
      match(TMSlangParser::LOOP);
      setState(108);
      dynamic_cast<WhileExprContext *>(_localctx)->action = expr(0);
      setState(109);
      match(TMSlangParser::POOL);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprListContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(111);
      match(TMSlangParser::LBRACE);
      setState(115); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(112);
        dynamic_cast<ExprListContext *>(_localctx)->exprContext = expr(0);
        dynamic_cast<ExprListContext *>(_localctx)->exprs.push_back(dynamic_cast<ExprListContext *>(_localctx)->exprContext);
        setState(113);
        match(TMSlangParser::SEMICOLON);
        setState(117); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TMSlangParser::FALSE)
        | (1ULL << TMSlangParser::IF)
        | (1ULL << TMSlangParser::ISNULL)
        | (1ULL << TMSlangParser::NEW)
        | (1ULL << TMSlangParser::NULLL)
        | (1ULL << TMSlangParser::SELECT)
        | (1ULL << TMSlangParser::TRUE)
        | (1ULL << TMSlangParser::WHILE)
        | (1ULL << TMSlangParser::LBRACE)
        | (1ULL << TMSlangParser::LPAR)
        | (1ULL << TMSlangParser::MINUS)
        | (1ULL << TMSlangParser::TILDE)
        | (1ULL << TMSlangParser::INTEGER)
        | (1ULL << TMSlangParser::ID)
        | (1ULL << TMSlangParser::STRING))) != 0));
      setState(119);
      match(TMSlangParser::RBRACE);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<SelectContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(121);
      match(TMSlangParser::SELECT);
      setState(123); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(122);
        selectAlt();
        setState(125); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TMSlangParser::FALSE)
        | (1ULL << TMSlangParser::IF)
        | (1ULL << TMSlangParser::ISNULL)
        | (1ULL << TMSlangParser::NEW)
        | (1ULL << TMSlangParser::NULLL)
        | (1ULL << TMSlangParser::SELECT)
        | (1ULL << TMSlangParser::TRUE)
        | (1ULL << TMSlangParser::WHILE)
        | (1ULL << TMSlangParser::LBRACE)
        | (1ULL << TMSlangParser::LPAR)
        | (1ULL << TMSlangParser::MINUS)
        | (1ULL << TMSlangParser::TILDE)
        | (1ULL << TMSlangParser::INTEGER)
        | (1ULL << TMSlangParser::ID)
        | (1ULL << TMSlangParser::STRING))) != 0));
      setState(127);
      match(TMSlangParser::END);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<NewExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(129);
      match(TMSlangParser::NEW);
      setState(130);
      dynamic_cast<NewExprContext *>(_localctx)->type = match(TMSlangParser::TYPE);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<UMinusExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(131);
      match(TMSlangParser::MINUS);
      setState(132);
      expr(15);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<IsNullExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(133);
      match(TMSlangParser::ISNULL);
      setState(134);
      expr(14);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<NotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(135);
      match(TMSlangParser::TILDE);
      setState(136);
      expr(9);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(137);
      match(TMSlangParser::LPAR);
      setState(138);
      expr(0);
      setState(139);
      match(TMSlangParser::RPAR);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<AssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(141);
      match(TMSlangParser::ID);
      setState(142);
      match(TMSlangParser::LESSDASH);
      setState(143);
      expr(7);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<IDExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(144);
      match(TMSlangParser::ID);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<IntExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(145);
      match(TMSlangParser::INTEGER);
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<StrExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(146);
      match(TMSlangParser::STRING);
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<TrueExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(147);
      match(TMSlangParser::TRUE);
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<FalseExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(148);
      match(TMSlangParser::FALSE);
      break;
    }

    case 17: {
      _localctx = _tracker.createInstance<NullExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(149);
      match(TMSlangParser::NULLL);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(181);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(179);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(152);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(153);
          _la = _input->LA(1);
          if (!(_la == TMSlangParser::SLASH

          || _la == TMSlangParser::STAR)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(154);
          dynamic_cast<MultExprContext *>(_localctx)->right = expr(14);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(155);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(156);
          _la = _input->LA(1);
          if (!(_la == TMSlangParser::MINUS

          || _la == TMSlangParser::PLUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(157);
          dynamic_cast<AddExprContext *>(_localctx)->right = expr(13);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(158);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(159);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << TMSlangParser::GEQ)
            | (1ULL << TMSlangParser::GTR)
            | (1ULL << TMSlangParser::LEQ)
            | (1ULL << TMSlangParser::LESS))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(160);
          dynamic_cast<RelExprContext *>(_localctx)->right = expr(12);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EqExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(161);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(162);
          _la = _input->LA(1);
          if (!(_la == TMSlangParser::EQUAL

          || _la == TMSlangParser::NEQ)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(163);
          dynamic_cast<EqExprContext *>(_localctx)->right = expr(10);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<FullMethodCallContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(164);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(165);
          match(TMSlangParser::DOT);
          setState(166);
          dynamic_cast<FullMethodCallContext *>(_localctx)->methodName = match(TMSlangParser::ID);
          setState(167);
          match(TMSlangParser::LPAR);
          setState(176);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << TMSlangParser::FALSE)
            | (1ULL << TMSlangParser::IF)
            | (1ULL << TMSlangParser::ISNULL)
            | (1ULL << TMSlangParser::NEW)
            | (1ULL << TMSlangParser::NULLL)
            | (1ULL << TMSlangParser::SELECT)
            | (1ULL << TMSlangParser::TRUE)
            | (1ULL << TMSlangParser::WHILE)
            | (1ULL << TMSlangParser::LBRACE)
            | (1ULL << TMSlangParser::LPAR)
            | (1ULL << TMSlangParser::MINUS)
            | (1ULL << TMSlangParser::TILDE)
            | (1ULL << TMSlangParser::INTEGER)
            | (1ULL << TMSlangParser::ID)
            | (1ULL << TMSlangParser::STRING))) != 0)) {
            setState(168);
            dynamic_cast<FullMethodCallContext *>(_localctx)->exprContext = expr(0);
            dynamic_cast<FullMethodCallContext *>(_localctx)->args.push_back(dynamic_cast<FullMethodCallContext *>(_localctx)->exprContext);
            setState(173);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == TMSlangParser::COMMA) {
              setState(169);
              match(TMSlangParser::COMMA);
              setState(170);
              dynamic_cast<FullMethodCallContext *>(_localctx)->exprContext = expr(0);
              dynamic_cast<FullMethodCallContext *>(_localctx)->args.push_back(dynamic_cast<FullMethodCallContext *>(_localctx)->exprContext);
              setState(175);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(178);
          match(TMSlangParser::RPAR);
          break;
        }

        default:
          break;
        } 
      }
      setState(183);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- SelectAltContext ------------------------------------------------------------------

TMSlangParser::SelectAltContext::SelectAltContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TMSlangParser::ExprContext *> TMSlangParser::SelectAltContext::expr() {
  return getRuleContexts<TMSlangParser::ExprContext>();
}

TMSlangParser::ExprContext* TMSlangParser::SelectAltContext::expr(size_t i) {
  return getRuleContext<TMSlangParser::ExprContext>(i);
}

tree::TerminalNode* TMSlangParser::SelectAltContext::COLON() {
  return getToken(TMSlangParser::COLON, 0);
}

tree::TerminalNode* TMSlangParser::SelectAltContext::SEMICOLON() {
  return getToken(TMSlangParser::SEMICOLON, 0);
}


size_t TMSlangParser::SelectAltContext::getRuleIndex() const {
  return TMSlangParser::RuleSelectAlt;
}


antlrcpp::Any TMSlangParser::SelectAltContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TMSlangVisitor*>(visitor))
    return parserVisitor->visitSelectAlt(this);
  else
    return visitor->visitChildren(this);
}

TMSlangParser::SelectAltContext* TMSlangParser::selectAlt() {
  SelectAltContext *_localctx = _tracker.createInstance<SelectAltContext>(_ctx, getState());
  enterRule(_localctx, 16, TMSlangParser::RuleSelectAlt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    expr(0);
    setState(185);
    match(TMSlangParser::COLON);
    setState(186);
    expr(0);
    setState(187);
    match(TMSlangParser::SEMICOLON);
   
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
    case 7: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TMSlangParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 13);
    case 1: return precpred(_ctx, 12);
    case 2: return precpred(_ctx, 11);
    case 3: return precpred(_ctx, 10);
    case 4: return precpred(_ctx, 22);

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
  "program", "classDef", "classBody", "method", "variableDecl", "formal", 
  "typeName", "expr", "selectAlt"
};

std::vector<std::string> TMSlangParser::_literalNames = {
  "", "'boolean'", "'class'", "'else'", "'end'", "'false'", "'fi'", "'if'", 
  "'in'", "'int'", "'inherits'", "'isnull'", "'loop'", "'new'", "'null'", 
  "'pool'", "'select'", "'then'", "'true'", "'while'", "':'", "','", "'.'", 
  "'='", "'>='", "'>'", "'{'", "'<='", "'<-'", "'<'", "'('", "'-'", "'~='", 
  "'+'", "'}'", "')'", "';'", "'/'", "'*'", "'~'"
};

std::vector<std::string> TMSlangParser::_symbolicNames = {
  "", "BOOL", "CLASS", "ELSE", "END", "FALSE", "FI", "IF", "IN", "INT", 
  "INHERITS", "ISNULL", "LOOP", "NEW", "NULLL", "POOL", "SELECT", "THEN", 
  "TRUE", "WHILE", "COLON", "COMMA", "DOT", "EQUAL", "GEQ", "GTR", "LBRACE", 
  "LEQ", "LESSDASH", "LESS", "LPAR", "MINUS", "NEQ", "PLUS", "RBRACE", "RPAR", 
  "SEMICOLON", "SLASH", "STAR", "TILDE", "WS", "INTEGER", "TYPE", "ID", 
  "STRING", "COMMENT"
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
       0x3, 0x2f, 0xc0, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
       0x3, 0x1b, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x5, 0x4, 0x22, 0xa, 0x4, 0x7, 0x4, 0x24, 0xa, 0x4, 0xc, 0x4, 
       0xe, 0x4, 0x27, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x30, 0xa, 0x5, 0xc, 0x5, 
       0xe, 0x5, 0x33, 0xb, 0x5, 0x5, 0x5, 0x35, 0xa, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x3c, 0xa, 0x5, 0xc, 
       0x5, 0xe, 0x5, 0x3f, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x49, 0xa, 
       0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x54, 0xa, 0x8, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x5c, 
       0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x5f, 0xb, 0x9, 0x5, 0x9, 0x61, 0xa, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x6, 0x9, 0x76, 0xa, 0x9, 0xd, 0x9, 0xe, 0x9, 0x77, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x6, 0x9, 0x7e, 0xa, 0x9, 0xd, 0x9, 0xe, 
       0x9, 0x7f, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x99, 0xa, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x7, 0x9, 0xae, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xb1, 0xb, 0x9, 0x5, 
       0x9, 0xb3, 0xa, 0x9, 0x3, 0x9, 0x7, 0x9, 0xb6, 0xa, 0x9, 0xc, 0x9, 
       0xe, 0x9, 0xb9, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
       0x3, 0xa, 0x3, 0xa, 0x2, 0x3, 0x10, 0xb, 0x2, 0x4, 0x6, 0x8, 0xa, 
       0xc, 0xe, 0x10, 0x12, 0x2, 0x6, 0x3, 0x2, 0x27, 0x28, 0x4, 0x2, 0x21, 
       0x21, 0x23, 0x23, 0x5, 0x2, 0x1a, 0x1b, 0x1d, 0x1d, 0x1f, 0x1f, 0x4, 
       0x2, 0x19, 0x19, 0x22, 0x22, 0x2, 0xda, 0x2, 0x14, 0x3, 0x2, 0x2, 
       0x2, 0x4, 0x16, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1e, 0x3, 0x2, 0x2, 0x2, 
       0x8, 0x2a, 0x3, 0x2, 0x2, 0x2, 0xa, 0x43, 0x3, 0x2, 0x2, 0x2, 0xc, 
       0x4c, 0x3, 0x2, 0x2, 0x2, 0xe, 0x53, 0x3, 0x2, 0x2, 0x2, 0x10, 0x98, 
       0x3, 0x2, 0x2, 0x2, 0x12, 0xba, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x5, 
       0x4, 0x3, 0x2, 0x15, 0x3, 0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 0x7, 0x4, 
       0x2, 0x2, 0x17, 0x1a, 0x7, 0x2c, 0x2, 0x2, 0x18, 0x19, 0x7, 0xc, 
       0x2, 0x2, 0x19, 0x1b, 0x7, 0x2c, 0x2, 0x2, 0x1a, 0x18, 0x3, 0x2, 
       0x2, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x2, 
       0x2, 0x1c, 0x1d, 0x5, 0x6, 0x4, 0x2, 0x1d, 0x5, 0x3, 0x2, 0x2, 0x2, 
       0x1e, 0x25, 0x7, 0x1c, 0x2, 0x2, 0x1f, 0x22, 0x5, 0xa, 0x6, 0x2, 
       0x20, 0x22, 0x5, 0x8, 0x5, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 
       0x20, 0x3, 0x2, 0x2, 0x2, 0x22, 0x24, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 
       0x3, 0x2, 0x2, 0x2, 0x24, 0x27, 0x3, 0x2, 0x2, 0x2, 0x25, 0x23, 0x3, 
       0x2, 0x2, 0x2, 0x25, 0x26, 0x3, 0x2, 0x2, 0x2, 0x26, 0x28, 0x3, 0x2, 
       0x2, 0x2, 0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x7, 0x24, 
       0x2, 0x2, 0x29, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0x2d, 0x2, 
       0x2, 0x2b, 0x34, 0x7, 0x20, 0x2, 0x2, 0x2c, 0x31, 0x5, 0xc, 0x7, 
       0x2, 0x2d, 0x2e, 0x7, 0x17, 0x2, 0x2, 0x2e, 0x30, 0x5, 0xc, 0x7, 
       0x2, 0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x30, 0x33, 0x3, 0x2, 0x2, 0x2, 
       0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 0x32, 
       0x35, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x34, 0x2c, 
       0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 
       0x2, 0x2, 0x2, 0x36, 0x37, 0x7, 0x25, 0x2, 0x2, 0x37, 0x38, 0x7, 
       0x16, 0x2, 0x2, 0x38, 0x39, 0x5, 0xe, 0x8, 0x2, 0x39, 0x3d, 0x7, 
       0x1c, 0x2, 0x2, 0x3a, 0x3c, 0x5, 0xa, 0x6, 0x2, 0x3b, 0x3a, 0x3, 
       0x2, 0x2, 0x2, 0x3c, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 
       0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x40, 0x3, 0x2, 0x2, 
       0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x5, 0x10, 0x9, 
       0x2, 0x41, 0x42, 0x7, 0x24, 0x2, 0x2, 0x42, 0x9, 0x3, 0x2, 0x2, 0x2, 
       0x43, 0x44, 0x7, 0x2d, 0x2, 0x2, 0x44, 0x45, 0x7, 0x16, 0x2, 0x2, 
       0x45, 0x48, 0x5, 0xe, 0x8, 0x2, 0x46, 0x47, 0x7, 0x1e, 0x2, 0x2, 
       0x47, 0x49, 0x5, 0x10, 0x9, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 
       0x48, 0x49, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 
       0x4b, 0x7, 0x26, 0x2, 0x2, 0x4b, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 
       0x7, 0x2d, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x16, 0x2, 0x2, 0x4e, 0x4f, 
       0x5, 0xe, 0x8, 0x2, 0x4f, 0xd, 0x3, 0x2, 0x2, 0x2, 0x50, 0x54, 0x7, 
       0x2c, 0x2, 0x2, 0x51, 0x54, 0x7, 0xb, 0x2, 0x2, 0x52, 0x54, 0x7, 
       0x3, 0x2, 0x2, 0x53, 0x50, 0x3, 0x2, 0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 
       0x2, 0x2, 0x53, 0x52, 0x3, 0x2, 0x2, 0x2, 0x54, 0xf, 0x3, 0x2, 0x2, 
       0x2, 0x55, 0x56, 0x8, 0x9, 0x1, 0x2, 0x56, 0x57, 0x7, 0x2d, 0x2, 
       0x2, 0x57, 0x60, 0x7, 0x20, 0x2, 0x2, 0x58, 0x5d, 0x5, 0x10, 0x9, 
       0x2, 0x59, 0x5a, 0x7, 0x17, 0x2, 0x2, 0x5a, 0x5c, 0x5, 0x10, 0x9, 
       0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5f, 0x3, 0x2, 0x2, 0x2, 
       0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 
       0x61, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x60, 0x58, 
       0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x3, 
       0x2, 0x2, 0x2, 0x62, 0x99, 0x7, 0x25, 0x2, 0x2, 0x63, 0x64, 0x7, 
       0x9, 0x2, 0x2, 0x64, 0x65, 0x5, 0x10, 0x9, 0x2, 0x65, 0x66, 0x7, 
       0x13, 0x2, 0x2, 0x66, 0x67, 0x5, 0x10, 0x9, 0x2, 0x67, 0x68, 0x7, 
       0x5, 0x2, 0x2, 0x68, 0x69, 0x5, 0x10, 0x9, 0x2, 0x69, 0x6a, 0x7, 
       0x8, 0x2, 0x2, 0x6a, 0x99, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x15, 
       0x2, 0x2, 0x6c, 0x6d, 0x5, 0x10, 0x9, 0x2, 0x6d, 0x6e, 0x7, 0xe, 
       0x2, 0x2, 0x6e, 0x6f, 0x5, 0x10, 0x9, 0x2, 0x6f, 0x70, 0x7, 0x11, 
       0x2, 0x2, 0x70, 0x99, 0x3, 0x2, 0x2, 0x2, 0x71, 0x75, 0x7, 0x1c, 
       0x2, 0x2, 0x72, 0x73, 0x5, 0x10, 0x9, 0x2, 0x73, 0x74, 0x7, 0x26, 
       0x2, 0x2, 0x74, 0x76, 0x3, 0x2, 0x2, 0x2, 0x75, 0x72, 0x3, 0x2, 0x2, 
       0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 
       0x77, 0x78, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 0x2, 0x79, 
       0x7a, 0x7, 0x24, 0x2, 0x2, 0x7a, 0x99, 0x3, 0x2, 0x2, 0x2, 0x7b, 
       0x7d, 0x7, 0x12, 0x2, 0x2, 0x7c, 0x7e, 0x5, 0x12, 0xa, 0x2, 0x7d, 
       0x7c, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 
       0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 
       0x2, 0x2, 0x2, 0x81, 0x82, 0x7, 0x6, 0x2, 0x2, 0x82, 0x99, 0x3, 0x2, 
       0x2, 0x2, 0x83, 0x84, 0x7, 0xf, 0x2, 0x2, 0x84, 0x99, 0x7, 0x2c, 
       0x2, 0x2, 0x85, 0x86, 0x7, 0x21, 0x2, 0x2, 0x86, 0x99, 0x5, 0x10, 
       0x9, 0x11, 0x87, 0x88, 0x7, 0xd, 0x2, 0x2, 0x88, 0x99, 0x5, 0x10, 
       0x9, 0x10, 0x89, 0x8a, 0x7, 0x29, 0x2, 0x2, 0x8a, 0x99, 0x5, 0x10, 
       0x9, 0xb, 0x8b, 0x8c, 0x7, 0x20, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0x10, 
       0x9, 0x2, 0x8d, 0x8e, 0x7, 0x25, 0x2, 0x2, 0x8e, 0x99, 0x3, 0x2, 
       0x2, 0x2, 0x8f, 0x90, 0x7, 0x2d, 0x2, 0x2, 0x90, 0x91, 0x7, 0x1e, 
       0x2, 0x2, 0x91, 0x99, 0x5, 0x10, 0x9, 0x9, 0x92, 0x99, 0x7, 0x2d, 
       0x2, 0x2, 0x93, 0x99, 0x7, 0x2b, 0x2, 0x2, 0x94, 0x99, 0x7, 0x2e, 
       0x2, 0x2, 0x95, 0x99, 0x7, 0x14, 0x2, 0x2, 0x96, 0x99, 0x7, 0x7, 
       0x2, 0x2, 0x97, 0x99, 0x7, 0x10, 0x2, 0x2, 0x98, 0x55, 0x3, 0x2, 
       0x2, 0x2, 0x98, 0x63, 0x3, 0x2, 0x2, 0x2, 0x98, 0x6b, 0x3, 0x2, 0x2, 
       0x2, 0x98, 0x71, 0x3, 0x2, 0x2, 0x2, 0x98, 0x7b, 0x3, 0x2, 0x2, 0x2, 
       0x98, 0x83, 0x3, 0x2, 0x2, 0x2, 0x98, 0x85, 0x3, 0x2, 0x2, 0x2, 0x98, 
       0x87, 0x3, 0x2, 0x2, 0x2, 0x98, 0x89, 0x3, 0x2, 0x2, 0x2, 0x98, 0x8b, 
       0x3, 0x2, 0x2, 0x2, 0x98, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x98, 0x92, 0x3, 
       0x2, 0x2, 0x2, 0x98, 0x93, 0x3, 0x2, 0x2, 0x2, 0x98, 0x94, 0x3, 0x2, 
       0x2, 0x2, 0x98, 0x95, 0x3, 0x2, 0x2, 0x2, 0x98, 0x96, 0x3, 0x2, 0x2, 
       0x2, 0x98, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0xb7, 0x3, 0x2, 0x2, 0x2, 
       0x9a, 0x9b, 0xc, 0xf, 0x2, 0x2, 0x9b, 0x9c, 0x9, 0x2, 0x2, 0x2, 0x9c, 
       0xb6, 0x5, 0x10, 0x9, 0x10, 0x9d, 0x9e, 0xc, 0xe, 0x2, 0x2, 0x9e, 
       0x9f, 0x9, 0x3, 0x2, 0x2, 0x9f, 0xb6, 0x5, 0x10, 0x9, 0xf, 0xa0, 
       0xa1, 0xc, 0xd, 0x2, 0x2, 0xa1, 0xa2, 0x9, 0x4, 0x2, 0x2, 0xa2, 0xb6, 
       0x5, 0x10, 0x9, 0xe, 0xa3, 0xa4, 0xc, 0xc, 0x2, 0x2, 0xa4, 0xa5, 
       0x9, 0x5, 0x2, 0x2, 0xa5, 0xb6, 0x5, 0x10, 0x9, 0xc, 0xa6, 0xa7, 
       0xc, 0x18, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x18, 0x2, 0x2, 0xa8, 0xa9, 
       0x7, 0x2d, 0x2, 0x2, 0xa9, 0xb2, 0x7, 0x20, 0x2, 0x2, 0xaa, 0xaf, 
       0x5, 0x10, 0x9, 0x2, 0xab, 0xac, 0x7, 0x17, 0x2, 0x2, 0xac, 0xae, 
       0x5, 0x10, 0x9, 0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb1, 
       0x3, 0x2, 0x2, 0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x3, 
       0x2, 0x2, 0x2, 0xb0, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xaf, 0x3, 0x2, 
       0x2, 0x2, 0xb2, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 
       0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb6, 0x7, 0x25, 0x2, 
       0x2, 0xb5, 0x9a, 0x3, 0x2, 0x2, 0x2, 0xb5, 0x9d, 0x3, 0x2, 0x2, 0x2, 
       0xb5, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xb5, 
       0xa6, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb5, 
       0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x11, 0x3, 
       0x2, 0x2, 0x2, 0xb9, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x5, 0x10, 
       0x9, 0x2, 0xbb, 0xbc, 0x7, 0x16, 0x2, 0x2, 0xbc, 0xbd, 0x5, 0x10, 
       0x9, 0x2, 0xbd, 0xbe, 0x7, 0x26, 0x2, 0x2, 0xbe, 0x13, 0x3, 0x2, 
       0x2, 0x2, 0x13, 0x1a, 0x21, 0x25, 0x31, 0x34, 0x3d, 0x48, 0x53, 0x5d, 
       0x60, 0x77, 0x7f, 0x98, 0xaf, 0xb2, 0xb5, 0xb7, 
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
