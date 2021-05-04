#pragma once
#include "../common/common.h"
#include "LoggedBaseVisitor.h"
#include "VariableValue.h"
#include "ScopeManager.h"
#include "BuiltinFunc.h"

namespace tmshell {

//out: return the log of this run;
std::string runAction(std::string const & action);

class ActionExecutor : public BaseExecutor {
public:
  friend std::string runAction(std::string const &);

  virtual antlrcpp::Any visitProgram(TMSlangParser::ProgramContext *context);

  virtual antlrcpp::Any visitExecute_line(TMSlangParser::Execute_lineContext *context);

  virtual antlrcpp::Any visitMgmt_command(TMSlangParser::Mgmt_commandContext *context) ;

  virtual antlrcpp::Any visitQuotedArg(TMSlangParser::QuotedArgContext *context) ;

  virtual antlrcpp::Any visitPlainArg(TMSlangParser::PlainArgContext *context) ;

  virtual antlrcpp::Any visitSessionVarDef(TMSlangParser::SessionVarDefContext *context) ;

  virtual antlrcpp::Any visitGlobalVarDef(TMSlangParser::GlobalVarDefContext *context) ;

  virtual antlrcpp::Any visitTriggerDef(TMSlangParser::TriggerDefContext *context) ;

  virtual antlrcpp::Any visitMulExpr(TMSlangParser::MulExprContext *context) ;

  virtual antlrcpp::Any visitIDExpr(TMSlangParser::IDExprContext *context) ;

  virtual antlrcpp::Any visitBoolExpr(TMSlangParser::BoolExprContext *context) ;

  virtual antlrcpp::Any visitEqlExpr(TMSlangParser::EqlExprContext *context) ;

  virtual antlrcpp::Any visitIfExpr(TMSlangParser::IfExprContext *context) ;

  virtual antlrcpp::Any visitRelExpr(TMSlangParser::RelExprContext *context) ;

  virtual antlrcpp::Any visitLogicExpr(TMSlangParser::LogicExprContext *context) ;

  virtual antlrcpp::Any visitPeriodicExpr(TMSlangParser::PeriodicExprContext *context) ;

  virtual antlrcpp::Any visitNegExpr(TMSlangParser::NegExprContext *context) ;

  virtual antlrcpp::Any visitAddExpr(TMSlangParser::AddExprContext *context) ;

  virtual antlrcpp::Any visitDurationLExpr(TMSlangParser::DurationLExprContext *context) ;

  virtual antlrcpp::Any visitAssignExpr(TMSlangParser::AssignExprContext *context) ;

  virtual antlrcpp::Any visitGroupExpr(TMSlangParser::GroupExprContext *context) ;

  virtual antlrcpp::Any visitTimePointLExpr(TMSlangParser::TimePointLExprContext *context) ;

  virtual antlrcpp::Any visitStringLExpr(TMSlangParser::StringLExprContext *context) ;

  virtual antlrcpp::Any visitLaterExpr(TMSlangParser::LaterExprContext *context) ;

  virtual antlrcpp::Any visitCurrentExpr(TMSlangParser::CurrentExprContext *context) ;

  virtual antlrcpp::Any visitIntLExpr(TMSlangParser::IntLExprContext *context) ;

  virtual antlrcpp::Any visitLocalVarDefExpr(TMSlangParser::LocalVarDefExprContext *context) ;

  virtual antlrcpp::Any visitCallExpr(TMSlangParser::CallExprContext *context) ;

  virtual antlrcpp::Any visitNotExpr(TMSlangParser::NotExprContext *context) ;

  virtual antlrcpp::Any visitFieldExpr(TMSlangParser::FieldExprContext *context) ;

  virtual antlrcpp::Any visitParanExpr(TMSlangParser::ParanExprContext *context);

};


} // namespace tmshell