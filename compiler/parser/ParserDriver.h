#ifndef PARSER_DRIVER_H
#define PARSER_DRIVER_H

/**
 * [ParserDriver iterates the tokens and handle the operation for each]
 */
static void ParserDriver(){
	while(true){
		fprintf(stderr, "parser.ready>");

		switch(current_token){
			case tok_eof: //if the current token is one End Of File then make a void return
				return;
			case ';': //if current token is one semicolon then ignore and thet the next token
				getNextToken();
				break;
			case tok_def:
				HandleDefinition();
				break;
			case tok_extern:
				HandleExtern();
				break;
			//if the current token is not identified then is a top level expression
			default:
				HandleTopLevelExpression();
				break;
		}
	}
}
#endif