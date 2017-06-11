#ifndef PARSE_PROTOTYPE_H
#define PARSE_PROTOTYPE_H

#include "expr/PrototypeAST.h"
#include "utils/log.h"

/**
 * [ParsePrototype parse the rest in a body definition]
 * @return [one PrototypeAST to parse]
 */
static PrototypeAST *ParsePrototype(){
	//check if the current token is differente of identifier
	if(current_token != tok_identifier)
		return ErrorPrototype("Expected the function name in prototype");

	//get the function name
	std::string function_name = identifier_str;
	getNextToken(); //get the parent char

	if(current_token != '(')
		return ErrorPrototype("Expected '(' to call one function");

	//read the argument names list
	std::vector<std::string> argument_names;

	//iterate the argument list
	while(getNextToken() == tok_identifier)
		argument_names.push(identifier_str);

	if(current_token != ')')
		return ErrorPrototype("Expected ')' in prototype");

	//if all success then eat the ) character
	getNextToken();

	return new PrototypeAST(function_name, argument_names);
}

#endif