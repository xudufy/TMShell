
// Generated from C:/projects/TMShell/grammar/TMSlang.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "TMSlangVisitor.h"


namespace tmshell {

/**
 * This class provides an empty implementation of TMSlangVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  TMSlangBaseVisitor : public TMSlangVisitor {
public:

  virtual antlrcpp::Any visitProgram(TMSlangParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExecute_line(TMSlangParser::Execute_lineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMgmt_command(TMSlangParser::Mgmt_commandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuotedArg(TMSlangParser::QuotedArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPlainArg(TMSlangParser::PlainArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSessionVarDef(TMSlangParser::SessionVarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGlobalVarDef(TMSlangParser::GlobalVarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTriggerDef(TMSlangParser::TriggerDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulExpr(TMSlangParser::MulExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIDExpr(TMSlangParser::IDExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolExpr(TMSlangParser::BoolExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqlExpr(TMSlangParser::EqlExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfExpr(TMSlangParser::IfExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelExpr(TMSlangParser::RelExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicExpr(TMSlangParser::LogicExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPeriodicExpr(TMSlangParser::PeriodicExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNegExpr(TMSlangParser::NegExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddExpr(TMSlangParser::AddExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDurationLExpr(TMSlangParser::DurationLExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignExpr(TMSlangParser::AssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGroupExpr(TMSlangParser::GroupExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimePointLExpr(TMSlangParser::TimePointLExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringLExpr(TMSlangParser::StringLExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLaterExpr(TMSlangParser::LaterExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCurrentExpr(TMSlangParser::CurrentExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntLExpr(TMSlangParser::IntLExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLocalVarDefExpr(TMSlangParser::LocalVarDefExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallExpr(TMSlangParser::CallExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNotExpr(TMSlangParser::NotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFieldExpr(TMSlangParser::FieldExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace tmshell
