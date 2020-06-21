#pragma once

#include "character.h"

class MainCharacter : public Character {
public:
	MainCharacter(const char* name, const char* description, Area* current_location);
	virtual ~MainCharacter();
};