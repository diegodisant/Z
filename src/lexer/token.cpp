using namespace std;

enum Token {
  TOKEN_EOF = -1,
  TOKEN_DEF = -2,
  TOKEN_EXTERN = -3,
  TOKEN_IDENTIFIER = -4,
  TOKEN_NUMBER = 5
};

static std::string stringIdentifier;
static double numbervalue;
