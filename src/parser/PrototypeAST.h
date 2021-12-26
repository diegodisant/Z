#include "./ExprAST.h"

using namespace std;

class PrototypeAST {
  std::string Name;
  std::vector<std::string> Args;

  public:
    PrototypeAST(
      const std::string &name,
      std::vector<std::string> Args
    ): Name(Name), Args(std::move(Args)) {}
}
