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
	Character(const char* name, const char* description, Area* current_location);
	virtual ~Character();

	// Accessors
	inline string getName() const { return this->name; }
	inline string getDescription() const { return this->description; }

	inline list<Item*> getInventory() const { return this->inventory; }
	inline Area* getCurrentLocation() const { return this->current_location; }

	// Mutators
	void setCurrentLocation(Area* area);

	// Functions
	void AddToInventory(Item* item);

private:
	string name;
	string description;

	list<Item*> inventory;
	Area* current_location;
};