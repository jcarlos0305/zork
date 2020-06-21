#include "character.h"

Character::Character(const char* name, const char* description, Area* current_location) :
name(name), description(description), current_location(current_location){

}

Character::~Character() {
	
}
