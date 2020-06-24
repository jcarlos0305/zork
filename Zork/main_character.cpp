#include "main_character.h"

MainCharacter::MainCharacter(string name, string description, int hit_points, int attack_damage, Area* current_location) :
	Character(name, description, hit_points, attack_damage), current_location(current_location) {
}

MainCharacter::~MainCharacter() {
}

void MainCharacter::Go(string direction) {
	for (Exit* const exit : current_location->getExits()) {
		if (direction.compare(exit->getDirection()) == 0) {
			cout << "You traveled " << direction << endl << endl;
			current_location = exit->getNextLocation();
		}
	}
}

Item * MainCharacter::GetItemFromInventory(string itemName)
{
	for (Item* const item : inventory) {
		if (item->getName().compare(itemName) == 0) {
			return item;
		}
	}
	return nullptr;
}

void MainCharacter::Pick() { 
	Item* item = current_location->getItems().back();
	if (item) {
		AddToInventory(item);
		current_location->RemoveItem(item);
	}
	else {
		cout << "There where no items to pick" << endl;
	}
}

void MainCharacter::Pick(string item_name) { 
	Item* item = GetItemFromInventory(item_name);
	if (item) {
		AddToInventory(item);
		current_location->RemoveItem(item);
	} else {
		cout << item_name << " not found" << endl;
	}
}

void MainCharacter::Drop() { 
	Item* item = inventory.back();
	if (item) {
		RemoveFromInventory(item);
		current_location->AddItem(item);
	} else {
		cout << "There where no items to drop" << endl;
	}
}

void MainCharacter::Drop(string item_name) { 
	Item* item = GetItemFromInventory(item_name);
	if (item) {
		RemoveFromInventory(item);
		current_location->AddItem(item);
	} else {
		cout << item_name << " not found" << endl;
	}
}

void MainCharacter::Attack() {
	Character* npc = current_location->getNPCs().back();
	if (npc) {
		Character::Attack(npc);
	}
	else {
		this->TakeDamage(1);
		cout << "You hit yourself in confusion" << endl;
	}
	
}

void MainCharacter::Attack(string enemy) {
	for (Character* const npc : current_location->getNPCs()) {
		if (npc->getName().compare(enemy) == 0) {
			Character::Attack(npc);
		}
	}
}

void MainCharacter::setCurrentLocation(Area * area) {
	current_location = area;
}