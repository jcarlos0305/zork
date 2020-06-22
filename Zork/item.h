#pragma once

#include <string>
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

	// Mutators
	void setAttackDamage(int damage);

private:
	string name;
	string description;
	ItemType type;
	int attack_damage;
	list<Item*> contain_items;
};