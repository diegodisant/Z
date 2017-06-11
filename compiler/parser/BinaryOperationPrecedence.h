#ifndef BINARY_OP_PRECEDENCE_H
#define BINARY_OP_PRECEDENCE_H

#include "utils/constants.h"

/**
 * [binary_precedence structure used to map the binary precedence]
 * @type map<char,int>
 */
static std::map<char,int> binary_precedence;

//define the binary operators
//@TODO extend the language implementing other operators like >, /, % and logic operators like &,|, &&, ||, ~, >>, <<
binary_precedence['<'] = 10;
binary_precedence['+'] = 20;
binary_precedence['-'] = 20;
binary_precedence['*'] = 40;

/**
 * The kaleidoscope language just support
 * four operations +,*,-,<
 */

/**
 * [GetTokenPrecedence return the token pr]
 * @return [description]
 */
static int GetTokenPrecedence(){
	//check if the current token is in ascii encode
	if(!isascii(current_token))
		return NOT_IS_OPERATOR;

	//check if the current token is one binary operation
	int token_precedence = binary_precedence[current_token];

	if(token_precedence < 0)
		return NOT_IS_OPERATOR;

	return token_precedence;
}
#endif