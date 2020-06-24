#pragma once

#include "character.h"
#include <string>
#include <iostream>

class MainCharacter : public Character {
public:
	MainCharacter(string name, string description, int hit_points, int attack_damage, Area* current_location);
	virtual ~MainCharacter();

	// Accessors
	inline Area* getCurrentLocation() const { return this->current_location; }

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

private:
	Area* current_location;

	Item* GetItemFromInventory(string itemName);
};

