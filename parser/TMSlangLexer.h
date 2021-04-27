
// Generated from C:/projects/TMShell/grammar/TMSlang.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"


namespace tmshell {


class  TMSlangLexer : public antlr4::Lexer {
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

  explicit TMSlangLexer(antlr4::CharStream *input);
  ~TMSlangLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace tmshell
