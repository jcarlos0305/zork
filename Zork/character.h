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
	Character(string name, string description, int hit_points, int attack_damage);
	virtual ~Character();

	// Accessors
	inline string getName() const { return this->name; }
	inline string getDescription() const { return this->description; }
	inline int getHitPoints() const { return this->hit_points; }
	inline int getAttackDamage() const { return this->attack_damage; }
	inline bool getIsAlive() const { return this->hit_points > 0; }
	inline list<Item*> getInventory() const { return this->inventory; }

	// Functions
	void AddToInventory(Item* item);
	void RemoveFromInventory(Item* item);
	void ShowStats();
	void ShowInventory();
	void Attack(Character* enemy);
	void TakeDamage(int incoming_damage);

private:
	string name;
	string description;

	int hit_points;
	int attack_damage;

	list<Item*> inventory;
};