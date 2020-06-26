#include "parser.h"

Parser::Parser() {
}

Parser::~Parser() {
}

Instruction *Parser::parse(vector<string> &args) {
	Instruction *i = new Instruction(INVALID); // start assuming the command is invalid
	const char* command = args[0].c_str();
	const char* argument = "";

	if (args.size() > 1) {
		argument = args[1].c_str();
		i->setArgument(argument);
	}

	if (args.size() > 0) {
		if (Utils::stringCompare(command, "go") == 0) {
			i->setType(DIRECTION);
		}
		else if (Utils::stringCompare(command, "pick") == 0) {
			i->setType(PICK_ITEM);

			if (Utils::stringCompare(argument, "item") == 0) {
				i->setArgument("");
			}
		}
		else if (Utils::stringCompare(command, "drop") == 0) {
			i->setType(DROP_ITEM);

			if (Utils::stringCompare(argument, "item") == 0) {
				i->setArgument("");
			}
		}
		else if (Utils::stringCompare(command, "attack") == 0) {
			i->setType(ATTACK);
		}
		else if (Utils::stringCompare(command, "show") == 0) {
			if (Utils::stringCompare(argument, "inventory") == 0) {
				i->setType(INVENTORY);
			}
			else if (Utils::stringCompare(argument, "stats") == 0) {
				i->setType(STATS);
			}
			else {
				i->setException("Show inventory or stats?");
			}
		}
		else if (Utils::stringCompare(command, "exit") == 0) {
			i->setType(EXIT);
		}
	}
	return i;
}
