#include "../common/common.h"
#include "../parser/TMSlang.h"
#include "ExecutionError.h"
#include "LoggedBaseVisitor.h"

using namespace tmshell;

void LoggedBaseVisitor::addLog(const std::string & msg) {
#ifdef TMSHELLD_OUTPUT_TO_CONSOLE
  std::cout<<msg<<std::endl;
#endif
  log += msg + "\n";
}

void LoggedBaseVisitor::error(antlr4::ParserRuleContext * context, const std::string & reason) {
  using namespace antlr4;
  auto l = context->stop->getLine();
  auto c = context->stop->getCharPositionInLine();
  throw ExecutionError(std::to_string(l) + ":" + std::to_string(c) + ":" + reason + "\n" 
    + getText(context) +"\n");
}

void LoggedBaseVisitor::error(antlr4::ParserRuleContext * context, const std::exception & e) {
  error(context, e.what());
}

std::string LoggedBaseVisitor::getText(antlr4::ParserRuleContext * context) {
  size_t a = context->start->getStartIndex();
  size_t b = context->stop->getStopIndex();
  context->getSourceInterval();
  antlr4::misc::Interval interval(a, b);
  std::string out = context->start->getInputStream()->getText(interval);
  return out;
}