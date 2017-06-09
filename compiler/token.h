/**
 * @enum Token
 * @desc This class defines one token denition code, using negative to avoid ascii character override
 */
enum Token {
	tok_eof = -1,
	tok_def = -2,
	tok_extern = -3,
	tok_identifier = -4,
	tok_number = -5
};

static std::string identifier_str; //used to fill with id_type
static double number_value; //used to fill with one numbers