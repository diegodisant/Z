include "ExpressionAST.h";

/**
 * @class VariableExpressionAST
 * @classdesc Checks one expression of variable type that match with ^[a-zA-Z][0-9]+
 */
class VariableExpressionAST : public ExpressionAST{
	/**
	 * [Name the current variable name]
	 * @type string (std)
	 */
	std::string Name;

	public:
		VariableExpressionAST(const std::string &name):Name(name){}
}