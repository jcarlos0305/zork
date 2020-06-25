#include "item.h"

Item::Item(string name, string description, ItemType type) :
	name(name), description(description), type(type) {
	attack_damage = 0;
	hit_points = 0;
}

Item::~Item() {
}

void Item::AddItem(Item * item) {
	contain_items.push_back(item);
}

void Item::UpgradeItem(Item * item) {
	contain_items.push_back(item);
	attack_damage += item->getAttackDamage();
	hit_points += item->getHitPoints();
	cout << "You combined the items you had into a better item" << endl;
	cout << endl;
}

void Item::setAttackDamage(int damage) {
	attack_damage = damage;
}

void Item::setHitPoints(int hp) {
	hit_points = hp;
}
