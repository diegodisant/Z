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
		NumberExpressionAST(double value):Value(value){}
};