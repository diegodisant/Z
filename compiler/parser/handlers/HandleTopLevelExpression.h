#ifndef HANDLE_TOP_LVL_EXP_H
#define HANDLE_TOP_LVL_EXP_H

#include "../ParseTopLevelExpression.h"

/**
 * [HandleTopLevelExpression handle a top level expression]
 */
static void HandleTopLevelExpression(){
	fprintf(stderr, "Parsed a top level expression");
	ParseTopLevelExpression();
	return;
}

#endif