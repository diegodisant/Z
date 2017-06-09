#include "token.h"

static int readed_line = 0;

/**
 * [getToken get the next token code defined in token.h]
 * @return char [one character in ascii or one token code]
 */
static int getToken(){
	static int last_char = '\0';

	//skip the white spaces
	while(isspace(last_char))
		last_char = getchar();

	//verify if the current character is one string [a-zA-Z][a-zA-Z0-9]*
	if(isalpha(last_char)){
		identifier_str = last_char;

		//while the next char is one alphanumeric then 
		while(isalnum(last_char = getchar()))
			identifier_str += last_char;

		//verify the strings if the current token is a def instruction of extern
		if(identifier_str == "def") return tok_def;
		else if(identifier_str == "extern") return tok_extern;

		return tok_identifier;
	}

	//verify if is one number or one point [0-9\.]+
	if(isdigit(last_char) || last_char == '.'){
		std::string number_str;

		do{
			//concat the last char
			number_str += last_char;
			//get the input
			last_char = getchar();
		}while(isdigit(last_char) || last_char == '.');

		/**
		 * Transform the current string to c string representation,
		 * and cast to double
		 */
		number_value = strtod(number_str.c_str(), 0);

		return tok_number;
	}

	//verify one comment token
	if(last_char == '#'){
		//get the next char
		do last_char = getchar();
		while(last_char != EOF 
			&& last_char != '\n' 
			&& last_char != '\r');

		if(last_char != EOF)
			return getToken();
	}

	//increase the line counter
	if(last_char == '\n'
		|| last_char == '\r')
		++readed_line;

	//verify the end of the file and return the token
	if(last_char == EOF)
		return tok_eof;

	//if the character doesn't match in the cases then transform it into ascii
	//just when is a symbol like (+,-,*,/)
	int tmp_char = last_char;
	//continue reading new characters
	last_char = getchar();
	return tmp_char;
}