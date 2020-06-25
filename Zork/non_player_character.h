#pragma once

#include <string>
#include "character.h"

enum Behavior {
	NEUTRAL,
	AGGRESSIVE
};

class NonPlayerCharacter : public Character {
public:
	NonPlayerCharacter(string name, string description, int hit_points, int attack_damage);
	virtual ~NonPlayerCharacter();

	// Accessors
	inline Behavior getNpcBehavior() const { return this->npc_behavior; }

	void Die();

private:
	Behavior npc_behavior;
};