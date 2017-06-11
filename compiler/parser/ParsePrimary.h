#ifndef PARSE_PRIMARY_H
#define PARSE_PRIMARY_H

#include "ParseIdentifierExpression.h"
#include "ParseNumberExpression.h"
#include "ParseParentExpression.h"

/**
 * [ParsePrimary parse one expression by checking the type of the current token]
 * @return [the current expression]
 */
static ExpressionAST *ParsePrimary(){
	switch(current_token){
		default:
			return Error("Unkown token when one expression is expected");
		case tok_identifier:
			return ParseIdentifierExpression();
		case tok_number:
			return ParseNumberExpression();
		case '(':
			return ParseParentExpression();
	}
}
#endif