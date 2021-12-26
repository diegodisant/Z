#include "./ExprAST.h"

class NumberExprAST : public ExprAST {
  double Value;

  public:
    NumberExprAST(double Value) : Value(Value) {}
}
