#include "parser.h"

Parser::Parser() {
}

Parser::~Parser() {
}

Instruction *Parser::parse(vector<string> &args) {
	Instruction *i = new Instruction(INVALID); // start assuming the command is invalid

	if (args.size() > 0) {
		if (args[0] == "go") {
			i->setType(DIRECTION);
		}
		else if (args[0] == "pick") {
			i->setType(PICK_ITEM);
		}
		else if (args[0] == "drop") {
			i->setType(DROP_ITEM);
		}
		else if (args[0] == "attack") {
			i->setType(ATTACK);
		}
		else if (args[0] == "show") {
			if (args[1] == "inventory") {
				i->setType(INVENTORY);
			}
			else if (args[1] == "stats") {
				i->setType(STATS);
			}
		}
		else if (args[0] == "exit") {
			i->setType(EXIT);
		}

		if (args.size() > 1) {
			i->setArgument(args[1]);
		}
	}
	return i;
}
