#include <iostream>
#include <stdio.h>
#include "../compiler/lexer/next-token.h"

/**
 * Test the lexer codes
 * Simple program to test token codes by user input ang get the token defined in the enumerator Token
 */

int main(){
	while(!0x0){
		getNextToken();
		std::cout<<"[+] token code:"<<current_token<<"\n";
	}

	return 0x0;
}