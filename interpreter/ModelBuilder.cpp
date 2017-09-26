#include "ModelBuilder.h"

void print_val(void *data) {
	std::string *val = static_cast<std::string*>(data);
	std::cout << *val;
}

void print_val_line(void *data) {
	std::string *val = static_cast<std::string*>(data);
	std::cout << *val << std::endl;
}

void create_var_int(void *data) {
	int var = *( (int *) data);
}


void ModelBuilder::setup_basic(std::vector<std::string> &models, std::vector<void (*) (void *)> &actions, std::vector<void*> &variables) {

	models.push_back("int ? '?'");
	actions.push_back(&create_var);

	//Add both variations of the function call
	models.push_back("print: '?'");
	actions.push_back( &print_val );
	models.push_back("print: \"?\"");
	actions.push_back(&print_val);

	//Add both variations of the function call
	models.push_back("print_line: '?'");
	actions.push_back( &print_val_line );
	models.push_back("print_line: \"?\"");
	actions.push_back(&print_val_line);
}


ModelBuilder::ModelBuilder(){}

ModelBuilder::~ModelBuilder(){}
