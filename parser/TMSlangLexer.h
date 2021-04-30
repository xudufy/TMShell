
// Generated from C:/projects/TMShell/grammar/TMSlang.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"


namespace tmshell {


class  TMSlangLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, COLON = 23, TEXTARG = 24, POUND = 25, LEFTBRACE = 26, 
    RIGHTBRACE = 27, RIGHTARROW = 28, VAR = 29, SESSION = 30, GLOBAL = 31, 
    ID = 32, TimePointLiteral = 33, DurationLiteral = 34, DurationFragment = 35, 
    IntegerLiteral = 36, StringLiteral = 37, WS = 38, ESCAPEDNEWLINE = 39, 
    NEWLINE_SKIP = 40, NEWLINE = 41, ERRORCHAR = 42
  };

  explicit TMSlangLexer(antlr4::CharStream *input);
  ~TMSlangLexer();


    int textArgModeUntilNewLine = 0;
    int textArgModeUntilSpace = 0;
    int skipNewline = 0;

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

  virtual void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;
  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

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
  void COLONAction(antlr4::RuleContext *context, size_t actionIndex);
  void POUNDAction(antlr4::RuleContext *context, size_t actionIndex);
  void LEFTBRACEAction(antlr4::RuleContext *context, size_t actionIndex);
  void RIGHTBRACEAction(antlr4::RuleContext *context, size_t actionIndex);
  void RIGHTARROWAction(antlr4::RuleContext *context, size_t actionIndex);
  void WSAction(antlr4::RuleContext *context, size_t actionIndex);
  void NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.
  bool TEXTARGSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool NEWLINE_SKIPSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace tmshell
