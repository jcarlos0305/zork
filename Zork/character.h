#pragma once

#include "item.h"
#include "area.h"
#include <string>
#include <list>

class Item;
class Area;

using namespace std;

class Character {
public:
	Character(const char* name, const char* description, Area* current_location);
	virtual ~Character();

public:
	std::string name;
	std::string description;

	list<Item*> inventory;
	Area* current_location;
};