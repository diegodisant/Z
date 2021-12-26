#include "./ExprAST.h"

using namespace std;

class FunctionAST : public ExprAST {
  std::unique_ptr<PrototypeAST> Prototype;
  std::unique_ptr<ExprAST> Body;

  public:
    FunctionAST(
      std::unique_ptr<PrototypeAST> Prototype,
      std::unique_ptr<ExprAST> Body
    ): Prototype(Prototype), Body(std::move(Body)) {}
}
