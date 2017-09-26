#include "Interpreter.h"
#include "Utils.h"
#include <vector>


Interpreter::Interpreter() {
	
	Interpreter::Builder->setup_basic(models, actions);
}

int Interpreter::Process(const std::string &script) {

	std::vector<std::string> lines;
	split(script, lines, ';');
		
	for(int k = 0; k < lines.size(); k++){
		std::string input = lines[k];
		if (input.size() == 0) continue;

		for (int i = 0; i < models.size(); i++) {

			std::string chr = models[i].substr(models[i].find('?') - 1, 1);

			std::string firstPart = input.substr(0, input.find(chr));
			std::string value = input.substr(firstPart.size() + 1, input.substr(firstPart.size() + 1, input.size() - firstPart.size()).find(chr));
			if (firstPart == models[i].substr(0, models[i].find(chr))) {

				actions[i](&value);
			}
		}
	}
	return 1;
}


Interpreter::~Interpreter() {

}
