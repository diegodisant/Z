#ifndef LOG_H
#define LOG_H

#include "../expr/FunctionAST.h"

ExpressionAST *Error(const char *current_string){
	fprintf(stderr, "Syntax Error: %s in line %d \n", current_string, readed_line);
	return 0;
}

PrototypeAST *ErrorPrototype(const char *current_string){
	Error(current_string);
	return 0;
}

FunctionAST *ErrorFunction(const char *current_string){
	Error(current_string);
	return 0;
}
#endif