#ifndef PARSE_EXTERN_H
#define PARSE_EXTERN_H

#include "ParsePrototype.h"

static PrototypeAST *ParseExtern(){
	//eat the extern token
	getNextToken();

	return ParsePrototype();
}

#endif