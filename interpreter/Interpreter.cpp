#include "Interpreter.h"
#include "Utils.h"
#include <vector>
#include <algorithm>


Interpreter::Interpreter() {
	
	Interpreter::Builder->setup_basic(models, actions, variables);
}

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
	if (from.empty())
		return;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
	}
}

int Interpreter::Process(const std::string &script) {

	std::vector<std::string> lines;
	split(script, lines, ';');
		
	for(int k = 0; k < lines.size(); k++){
		std::string input = lines[k];
		if (input.size() == 0) continue;

		for (int i = 0; i < models.size(); i++) {

			//std::string chr = models[i].substr(models[i].find('?') - 1, 1);
			bool Success = false;
			void *value;
			
			for (int j = 0; j < input.length(); j++){
				
				if(models[i][j] != '*' && models[i][j] != '?'){
					if (input[j] != models[i][j]) break;
				}
				else {
					if (models[i][j] == '?') {
						
						if (input[j] != ' ') break;
					}
					else if (models[i][j] == '*') {
						
						std::string firstPart = input.substr(0, j-1);
						std::string str_val = input.substr(firstPart.size() + 1, input.substr(firstPart.size() + 1, input.size() - firstPart.size()).find(models[i][j-1]));

						actions[i](&str_val);
						
						Success = true;
						break;
					}
				}
			}
		}
	}
	return 1;
}


Interpreter::~Interpreter() {

}
