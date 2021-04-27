
// Generated from C:/projects/TMShell/grammar/TMSlang.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"


namespace tmshell {


class  TMSlangParser : public antlr4::Parser {
public:
  enum {
    BOOL = 1, CLASS = 2, ELSE = 3, END = 4, FALSE = 5, FI = 6, IF = 7, IN = 8, 
    INT = 9, INHERITS = 10, ISNULL = 11, LOOP = 12, NEW = 13, NULLL = 14, 
    POOL = 15, SELECT = 16, THEN = 17, TRUE = 18, WHILE = 19, COLON = 20, 
    COMMA = 21, DOT = 22, EQUAL = 23, GEQ = 24, GTR = 25, LBRACE = 26, LEQ = 27, 
    LESSDASH = 28, LESS = 29, LPAR = 30, MINUS = 31, NEQ = 32, PLUS = 33, 
    RBRACE = 34, RPAR = 35, SEMICOLON = 36, SLASH = 37, STAR = 38, TILDE = 39, 
    WS = 40, INTEGER = 41, TYPE = 42, ID = 43, STRING = 44, COMMENT = 45
  };

  enum {
    RuleProgram = 0, RuleClassDef = 1, RuleClassBody = 2, RuleMethod = 3, 
    RuleVariableDecl = 4, RuleFormal = 5, RuleTypeName = 6, RuleExpr = 7, 
    RuleSelectAlt = 8
  };

  explicit TMSlangParser(antlr4::TokenStream *input);
  ~TMSlangParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class ClassDefContext;
  class ClassBodyContext;
  class MethodContext;
  class VariableDeclContext;
  class FormalContext;
  class TypeNameContext;
  class ExprContext;
  class SelectAltContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    TMSlangParser::ClassDefContext *classDefContext = nullptr;
    std::vector<ClassDefContext *> classes;
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassDefContext *classDef();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ClassDefContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *className = nullptr;
    antlr4::Token *inherits = nullptr;
    ClassDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLASS();
    ClassBodyContext *classBody();
    std::vector<antlr4::tree::TerminalNode *> TYPE();
    antlr4::tree::TerminalNode* TYPE(size_t i);
    antlr4::tree::TerminalNode *INHERITS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassDefContext* classDef();

  class  ClassBodyContext : public antlr4::ParserRuleContext {
  public:
    TMSlangParser::VariableDeclContext *variableDeclContext = nullptr;
    std::vector<VariableDeclContext *> variables;
    TMSlangParser::MethodContext *methodContext = nullptr;
    std::vector<MethodContext *> methods;
    ClassBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<VariableDeclContext *> variableDecl();
    VariableDeclContext* variableDecl(size_t i);
    std::vector<MethodContext *> method();
    MethodContext* method(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassBodyContext* classBody();

  class  MethodContext : public antlr4::ParserRuleContext {
  public:
    TMSlangParser::FormalContext *formalContext = nullptr;
    std::vector<FormalContext *> formals;
    TMSlangParser::TypeNameContext *type = nullptr;
    TMSlangParser::VariableDeclContext *variableDeclContext = nullptr;
    std::vector<VariableDeclContext *> vars;
    MethodContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *LBRACE();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RBRACE();
    TypeNameContext *typeName();
    std::vector<FormalContext *> formal();
    FormalContext* formal(size_t i);
    std::vector<VariableDeclContext *> variableDecl();
    VariableDeclContext* variableDecl(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodContext* method();

  class  VariableDeclContext : public antlr4::ParserRuleContext {
  public:
    TMSlangParser::TypeNameContext *type = nullptr;
    TMSlangParser::ExprContext *initializer = nullptr;
    VariableDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *SEMICOLON();
    TypeNameContext *typeName();
    antlr4::tree::TerminalNode *LESSDASH();
    ExprContext *expr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclContext* variableDecl();

  class  FormalContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *name = nullptr;
    TMSlangParser::TypeNameContext *type = nullptr;
    FormalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *ID();
    TypeNameContext *typeName();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormalContext* formal();

  class  TypeNameContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *classType = nullptr;
    antlr4::Token *intType = nullptr;
    antlr4::Token *boolType = nullptr;
    TypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *BOOL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeNameContext* typeName();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  WhileExprContext : public ExprContext {
  public:
    WhileExprContext(ExprContext *ctx);

    TMSlangParser::ExprContext *condition = nullptr;
    TMSlangParser::ExprContext *action = nullptr;
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *LOOP();
    antlr4::tree::TerminalNode *POOL();
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

  class  IfExprContext : public ExprContext {
  public:
    IfExprContext(ExprContext *ctx);

    TMSlangParser::ExprContext *condition = nullptr;
    TMSlangParser::ExprContext *thenExp = nullptr;
    TMSlangParser::ExprContext *elseExp = nullptr;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *THEN();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *FI();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TrueExprContext : public ExprContext {
  public:
    TrueExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *TRUE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IsNullExprContext : public ExprContext {
  public:
    IsNullExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *ISNULL();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RelExprContext : public ExprContext {
  public:
    RelExprContext(ExprContext *ctx);

    TMSlangParser::ExprContext *left = nullptr;
    TMSlangParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *LESS();
    antlr4::tree::TerminalNode *LEQ();
    antlr4::tree::TerminalNode *GTR();
    antlr4::tree::TerminalNode *GEQ();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MultExprContext : public ExprContext {
  public:
    MultExprContext(ExprContext *ctx);

    TMSlangParser::ExprContext *left = nullptr;
    TMSlangParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *SLASH();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FullMethodCallContext : public ExprContext {
  public:
    FullMethodCallContext(ExprContext *ctx);

    TMSlangParser::ExprContext *object = nullptr;
    antlr4::Token *methodName = nullptr;
    TMSlangParser::ExprContext *exprContext = nullptr;
    std::vector<ExprContext *> args;
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *ID();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddExprContext : public ExprContext {
  public:
    AddExprContext(ExprContext *ctx);

    TMSlangParser::ExprContext *left = nullptr;
    TMSlangParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UMinusExprContext : public ExprContext {
  public:
    UMinusExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *MINUS();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignExprContext : public ExprContext {
  public:
    AssignExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LESSDASH();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FalseExprContext : public ExprContext {
  public:
    FalseExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *FALSE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NullExprContext : public ExprContext {
  public:
    NullExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *NULLL();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprListContext : public ExprContext {
  public:
    ExprListContext(ExprContext *ctx);

    TMSlangParser::ExprContext *exprContext = nullptr;
    std::vector<ExprContext *> exprs;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EqExprContext : public ExprContext {
  public:
    EqExprContext(ExprContext *ctx);

    TMSlangParser::ExprContext *left = nullptr;
    TMSlangParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *NEQ();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SelectContext : public ExprContext {
  public:
    SelectContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *SELECT();
    antlr4::tree::TerminalNode *END();
    std::vector<SelectAltContext *> selectAlt();
    SelectAltContext* selectAlt(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NewExprContext : public ExprContext {
  public:
    NewExprContext(ExprContext *ctx);

    antlr4::Token *type = nullptr;
    antlr4::tree::TerminalNode *NEW();
    antlr4::tree::TerminalNode *TYPE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StrExprContext : public ExprContext {
  public:
    StrExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NotExprContext : public ExprContext {
  public:
    NotExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *TILDE();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntExprContext : public ExprContext {
  public:
    IntExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *INTEGER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LocalMethodCallContext : public ExprContext {
  public:
    LocalMethodCallContext(ExprContext *ctx);

    antlr4::Token *methodName = nullptr;
    TMSlangParser::ExprContext *exprContext = nullptr;
    std::vector<ExprContext *> args;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *ID();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenExprContext : public ExprContext {
  public:
    ParenExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *LPAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  SelectAltContext : public antlr4::ParserRuleContext {
  public:
    SelectAltContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectAltContext* selectAlt();


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
