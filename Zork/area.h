#pragma once

#include "exit.h"
#include "item.h"
#include "character.h"
#include <string>
#include <list>

class Character;
class Exit;
class Item;

using namespace std;

class Area {
public:
	Area(const char* name, const char* description);
	virtual ~Area();

	// Accessors
	inline string getName() const { return this->name; }
	inline string getDescription() const { return this->description; }

	inline list<Exit*> getExits() const { return this->exits; }
	inline list<Item*> getItems() const { return this->items; }
	inline list<Character*> getNPCs() const { return this->npcs; }

	// Functions
	void AddExit(Exit* exit);
	void AddItem(Item* item);
	void AddNPC(Character* npc);

private:
	string name;
	string description;

	list<Exit*> exits;
	list<Item*> items;
	list<Character*> npcs;
};