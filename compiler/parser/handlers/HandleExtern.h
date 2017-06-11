#ifndef HANDLE_EXTERN_H
#define HANDLE_EXTERN_H

#include "../ParseExtern.h"

static void HandleExtern(){
	fprintf(stderr, "Parsed an extern call \n");
	ParseExtern();
	return;
}

#endif