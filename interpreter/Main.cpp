// Main.cpp : Defines the entry point for the console application.
//

#include "iostream"
#include <string>
#include "Lexer.h"
using namespace std;


int main()
{
	//Tools

	string ice_code = string("print ( ' HelloWorld ' ) ");

	Lexer* CodeLexer = new Lexer();

	vector<Token> tokens;
	string msg = CodeLexer->Process(ice_code, tokens);

	//if (msg == "SUCCESS" ) {
		for (int i = 0; i < tokens.size(); i++)
			cout << (CodeLexer->ParseToken(tokens[i]) + " ");
	//}
	//else {
	//	cout << msg;
	//}

	cin.get();

	return 0;
}

