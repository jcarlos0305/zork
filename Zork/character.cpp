#include "character.h"

Character::Character(string name, string description, int  hit_points, int attack_damage) :
name(name), description(description) {
	base_stats = { hit_points, attack_damage };
}

Character::~Character() {
	
}

void Character::AddToInventory(Item * item) {
	inventory.push_back(item);
	UpdateStats();
}

void Character::RemoveFromInventory(Item * item) {
	inventory.remove(item);
	UpdateStats();
}

void Character::UpdateStats() {
	current_stats.attack_damage = base_stats.attack_damage;
	current_stats.hit_points = base_stats.hit_points;
	for (Item* const item : inventory) {
		current_stats.attack_damage += item->getAttackDamage();
		current_stats.hit_points += item->getHitPoints();
	}
}

void Character::ShowStats() const {
	cout << "-----------" << endl;
	cout << "   Stats   " << endl;
	cout << "-----------" << endl;
	cout << "HP: " << current_stats.hit_points << endl;
	cout << "Attack: " << current_stats.attack_damage << endl;
	cout << endl;
}

void Character::ShowInventory() const {
	if (inventory.size() > 0) {
		cout << "---------------" << endl;
		cout << "   Inventory   " << endl;
		cout << "---------------" << endl;
		for (Item* const item : inventory) {
			cout << item->getName() << "\n";
		}
		cout << endl;
	}
	else {
		cout << "The character has no items" << endl;
	}
}

void Character::Attack(Character* enemy) const{
	enemy->TakeDamage(current_stats.attack_damage);
}

void Character::TakeDamage(int incoming_damage) {
	current_stats.hit_points -= incoming_damage;
}
