#pragma once

#include "item.h"
#include "area.h"
#include <string>
#include <list>

class Item;
class Area;

using namespace std;

struct Stats {
	int hit_points;
	int attack_damage;
};

class Character {
public:
	Character(string name, string description, int hit_points, int attack_damage);
	virtual ~Character();

	// Accessors
	inline string getName() const { return this->name; }
	inline string getDescription() const { return this->description; }
	inline int getHitPoints() const { return this->current_stats.hit_points; }
	inline int getAttackDamage() const { return this->current_stats.attack_damage; }
	inline bool getIsAlive() const { return this->current_stats.hit_points > 0; }
	inline list<Item*> getInventory() const { return this->inventory; }

	// Functions
	void AddToInventory(Item* item);
	void RemoveFromInventory(Item* item);
	void UpdateStats();
	void ShowStats() const;
	void ShowInventory() const;
	void Attack(Character* enemy) const;
	void TakeDamage(int incoming_damage);

protected:
	list<Item*> inventory;

private:
	string name;
	string description;

	Stats base_stats;
	Stats current_stats;
};