#pragma once

#include "main_character.h"
#include <string>

enum InstructionType {
	INVALID, // for all invalid instructions
	DIRECTION,
	ATTACK,
	PICK_ITEM,
	DROP_ITEM,
	INVENTORY,
	STATS,
	EXIT
};

class Instruction {
public:
	Instruction();
	Instruction(InstructionType type);
	~Instruction();

	// Accessors
	inline InstructionType getType() const { return this->type; }
	inline string getArgument() const { return this->argument; }
	inline string getException() const { return this->exception; }

	// Mutators
	void setType(InstructionType type);
	void setArgument(string argument);
	void setException(string exception);

	// Functions
	void execute(bool* playing, MainCharacter* player);

private:
	InstructionType type;
	string argument;
	string exception;
	bool hasArguments();
	bool checkParserExceptions();
};
