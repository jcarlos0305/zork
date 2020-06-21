#pragma once

#include "area.h"
#include <list>

class Map{
public:
	Map();
	~Map();

	// Accessors
	inline list<Area*> getAreas() const { return this->areas; }

	// Functions
	void AddArea(Area* area);

private:
	list<Area*> areas;
};
