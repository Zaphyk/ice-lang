// Main.cpp : Defines the entry point for the console application.
//

#include "iostream"
#include <string>
#include "Interpreter.h"
using namespace std;


int main()
{
	//Tools

	string ice_code = "let a = 0;print: 'Hey cowboy';";

	Interpreter* CodeInterpreter = new Interpreter();

	int result = CodeInterpreter->Process(ice_code);
	if (result == 0) cout << "SYNTAX ERROR";

	cin.get();

	return 0;
}

