#include "non_player_character.h"

NonPlayerCharacter::NonPlayerCharacter(const char* name, const char* description, Area* current_location) :
	Character(name, description, current_location) {

}

NonPlayerCharacter::~NonPlayerCharacter()
{
}
