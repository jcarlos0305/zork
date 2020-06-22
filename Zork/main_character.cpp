#include "main_character.h"

MainCharacter::MainCharacter(string name, string description, int hit_points, int attack_damage, Area* current_location) :
	Character(name, description, hit_points, attack_damage), current_location(current_location) {
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

void MainCharacter::PickItem(Item * item) {
	AddToInventory(item);
}

void MainCharacter::DropItem(Item * item) {
	RemoveFromInventory(item);
}



void MainCharacter::setCurrentLocation(Area * area) {
	current_location = area;
}