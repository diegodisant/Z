#ifndef PARSE_NUM_EXPR_H
#define PARSE_NUM_EXPR_H

#include "expr/NumberExpression.h"

/**
 * [ParseNumberExpression parse one numberic expression]
 * @return [the expression in one ast node]
 *
 * The numeric expressions are the most simplest to process in one compiler
 */
static ExpressionAST *ParseNumberExpression(){
	//creates one ast node
	ExpressionAST *result = new NumberExpression(number_value);

	//get the next token that will be processed
	getNextToken();

	//make one new node for the AST
	return result;
} 
#endif