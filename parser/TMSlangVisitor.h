
// Generated from C:/projects/TMShell/grammar/TMSlang.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "TMSlangParser.h"


namespace tmshell {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by TMSlangParser.
 */
class  TMSlangVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by TMSlangParser.
   */
    virtual antlrcpp::Any visitProgram(TMSlangParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitClassDef(TMSlangParser::ClassDefContext *context) = 0;

    virtual antlrcpp::Any visitClassBody(TMSlangParser::ClassBodyContext *context) = 0;

    virtual antlrcpp::Any visitMethod(TMSlangParser::MethodContext *context) = 0;

    virtual antlrcpp::Any visitVariableDecl(TMSlangParser::VariableDeclContext *context) = 0;

    virtual antlrcpp::Any visitFormal(TMSlangParser::FormalContext *context) = 0;

    virtual antlrcpp::Any visitTypeName(TMSlangParser::TypeNameContext *context) = 0;

    virtual antlrcpp::Any visitWhileExpr(TMSlangParser::WhileExprContext *context) = 0;

    virtual antlrcpp::Any visitIDExpr(TMSlangParser::IDExprContext *context) = 0;

    virtual antlrcpp::Any visitIfExpr(TMSlangParser::IfExprContext *context) = 0;

    virtual antlrcpp::Any visitTrueExpr(TMSlangParser::TrueExprContext *context) = 0;

    virtual antlrcpp::Any visitIsNullExpr(TMSlangParser::IsNullExprContext *context) = 0;

    virtual antlrcpp::Any visitRelExpr(TMSlangParser::RelExprContext *context) = 0;

    virtual antlrcpp::Any visitMultExpr(TMSlangParser::MultExprContext *context) = 0;

    virtual antlrcpp::Any visitFullMethodCall(TMSlangParser::FullMethodCallContext *context) = 0;

    virtual antlrcpp::Any visitAddExpr(TMSlangParser::AddExprContext *context) = 0;

    virtual antlrcpp::Any visitUMinusExpr(TMSlangParser::UMinusExprContext *context) = 0;

    virtual antlrcpp::Any visitAssignExpr(TMSlangParser::AssignExprContext *context) = 0;

    virtual antlrcpp::Any visitFalseExpr(TMSlangParser::FalseExprContext *context) = 0;

    virtual antlrcpp::Any visitNullExpr(TMSlangParser::NullExprContext *context) = 0;

    virtual antlrcpp::Any visitExprList(TMSlangParser::ExprListContext *context) = 0;

    virtual antlrcpp::Any visitEqExpr(TMSlangParser::EqExprContext *context) = 0;

    virtual antlrcpp::Any visitSelect(TMSlangParser::SelectContext *context) = 0;

    virtual antlrcpp::Any visitNewExpr(TMSlangParser::NewExprContext *context) = 0;

    virtual antlrcpp::Any visitStrExpr(TMSlangParser::StrExprContext *context) = 0;

    virtual antlrcpp::Any visitNotExpr(TMSlangParser::NotExprContext *context) = 0;

    virtual antlrcpp::Any visitIntExpr(TMSlangParser::IntExprContext *context) = 0;

    virtual antlrcpp::Any visitLocalMethodCall(TMSlangParser::LocalMethodCallContext *context) = 0;

    virtual antlrcpp::Any visitParenExpr(TMSlangParser::ParenExprContext *context) = 0;

    virtual antlrcpp::Any visitSelectAlt(TMSlangParser::SelectAltContext *context) = 0;


};

}  // namespace tmshell
