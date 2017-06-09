/**
 * [current_token the current token beign procesed]
 * @type int
 */
static int current_token;

/**
 * [getNextToken return the next token]
 */
static int getNextToken(){
	return current_token = getToken();
}

