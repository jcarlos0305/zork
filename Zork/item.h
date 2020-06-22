#pragma once

#include <list>

using namespace std;

enum ItemType {
	WEAPON,
	UTILITY
};

class Item {
public:
	Item(string name, string description, ItemType type);
	virtual ~Item();

	// Accessors
	inline string getName() const { return this->name; }
	inline string getDescription() const { return this->description; }
	inline ItemType getType() const { return this->type; }
	inline list<Item*> getContainItems() const { return this->contain_items; }

	// Functions
	void AddItem(Item* item);

private:
	string name;
	string description;
	ItemType type;
	list<Item*> contain_items;
};