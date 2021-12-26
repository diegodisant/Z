#include "../../lexer/Token.cpp"
#include "../../lexer/TokenExtractor.cpp"

#include "../AST/Expr/ExprAST.h"
#include "../AST/Expr/NumberExprAst.cpp"

using namespace std;

extern static double numbervalue;

static std::unique_ptr<ExprAST> ParseNumberExpr() {
  auto exprResult = std::make_unique<NumberExprAST>(numbervalue);

  extractToken();

  return std::move(exprResult);
}
