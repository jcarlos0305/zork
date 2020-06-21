#include "area.h"

Area::Area(const char* name, const char* description) :
	name(name), description(description) {
}

Area::~Area()
{
}

void Area::AddExit(Exit * exit) {
	exits.push_back(exit);
}

void Area::AddItem(Item * item) {
	items.push_back(item);
}

void Area::AddNPC(Character * npc) {
	npcs.push_back(npc);
}
