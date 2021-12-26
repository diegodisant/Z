#include "./ExprAST.h"

using namespace std;

class BinaryExprAST : public ExprAST {
  char Operator;

  std::unique_ptr<ExprAST> LHS;

  std::unique_ptr<ExprAST> RHS;

  public:
    BinaryExprAST(
      char operator,
      std::unique_ptr<ExprAST> LHS,
      std::unique_ptr<ExprAST> RHS
    ) : Operator(Operator), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
}
