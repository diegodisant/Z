#ifndef HANDLE_DEF_H
#define HANDLE_DEF_H

#include "../ParseFunction.h"
#include "../ParsePrimary.h"

static void HandleDefinition(){
	if(current_token == tok_def){
		fprintf(stderr, "Parsed one function definition\n");
		ParseFunction();
	}
	else
		ParsePrimary();

	return;
}

#endif