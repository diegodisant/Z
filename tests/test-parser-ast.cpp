#include <iostream>
#include "../compiler/parser/expr/VariableExpressionAST.h"
#include "../compiler/parser/expr/BinaryExpressionAST.h"

/**
 * Test the parser by creating tree nodes
 */
int main(){
	//create the variable x
	ExpressionAST *x = new VariableExpressionAST("x");

	//create the variable y
	ExpressionAST *y = new VariableExpressionAST("y");

	//sum the variable
	ExpressionAST *result = new BinaryExpressionAST('+', x, y); 

	return 0x0;
}