#pragma once

#include "item.h"
#include "area.h"
#include <string>
#include <list>

class Item;
class Area;

using namespace std;

class Character {
public:
	Character(string name, string description);
	virtual ~Character();

	// Accessors
	inline string getName() const { return this->name; }
	inline string getDescription() const { return this->description; }

	inline list<Item*> getInventory() const { return this->inventory; }

	// Functions
	void AddToInventory(Item* item);

private:
	string name;
	string description;

	list<Item*> inventory;
};