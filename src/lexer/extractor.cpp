#include <stdio.h>
#include <ctype.h>

#include "./token.cpp"

using namespace std;

extern static std::string stringIdentifier;
extern static double numbervalue;

static int extractToken() {
  static int lastCharacter = ' ';

  for (;isspace(lastCharacter);) {
    lastCharacter = getchar();

    if (isalpha(lastCharacter)) {
      return extractAlpha(lastCharacter);
    }

    if (isdigit(lastCharacter) || lastCharacter == '.') {
      return extractNumber(lastCharacter);
    }

    if (lastCharacter == '#') {
      return ignoreComment();
    }

    if (lastCharacter == EOF) {
      return TOKEN_EOF;
    }

    int prevLastCharacter = lastCharacter;
    lastCharacter = getchar();

    return prevLastCharacter;
  }
}

static int extractAlpha(int &lastCharacter) {
  stringIdentifier = lastCharacter;

  for (
    lastCharacter = getchar();
    isalnum(lastCharacter);
  ) {
    lastCharacter = getchar();
    stringIdentifier += lastCharacter;
  }

  if (stringIdentifier == "def") {
    return TOKEN_DEF;
  }

  if (stringIdentifier == "extern") {
    return TOKEN_EXTERN;
  }

  return TOKEN_IDENTIFIER;
}

static int extractNumber(int &lastCharacter) {
  static std::string numberString;

  for (;;) {
    numberString += lastCharacter;
    lastCharacter = getchar();

    if (!isDigit(lastCharacter) && lastCharacter != '.') {
      break;
    }
  }

  numberValue = strod(numberString.c_str(), 0);

  return TOKEN_NUMBER;
}

static int ignoreComment(int &lastCharacter) {
  for (;;) {
    lastCharacter = getchar();

    if (
      lastCharacter == EOF ||
      lastCharacter == '\n' ||
      lastCharacter == '\r'
    ) {
      break;
    }
  }

  if (lastCharacter != EOF) {
    return streamToken();
  }
}
