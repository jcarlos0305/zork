#pragma once

#include "exit.h"
#include "item.h"
#include "character.h"
#include <string>
#include <list>

class Character;

using namespace std;

class Area {
public:
	Area(const char* name, const char* description);
	virtual ~Area();

public:
	std::string name;
	std::string description;

	list<Exit*> exits;
	list<Item*> items;
	list<Character*> npcs;
};