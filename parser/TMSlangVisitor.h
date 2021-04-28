
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

    virtual antlrcpp::Any visitExecute_line(TMSlangParser::Execute_lineContext *context) = 0;

    virtual antlrcpp::Any visitMgmt_command(TMSlangParser::Mgmt_commandContext *context) = 0;

    virtual antlrcpp::Any visitQuotedArg(TMSlangParser::QuotedArgContext *context) = 0;

    virtual antlrcpp::Any visitPlainArg(TMSlangParser::PlainArgContext *context) = 0;

    virtual antlrcpp::Any visitSessionVarDef(TMSlangParser::SessionVarDefContext *context) = 0;

    virtual antlrcpp::Any visitGlobalVarDef(TMSlangParser::GlobalVarDefContext *context) = 0;

    virtual antlrcpp::Any visitTriggerDef(TMSlangParser::TriggerDefContext *context) = 0;

    virtual antlrcpp::Any visitMulExpr(TMSlangParser::MulExprContext *context) = 0;

    virtual antlrcpp::Any visitIDExpr(TMSlangParser::IDExprContext *context) = 0;

    virtual antlrcpp::Any visitEqlExpr(TMSlangParser::EqlExprContext *context) = 0;

    virtual antlrcpp::Any visitIfExpr(TMSlangParser::IfExprContext *context) = 0;

    virtual antlrcpp::Any visitRelExpr(TMSlangParser::RelExprContext *context) = 0;

    virtual antlrcpp::Any visitPeriodicExpr(TMSlangParser::PeriodicExprContext *context) = 0;

    virtual antlrcpp::Any visitAddExpr(TMSlangParser::AddExprContext *context) = 0;

    virtual antlrcpp::Any visitDurationLExpr(TMSlangParser::DurationLExprContext *context) = 0;

    virtual antlrcpp::Any visitAssignExpr(TMSlangParser::AssignExprContext *context) = 0;

    virtual antlrcpp::Any visitGroupExpr(TMSlangParser::GroupExprContext *context) = 0;

    virtual antlrcpp::Any visitTimePointLExpr(TMSlangParser::TimePointLExprContext *context) = 0;

    virtual antlrcpp::Any visitStringLExpr(TMSlangParser::StringLExprContext *context) = 0;

    virtual antlrcpp::Any visitLaterExpr(TMSlangParser::LaterExprContext *context) = 0;

    virtual antlrcpp::Any visitCurrentExpr(TMSlangParser::CurrentExprContext *context) = 0;

    virtual antlrcpp::Any visitIntLExpr(TMSlangParser::IntLExprContext *context) = 0;

    virtual antlrcpp::Any visitLocalVarDefExpr(TMSlangParser::LocalVarDefExprContext *context) = 0;

    virtual antlrcpp::Any visitCallExpr(TMSlangParser::CallExprContext *context) = 0;

    virtual antlrcpp::Any visitFieldExpr(TMSlangParser::FieldExprContext *context) = 0;


};

}  // namespace tmshell
