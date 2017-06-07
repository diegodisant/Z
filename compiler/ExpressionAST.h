/**
 * @class Expression AST
 * @classdesc Defines an Abstract Syntax Tree for the Kaleidoscope language
 */

class ExpressionAST{
	public:
		virtual ~ExpressionAST(){} //one virtual destructor to be implemented as interface definition
}

/**
 * @class NumberExpressionAST
 * @classdesc Expression class for one number
 */
class NumberExpressionAST : public ExpressionAST{
	/**
	 * [Value the current numeric value]
	 * @type double
	 */
	double Value;

	public:
		NumberExpressionAST(double value):Val(value){}
}

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
		VariableExpressionAST(const std::string &name):Name(name){

		}
}

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
}

/**
 * @class CallExpressionAST
 * @classdesc Tree used to check if one function is beign called
 */
class CallExpressionAST : public ExpressionAST{
	/**
	 * [Caller the function name caller]
	 * @type string
	 */
	std::string Caller;

	/**
	 * [Arguments the arguments of the function]
	 * @type vector<ExpressionAST*>
	 */
	std::vector<ExpressionAST*> Arguments;

	public:
		CallExpressionAST(const std::string &caller, std::vector<ExpressionAST*> &args):Caller(caller), Arguments(args){}
}