// Main.cpp : Defines the entry point for the console application.
//

#include "iostream"
#include <string>
#include "Lexer.h"
using namespace std;


int main()
{
	//Tools

	string ice_code = "print('Hello World')";

	Lexer* CodeLexer = new Lexer();
	
	vector<Token> tokens;
	CodeLexer->Process( ice_code, tokens );

	cout << ice_code;
	cin.get();

	return 0;
}

