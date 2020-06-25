#pragma once

#include "character.h"
#include "utils.h"
#include <string>
#include <iostream>
#include <algorithm>

class MainCharacter : public Character {
public:
	MainCharacter(string name, string description, int hit_points, int attack_damage, Area* current_location, bool* playing);
	virtual ~MainCharacter();

	// Mutators
	void setCurrentLocation(Area* area);

	// Functions
	void Go(string direction);
	void Pick();
	void Pick(string item_name);
	void Drop();
	void Drop(string item_name);
	void Attack();
	void Attack(string enemy);

	// Override parent funcitons
	Area* getCurrentLocation();
	void Die();

private:
	Area* current_location;
	bool* playing;

	Item* FindItem(list<Item*> item_list, const string& itemName);
	Character * FindNpc(list<Character*> npc_list, const string & enemy_name);
};

