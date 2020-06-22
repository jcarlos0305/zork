#pragma once

#include "character.h"
#include <iostream>

class MainCharacter : public Character {
public:
	MainCharacter(string name, string description, Area* current_location);
	virtual ~MainCharacter();

	// Accessors
	inline Area* getCurrentLocation() const { return this->current_location; }

	// Mutators
	void setCurrentLocation(Area* area);

	// Functions
	void GoToArea(string direction);

private:
	Area* current_location;
};

