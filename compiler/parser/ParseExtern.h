#ifndef PARSE_EXTERN_H
#define PARSE_EXTERN_H

#include "ParsePrototype.h"

/**
 * [ParseExtern creates one empty prototype to call extern elements for the language]
 * @return [one empty prototype]
 */
static PrototypeAST *ParseExtern(){
	//eat the extern token
	getNextToken();

	return ParsePrototype(); //make one prototype to call one extern element
}

#endif