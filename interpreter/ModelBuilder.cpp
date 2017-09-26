#include "ModelBuilder.h"

void print_val(void *data) {
	std::string *val = static_cast<std::string*>(data);
	std::cout << *val;

	//delete val;
}

void foo(void *data) {}

void ModelBuilder::setup_basic(std::vector<std::string> &models, std::vector<void (*) (void *)> &actions) {

	models.push_back("print: '?' ");
	actions.push_back( &print_val );
}


ModelBuilder::ModelBuilder(){}

ModelBuilder::~ModelBuilder(){}
