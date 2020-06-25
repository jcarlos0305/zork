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
	Instruction(InstructionType type, string argument);
	~Instruction();

	// Accessors
	inline InstructionType getType() const { return this->type; }
	inline string getArgument() const { return this->argument; }
	
	// Mutators
	void setType(InstructionType type);
	void setArgument(string argument);

	// Functions
	void execute(bool* playing, MainCharacter* player);

private:
	InstructionType type;
	string argument;
};
