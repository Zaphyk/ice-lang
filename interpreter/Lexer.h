#pragma once

#include <vector>

enum Token { IDENTIFIER, LEFT_PARENTHESIS, RIGHT_PARENTHESIS, STATEMENT_END, COMMA };

class Lexer
{
	public:

		Lexer();

		virtual ~Lexer();

		int Process(const std::string &input, std::vector<Token> &out);
};

