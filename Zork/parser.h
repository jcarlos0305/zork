#pragma once

#include "instruction.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Parser {
public:
	Parser();
	~Parser();

	// Functions
	Instruction * parse(vector<string> &args);

};
