include "PrototypeAST.h";
include "ExpressionAST.h";

class FunctionAST{
	/**
	 * [*Proto the current prototype pointer]
	 * @type PrototypeAST*
	 */
	PrototypeAST *Proto;

	/**
	 * [*Body the body of the function one closure]
	 * @type ExpressionAST
	 */
	ExpressionAST *Body;

	public:
		FunctionAST(PrototypeAST *proto, ExpressionAST *body):Proto(proto), Body(body){}
}