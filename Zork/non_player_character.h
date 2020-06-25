#pragma once

#include <string>
#include "character.h"

class NonPlayerCharacter : public Character {
public:
	NonPlayerCharacter(string name, string description, int hit_points, int attack_damage);
	virtual ~NonPlayerCharacter();

	void Die();
	Area* getCurrentLocation();
};