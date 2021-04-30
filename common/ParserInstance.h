#pragma once

#include "../parser/TMSlang.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <functional>

#include "../common/StringErrorListener.h"

namespace tmshell {

class ParserInstance {
public:
  ParserInstance(const std::string & input);  

  TMSlangParser::ProgramContext* parseProgram();
  TMSlangParser::Execute_lineContext* parseLine();
  TMSlangParser::ExprContext* parseAction();

  TMSlangParser& getParser() {return _parser;}
  std::string getLastError() {return _logListener.msg;}
  std::string getOffending() {return _logListener.offendingToken;}
  bool isParsed() {return parsed;}
  bool isComleted() {return completed;}

private:
  void* parse(std::function<void*(TMSlangParser*)> ruleFunc);

  bool parsed = false;
  bool completed = false;
  ANTLRInputStream _input;
  TMSlangLexer _lexer;
  CommonTokenStream _tokens;
  TMSlangParser _parser;
  StringErrorListener _logListener;

  TMSlangParser::ProgramContext* programNode = nullptr;
  TMSlangParser::Execute_lineContext* lineNode = nullptr;
  TMSlangParser::ExprContext* actionNode = nullptr;

};

}