#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "../compiler/next-token.h"

/**
 * Test the lexer codes
 */

int main(){
	while(!0x0){
		getNextToken();
		std::cout<<"[+] token code:"<<current_token<<"\n";
	}

	return 0x0;
}