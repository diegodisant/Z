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
};