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
	void GoToArea(string direction);
	void PickItem(Item* item);
	void DropItem(Item* item);

private:
	Area* current_location;
};

