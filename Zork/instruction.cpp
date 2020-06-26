#include "instruction.h"

Instruction::Instruction():
	type(INVALID) {
}

Instruction::Instruction(InstructionType type) :
	type(type) {
}

Instruction::~Instruction() {
}

void Instruction::setType(InstructionType type) {
	this->type = type;
}

void Instruction::setArgument(string argument) {
	this->argument = argument;
}

void Instruction::setException(string exception) {
	this->exception = exception;
}

bool Instruction::hasArguments() {
	return argument.size() > 0;
}

bool Instruction::checkParserExceptions() {
	if (exception.size() > 0) {
		cout << exception << endl;
		return true;
	}
	return false;
}

void Instruction::execute(bool *playing, MainCharacter *player) {
	// if there's a pre-defined parser exception, break the instruction cycle
	if (checkParserExceptions()) return;

	switch (type) {
	case DIRECTION:
		player->Go(argument);
		break;
	case ATTACK:
		if (hasArguments()) {
			player->Attack(argument);
		}
		else {
			player->Attack();
		}
		break;
	case PICK_ITEM:
		if (hasArguments()) {
			player->Pick(argument);
		}
		else {
			player->Pick();
		}
		break;
	case DROP_ITEM:
		if (hasArguments()) {
			player->Drop(argument);
		}
		else {
			player->Drop();
		}
		break;
	case INVENTORY:
		player->ShowInventory();
		break;
	case STATS:
		player->ShowStats();
		break;
	case EXIT:
		*playing = false;
		break;
	default:
		cout << "Command not recognized" << endl;
		cout << endl;
		break;
	}
}
