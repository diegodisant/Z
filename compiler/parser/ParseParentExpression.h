#ifndef PARSE_PARENT_EXPR_H
#define PARSE_PARENT_EXPR_H

#include "utils/log.h"
#include "ParseExpression.h"

/**
 * [ParseParentExpression parses the parent expression located in ()]
 * @return [one AST node that is instance of ExpressionAST]
 */
static ExpressionAST *ParseParentExpression(){
	getNextToken();

	//create one expression ast 
	ExpressionAST *current_expr = ParseExpression();

	//if the current expression is valid
	if(!current_expr) return 0;

	//if the current token is not one enclosure then return one error
	if(current_token != ')')
		return Error("Expected ) at the end of line");

	//ge the next token and return the next parameter separated by comma
	getNextToken();

	//returns the current expression
	return current_expr;
}
#endif