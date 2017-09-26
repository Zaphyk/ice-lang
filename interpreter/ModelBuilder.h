#pragma once
#include <vector>
#include <string>
#include "iostream"

class ModelBuilder
{
	public:

		void setup_basic(std::vector<std::string> &models, std::vector<void(*)(void *)> &actions);
		ModelBuilder();
		~ModelBuilder();
};

