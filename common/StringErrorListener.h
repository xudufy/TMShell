#pragma once

#include <antlr4-runtime.h>

namespace tmshell{

using namespace antlr4;
class StringErrorListener: public antlr4::BaseErrorListener{
public:
    std::string msg;
    std::string offendingToken;
    bool meetError = false;

    virtual void syntaxError(Recognizer *, Token * offendingSymbol, size_t line, size_t charPositionInLine,
      const std::string &msg, std::exception_ptr e) override {
        this->msg = std::to_string(line) + ":" + std::to_string(charPositionInLine) + ":" + msg;
        meetError = true;
        offendingToken = offendingSymbol->getText();
      }

    void reset() {
      meetError = false;
      msg.clear();
      offendingToken.clear();
    }
};

}