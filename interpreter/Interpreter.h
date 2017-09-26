#pragma once

#include <vector>
#include "ModelBuilder.h"

class Interpreter
{
public:

	ModelBuilder* Builder = new ModelBuilder();
	std::vector<std::string> models;
	std::vector<void(*)(void *)> actions;
	std::vector<void*> variables;

	Interpreter();

	virtual ~Interpreter();

	int Process(const std::string &input);
};

