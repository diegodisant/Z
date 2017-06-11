#ifndef PARSE_EXPR_H
#define PARSE_EXPR_H

#include "ParsePrimary.h"
#include "ParseBinaryOperation.h"

/**
 * [ParseExpression check if need to eval the current operation]
 * @return [one call to other parse operations of one parse to binary operation]
 */
static ExpressionAST *ParseExpression(){
	//get the left offset of one binary operation
	ExpressionAST *left_offset = ParsePrimary();

	if(!left_offset) return 0;

	return ParseBinaryOperation(0, left_offset);
}

#endif