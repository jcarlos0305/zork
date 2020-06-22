#include "character.h"

Character::Character(string name, string description) :
name(name), description(description){

}

Character::~Character() {
	
}

void Character::AddToInventory(Item * item) {
	inventory.push_back(item);
}
