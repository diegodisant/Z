#include "./TokenExtractor.cpp"

static int currentToken;

static int streamToken() {
  currentToken = extractToken();

  return currentToken;
}
