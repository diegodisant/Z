#include "../parser/ExprAST.h"

using namespace std;

class ZLogger {
  public:
    std::unique_ptr<ExprAST> LogError(const char *message);
}
