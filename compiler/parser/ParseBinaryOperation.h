#ifndef PARSE_BIN_OP_H
#define PARSE_BIN_OP_H

#include "ParsePrimary.h"
#include "BinaryOperationPrecedence.h"
#include "expr/BinaryExpressionAST.h"

/**
 * [ParseBinaryOperation parse one binary operation by precedence]
 * @param  expr_precedence [the value of precedence]
 * @param  left_offset     [one pointer that manage the operator precedence]
 * @return                 [the left offset managed]
 *
 * This function can be used to parse the binary operation as the next way
 * [+, (x+y)], [*,w], etc.
 */
static ExpressionAST *ParseBinaryOperation(int expr_precedence, ExpressionAST *left_offset){
	while(true){
		//get the current token precedence
		int token_precedence = GetTokenpPrecedence();

		//if the token precedence is less than expression precedence, then return the offset
		if(token_precedence < expr_precedence)
			return left_offset;

		//get the binary operator
		int binary_operator = curren_token;

		//get the next binary operand
		getNextToken();

		//parse the expression
		ExpressionAST *right_offset = ParsePrimary();

		//check if have more tokens
		if(!right_offset) return 0;

		//check the next precedence
		//when have for example a + (b binop unparsed)
		//thus parse the next operation with one high level of precedence
		int next_precedence = GetTokenpPrecedence();
		if(token_precedence < next_precedence){
			right_offset = ParseBinaryOperation(token_precedence+1, right_offset);

			//if the right offset wasn't parsed correctly then return 0
			if(right_offset == 0) return 0;
		}


		left_offset = new BinaryExpressionAST(binary_operator, left_offset, right_offset);
	}
}

#endif