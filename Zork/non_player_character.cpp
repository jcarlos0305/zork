#include "non_player_character.h"

NonPlayerCharacter::NonPlayerCharacter(string name, string description, int hit_points, int attack_damage) :
	Character(name, description, hit_points, attack_damage) {

}

NonPlayerCharacter::~NonPlayerCharacter() {
}
