#ifndef BINARY_EXPR_AST_H
#define BINARY_EXPR_AST_H

#include "ExpressionAST.h"

/**
 * @class BinaryExpressionAST
 * @classdesc Process one operator to with to operands
 */
class BinaryExpressionAST : public ExpressionAST{
	/**
	 * [operation the current operation symbol]
	 * @type char
	 */
	char Operation;

	/**
	 * [left_offset the previous tree to process]
	 * @type ExpressionAST
	 */
	ExpressionAST *Left_offset;

	/**
	 * [right offset the next tree to process]
	 */
	ExpressionAST *Right_offset;

	public:
		BinaryExpressionAST(char op, ExpressionAST *lo, ExpressionAST *ro):Operation(op), Left_offset(lo), Right_offset(ro){}
};

#endif