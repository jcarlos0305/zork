#include "exit.h"

Exit::Exit(string direction, string description, Area* next_location, bool can_travel) :
	direction(direction), description(description), next_location(next_location), can_travel(can_travel) {
}

Exit::~Exit()
{
}

void Exit::setNextLocation(Area * area) {
	next_location = area;
}

void Exit::setCanTravel(bool value) {
	can_travel = value;
}
