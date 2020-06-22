#include "character.h"

Character::Character(string name, string description, int  hit_points, int attack_damage) :
name(name), description(description), hit_points( hit_points), attack_damage(attack_damage){

}

Character::~Character() {
	
}

void Character::AddToInventory(Item * item) {
	inventory.push_back(item);
}

void Character::RemoveFromInventory(Item * item) {
	inventory.remove(item);
}

void Character::ShowStats() {
	cout << "Stats" << endl;
	cout << "==========" << endl;
	cout << "HP: " << hit_points << endl;
	cout << "Attack: " << attack_damage << endl;
}

void Character::ShowInventory() {
	cout << "Inventory" << endl;
	cout << "==========" << endl;
	if (getInventory().size() > 0) {
		for (Item* const item : inventory) {
			cout << item->getName() << "\n";
		}
		cout << endl;
	}
}
