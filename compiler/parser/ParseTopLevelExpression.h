#ifndef PARSE_TOP_LVL_EXPR_H
#define PARSE_TOP_LVL_EXPR_H
	
#include "expr/FunctionAST.h"
#include "ParseExpression.h"

/**
 * [ParseTopLevelExpression parse a top level expression like nested functions]
 * @return [one function expressio]
 */
static FunctionAST *ParseTopLevelExpression(){
	if(ExpressionAST *expr = ParseExpression()){
		//make one anonymous prototype
		PrototypeAST *prototype = new PrototypeAST("", std::vector<std::string>());
		
		//return the function
		return new FunctionAST(prototype, expr);
	}
	return 0; //if there is no more expressions or functions
}

#endif