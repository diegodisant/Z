#include <stdio.h>

#include "./ZLogger.h"

using namespace std;

std::unique_ptr<ExprAST> ZLogger::LogError(const char *message) {
  fprintf(
    stderr,
    "[+] ZError: %s \n",
    message
  );

  return nullptr;
}
