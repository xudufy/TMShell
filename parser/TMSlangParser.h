
// Generated from C:/projects/TMShell/grammar/TMSlang.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"


namespace tmshell {


class  TMSlangParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, COLON = 23, TEXTARG = 24, IF = 25, ELSE = 26, 
    POUND = 27, LEFTBRACE = 28, RIGHTBRACE = 29, RIGHTARROW = 30, LET = 31, 
    SESSION = 32, GLOBAL = 33, BoolLiteral = 34, ID = 35, TimePointLiteral = 36, 
    DurationLiteral = 37, DurationFragment = 38, IntegerLiteral = 39, StringLiteral = 40, 
    WS = 41, ESCAPEDNEWLINE = 42, NEWLINE_SKIP = 43, NEWLINE = 44, ERRORCHAR = 45
  };

  enum {
    RuleProgram = 0, RuleExecute_line = 1, RuleMgmt_command = 2, RuleCmd_arg = 3, 
    RuleVarDef = 4, RuleTriggerDef = 5, RuleExpr = 6
  };

  explicit TMSlangParser(antlr4::TokenStream *input);
  ~TMSlangParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class Execute_lineContext;
  class Mgmt_commandContext;
  class Cmd_argContext;
  class VarDefContext;
  class TriggerDefContext;
  class ExprContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Execute_lineContext *> execute_line();
    Execute_lineContext* execute_line(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  Execute_lineContext : public antlr4::ParserRuleContext {
  public:
    Execute_lineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEWLINE();
    Mgmt_commandContext *mgmt_command();
    VarDefContext *varDef();
    TriggerDefContext *triggerDef();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Execute_lineContext* execute_line();

  class  Mgmt_commandContext : public antlr4::ParserRuleContext {
  public:
    TMSlangParser::Cmd_argContext *command_name = nullptr;
    TMSlangParser::Cmd_argContext *cmd_argContext = nullptr;
    std::vector<Cmd_argContext *> args;
    Mgmt_commandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    std::vector<Cmd_argContext *> cmd_arg();
    Cmd_argContext* cmd_arg(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mgmt_commandContext* mgmt_command();

  class  Cmd_argContext : public antlr4::ParserRuleContext {
  public:
    Cmd_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Cmd_argContext() = default;
    void copyFrom(Cmd_argContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PlainArgContext : public Cmd_argContext {
  public:
    PlainArgContext(Cmd_argContext *ctx);

    antlr4::tree::TerminalNode *TEXTARG();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  QuotedArgContext : public Cmd_argContext {
  public:
    QuotedArgContext(Cmd_argContext *ctx);

    antlr4::tree::TerminalNode *StringLiteral();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Cmd_argContext* cmd_arg();

  class  VarDefContext : public antlr4::ParserRuleContext {
  public:
    VarDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VarDefContext() = default;
    void copyFrom(VarDefContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  GlobalVarDefContext : public VarDefContext {
  public:
    GlobalVarDefContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *LET();
    antlr4::tree::TerminalNode *GLOBAL();
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SessionVarDefContext : public VarDefContext {
  public:
    SessionVarDefContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *LET();
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  VarDefContext* varDef();

  class  TriggerDefContext : public antlr4::ParserRuleContext {
  public:
    TMSlangParser::ExprContext *signal = nullptr;
    TMSlangParser::Cmd_argContext *trigger_name = nullptr;
    TMSlangParser::ExprContext *exprContext = nullptr;
    std::vector<ExprContext *> action;
    TriggerDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RIGHTARROW();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *POUND();
    Cmd_argContext *cmd_arg();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TriggerDefContext* triggerDef();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MulExprContext : public ExprContext {
  public:
    MulExprContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IDExprContext : public ExprContext {
  public:
    IDExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BoolExprContext : public ExprContext {
  public:
    BoolExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *BoolLiteral();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EqlExprContext : public ExprContext {
  public:
    EqlExprContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfExprContext : public ExprContext {
  public:
    IfExprContext(ExprContext *ctx);

    TMSlangParser::ExprContext *cond = nullptr;
    TMSlangParser::ExprContext *then = nullptr;
    TMSlangParser::ExprContext *epart = nullptr;
    antlr4::tree::TerminalNode *IF();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RelExprContext : public ExprContext {
  public:
    RelExprContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LogicExprContext : public ExprContext {
  public:
    LogicExprContext(ExprContext *ctx);

    TMSlangParser::ExprContext *lhs = nullptr;
    antlr4::Token *op = nullptr;
    TMSlangParser::ExprContext *rhs = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PeriodicExprContext : public ExprContext {
  public:
    PeriodicExprContext(ExprContext *ctx);

    TMSlangParser::ExprContext *end = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NegExprContext : public ExprContext {
  public:
    NegExprContext(ExprContext *ctx);

    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddExprContext : public ExprContext {
  public:
    AddExprContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DurationLExprContext : public ExprContext {
  public:
    DurationLExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *DurationLiteral();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignExprContext : public ExprContext {
  public:
    AssignExprContext(ExprContext *ctx);

    antlr4::Token *idToken = nullptr;
    std::vector<antlr4::Token *> id;
    ExprContext *expr();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GroupExprContext : public ExprContext {
  public:
    GroupExprContext(ExprContext *ctx);

    TMSlangParser::ExprContext *exprContext = nullptr;
    std::vector<ExprContext *> inner;
    antlr4::tree::TerminalNode *LEFTBRACE();
    antlr4::tree::TerminalNode *RIGHTBRACE();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TimePointLExprContext : public ExprContext {
  public:
    TimePointLExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *TimePointLiteral();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringLExprContext : public ExprContext {
  public:
    StringLExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *StringLiteral();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParanExprContext : public ExprContext {
  public:
    ParanExprContext(ExprContext *ctx);

    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LaterExprContext : public ExprContext {
  public:
    LaterExprContext(ExprContext *ctx);

    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CurrentExprContext : public ExprContext {
  public:
    CurrentExprContext(ExprContext *ctx);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntLExprContext : public ExprContext {
  public:
    IntLExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *IntegerLiteral();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LocalVarDefExprContext : public ExprContext {
  public:
    LocalVarDefExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *LET();
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CallExprContext : public ExprContext {
  public:
    CallExprContext(ExprContext *ctx);

    TMSlangParser::ExprContext *exprContext = nullptr;
    std::vector<ExprContext *> args;
    antlr4::tree::TerminalNode *ID();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NotExprContext : public ExprContext {
  public:
    NotExprContext(ExprContext *ctx);

    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FieldExprContext : public ExprContext {
  public:
    FieldExprContext(ExprContext *ctx);

    ExprContext *expr();
    antlr4::tree::TerminalNode *ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);

  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace tmshell
