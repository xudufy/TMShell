
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

  virtual antlrcpp::Any visitClassDef(TMSlangParser::ClassDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassBody(TMSlangParser::ClassBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethod(TMSlangParser::MethodContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDecl(TMSlangParser::VariableDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormal(TMSlangParser::FormalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeName(TMSlangParser::TypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileExpr(TMSlangParser::WhileExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIDExpr(TMSlangParser::IDExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfExpr(TMSlangParser::IfExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrueExpr(TMSlangParser::TrueExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIsNullExpr(TMSlangParser::IsNullExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelExpr(TMSlangParser::RelExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultExpr(TMSlangParser::MultExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFullMethodCall(TMSlangParser::FullMethodCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddExpr(TMSlangParser::AddExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUMinusExpr(TMSlangParser::UMinusExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignExpr(TMSlangParser::AssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFalseExpr(TMSlangParser::FalseExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNullExpr(TMSlangParser::NullExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprList(TMSlangParser::ExprListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqExpr(TMSlangParser::EqExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelect(TMSlangParser::SelectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNewExpr(TMSlangParser::NewExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStrExpr(TMSlangParser::StrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNotExpr(TMSlangParser::NotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntExpr(TMSlangParser::IntExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLocalMethodCall(TMSlangParser::LocalMethodCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenExpr(TMSlangParser::ParenExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectAlt(TMSlangParser::SelectAltContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace tmshell
