#pragma once

#include "area.h"
#include <list>

class Map{
public:
	Map();
	~Map();

public:
	list<Area*> areas;
};
