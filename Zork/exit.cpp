#include "exit.h"

Exit::Exit(string direction, string description, Area* next_location, bool can_travel) :
	direction(direction), description(description), next_location(next_location), can_travel(can_travel) {
}

Exit::~Exit()
{
}

Area* Exit::getNextLocation() const {
	if (can_travel) {
		return next_location;
	}
	else {
		cout << "You need to defeat the enemy to be able to travel" << endl;
		cout << endl;
		return nullptr;
	}
}

void Exit::setCanTravel(bool value) {
	can_travel = value;
}
