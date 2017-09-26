#pragma once

#include <vector>

class Interpreter
{
public:

	std::vector<std::string> models;
	std::vector<void(*)()> actions;

	Interpreter();

	virtual ~Interpreter();

	int Process(const std::string &input);
};

