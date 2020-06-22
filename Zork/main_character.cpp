#include "main_character.h"

MainCharacter::MainCharacter(string name, string description, Area* current_location) :
	Character(name, description), current_location(current_location) {
}

MainCharacter::~MainCharacter() {
}

void MainCharacter::GoToArea(string direction) {
	for (Exit* const exit : current_location->getExits()) {
		if (direction.compare(exit->getDirection()) == 0) {
			cout << "You traveled " << direction << endl << endl;
			current_location = exit->getNextLocation();
		}
	}
}

void MainCharacter::setCurrentLocation(Area * area) {
	current_location = area;
}