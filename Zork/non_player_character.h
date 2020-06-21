#pragma once

#include "character.h"

class NonPlayerCharacter : public Character {
public:
	NonPlayerCharacter(const char* name, const char* description, Area* current_location);
	virtual ~NonPlayerCharacter();
};