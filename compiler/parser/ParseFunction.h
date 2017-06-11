#ifndef PARSE_FUNCTION_H
#define PARSE_FUNCTION_H

#include "expr/FunctionAST.h"
#include "ParsePrototype.h"

/**
 * [ParseFunction parse the current function]
 * @return [FunctionAST the function parsed builded]
 */
static FunctionAST *ParseFunction(){
	//eat def string
	getNextToken();

	//get the current function prototype
	PrototypeAST *prototype = ParsePrototype();

	//check if the prototype is not valid
	if(prototype == 0) return 0;

	//check if the expression is valid
	if(ExpressionAST *expr = ParseExpression())
		return new FunctionAST(prototype, expr);

	return 0; //if the expression is not valid
}

#endif