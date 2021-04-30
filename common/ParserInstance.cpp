#include "../common/common.h"
#include "ParserInstance.h"

using namespace tmshell;

ParserInstance::ParserInstance(const std::string & input)
: _input(input),
_lexer(&_input),
_tokens(&_lexer),
_parser(&_tokens)
{
  _parser.setErrorHandler(std::make_shared<BailErrorStrategy>());
  _parser.removeErrorListeners();
  _parser.addErrorListener(&_logListener);
}

TMSlangParser::ProgramContext* ParserInstance::parseProgram() {
  if (parsed) {
    if (completed) {
      ASSERT(programNode!=nullptr, "parserInstance has run at other enter rule.");
    }
    return programNode;
  }
  auto out = static_cast<TMSlangParser::ProgramContext*>(
    parse([](TMSlangParser* p){return p->program();})
    );
  programNode = out;
  return out;
}

TMSlangParser::Execute_lineContext* ParserInstance::parseLine() {
  if (parsed) {
    if (completed) {
      ASSERT(lineNode!=nullptr, "parserInstance has run at other enter rule.");
    }
    return lineNode;
  }
  auto out = static_cast<TMSlangParser::Execute_lineContext*>(
    parse([](TMSlangParser* p){return p->execute_line();})
    );
  lineNode = out;
  return out;
}

TMSlangParser::ExprContext* ParserInstance::parseAction() {
  if (parsed) {
    if (completed) {
      ASSERT(actionNode!=nullptr, "parserInstance has run at other enter rule.");
    }
    return actionNode;
  }
  auto out = static_cast<TMSlangParser::ExprContext*>(
    parse([](TMSlangParser* p){return p->expr();})
    );
  actionNode = out;
  return out;
}

void* ParserInstance::parse(std::function<void*(TMSlangParser*)> ruleFunc) {
  parsed = true;
  try {
    auto out = ruleFunc(&_parser);
    completed = true;
    return out;
  } catch (const ParseCancellationException& e) {
    try {
      std::rethrow_if_nested(e);
    } catch(const RecognitionException& e) {
      BailErrorStrategy().reportError(&_parser, e);
    }
  }
  return nullptr;
}
