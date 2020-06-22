#pragma once

#include "area.h"
#include <string>

class Area;

using namespace std;

class Exit {
public:
	Exit(string direction, string description, Area* next_location, bool can_travel = true);
	virtual ~Exit();

	// Accessors
	inline string getDirection() const { return this->direction; }
	inline string getDescription() const { return this->description; }
	inline Area* getNextLocation() const { return this->next_location; }
	inline bool getCanTravel() const { return this->can_travel; }

	// Mutators
	void setNextLocation(Area* area);
	void setCanTravel(bool value);

private:
	string direction;
	string description;

	Area* next_location;
	bool can_travel;
};