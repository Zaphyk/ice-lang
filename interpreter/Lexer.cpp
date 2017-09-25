#include "Lexer.h"
#include "Utils.h"
#include <vector>


Lexer::Lexer() {
	identifiers.push_back("print");
}

std::string Lexer::Process(const std::string &input, std::vector<Token> &out) {

	std::vector<std::string> parts;
	split(input, parts, ' ');

	for (int i = 0; i < parts.size(); i++) {

		if (parts[i] == ",")
			out.push_back(Token::COMMA);

		else if (parts[i] == "(")
			out.push_back(Token::LEFT_PARENTHESIS);

		else if (parts[i] == ",")
			out.push_back(Token::RIGHT_PARENTHESIS);

		else if (parts[i] == "\r\n")
			out.push_back(Token::STATEMENT_END);

		else {
			bool IsKnown = false;
			for (int k = 0; k < identifiers.size(); k++) {
				if (identifiers[k] == parts[i]) {
					out.push_back(Token::IDENTIFIER);
					IsKnown = true;
					break;
				}
			}

			if(!IsKnown) return std::string("UNKOWN ITEM " + parts[i]);
		}

	}

	return std::string("SUCCESS");
}

std::string Lexer::ParseToken(Token &t) {
	switch (t)
	{
		case IDENTIFIER:
			return "IDENTIFIER";
	
		case LEFT_PARENTHESIS:
			return "LEFT_PARENTHESIS";

		case RIGHT_PARENTHESIS:
			return "RIGHT_PARENTHESIS";

		case STATEMENT_END:
			return "STATEMENT_END";

		case COMMA:
			return "COMMA";

		default:
			return "UNKOWN";
	}
}


Lexer::~Lexer(){

}
