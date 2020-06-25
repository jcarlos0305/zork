#include "instruction.h"

Instruction::Instruction() {
	setType(INVALID);
}

Instruction::Instruction(InstructionType type) :
	type(type) {
}

Instruction::Instruction(InstructionType type, string argument) :
	type(type), argument(argument) {
}

Instruction::~Instruction() {
}

void Instruction::setType(InstructionType type) {
	this->type = type;
}

void Instruction::setArgument(string argument) {
	this->argument = argument;
}

void Instruction::execute(bool *playing, MainCharacter *player) {
	switch (type) {
	case DIRECTION:
		player->Go(argument);
		break;
	case ATTACK:
		player->Attack(argument);
		break;
	case PICK_ITEM:
		player->Pick(argument);
		break;
	case DROP_ITEM:
		player->Drop(argument);
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
