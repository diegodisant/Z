#ifndef PARSE_ID_EXPR_H
#define PARSE_ID_EXPR_H

#include "utils/log.h"
#include "expr/VariableExpressionAST.h"
#include "expr/CallExpressionAST.h"
#include "ParseExpression.h"

/**
 * [ParseIdentifierExpression parse one expression that contains one identifier or variable name]
 * @return [One varialbe expression or call expression if is one function]
 */
static ExpressionAST ParseIdentifierExpression(){
	std::string identifier_name = identifier_str;

	//get the next token in the current buffer
	getNextToken();

	//check if the current token doesn't contain a call
	if(current_token != '(') return new VariableExpressionAST(identifier_name);

	/**
	 * DEFINITION FOR ONE CALL BLOCK
	 */

	//define the list of arguments
	std::vector<ExpressionAST*> arguments;

	if(current_token != ')'){
		while(true){
			//parse the argument expression
			ExpressionAST *argument = ParseExpression();

			// check if there is arguments in the function
			if(!argument) return 0;

			//add one argument if exists
			arguments.push(argument);

			//break the execution flow if the token is one right parent
			if(current_token == ')') break;

			//check if the separator of the parameters are divided by comma character
			if(current_token != ',')
				return Error("Expected ')' or ',' to close the call to function");
		} 
	}

	//get the final token to iterate the last char )
	getNextToken();

	//create one new call expression with the arguments
	return new CallExpressionAST(identifier_name, arguments);
}
#endif