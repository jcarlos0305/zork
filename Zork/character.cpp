#include "character.h"

Character::Character(const char* name, const char* description, Area* current_location) :
name(name), description(description), current_location(current_location){

}

Character::~Character() {
	
}

void Character::AddToInventory(Item * item) {
	inventory.push_back(item);
}

void Character::setCurrentLocation(Area * area) {
	current_location = area;
}
