#pragma once

#include "character.h"

enum Behavior {
	NEUTRAL,
	AGGRESSIVE
};

class NonPlayerCharacter : public Character {
public:
	NonPlayerCharacter(string name, string description);
	virtual ~NonPlayerCharacter();

	// Accessors
	inline Behavior getNpcBehavior() const { return this->npc_behavior; }

private:
	Behavior npc_behavior;
};