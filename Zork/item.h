#pragma once

#include <list>

using namespace std;

class Item {
public:
	Item();
	virtual ~Item();

	// Accessors
	inline list<Item*> getContainItems() const { return this->contain_items; }

	// Functions
	void AddItem(Item* item);

private:
	list<Item*> contain_items;
};