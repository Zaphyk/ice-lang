#pragma once

#include <vector>

enum Token { IDENTIFIER, LEFT_PARENTHESIS, RIGHT_PARENTHESIS, STATEMENT_END, COMMA };

class Lexer
{
	public:
		std::vector<std::string> identifiers;

		Lexer();

		virtual ~Lexer();

		std::string Process(const std::string &input, std::vector<Token> &out);
		std::string ParseToken(Token &t);
};

