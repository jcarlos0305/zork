#include "area.h"

Area::Area(string name, string description) :
	name(name), description(description) {
}

Area::~Area() {
}

void Area::AddExit(Exit * exit) {
	exits.push_back(exit);
}

void Area::AddItem(Item * item) {
	items.push_back(item);
}

void Area::RemoveItem(Item * item) {
	items.remove(item);
}

void Area::AddNPC(Character * npc) {
	npcs.push_back(npc);
}

void Area::RemoveNPC(Character * npc) {
	npcs.remove(npc);
}

void Area::DisplayInformation() const {
	cout << name << endl;
	cout << description << " ";

	if (exits.size() > 0) {
		for (Exit* const exit : exits) {
			cout << exit->getDescription() << " ";
		}
		cout << endl;
	}

	if (items.size() > 0) {
		for (Item* const item : items) {
			cout << item->getDescription() << " ";
		}
		cout << endl;
	}

	if (npcs.size() > 0) {
		cout << "It seems you are not alone in this area, ";
		for (Character* const npc : npcs) {
			cout << npc->getDescription() << " \n";
		}
	}
	cout << endl;
}

Exit* Area::FindExit(const string& exit_name) const {
	for (Exit* const exit : exits) {
		if (Utils::stringCompare(exit_name.c_str(), exit->getDirection().c_str()) == 0) {
			return exit;
		}
	}
	return nullptr;
}
