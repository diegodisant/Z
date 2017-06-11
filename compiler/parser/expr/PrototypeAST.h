#ifndef PROTOTYPE_AST_H
#define PROTOTYPE_AST_H

/**
 * @class PrototypeAST
 * @classdesc Is the representation of one prototype for a function, 
 * thus captures its name and determine the number of arguments taken
 * by the function
 */

class PrototypeAST{
	/**
	 * [Name the function name]
	 * @type string
	 */
	std::string Name;

	/**
	 * [Arguments the arguments of the function]
	 */
	std::vector<std::string> Arguments;

	public: 
		PrototypeAST(const std::string &name, const std::vector<std::string> &args):Name(name), Arguments(args){}
};
#endif