#include "main_character.h"

MainCharacter::MainCharacter(string name, string description, int hit_points, int attack_damage, Area* current_location) :
	Character(name, description, hit_points, attack_damage), current_location(current_location) {
}

MainCharacter::~MainCharacter() {
}

void MainCharacter::Go(const string direction) {
	for (Exit* const exit : current_location->getExits()) {
		if (direction.compare(exit->getDirection()) == 0) {
			cout << "You traveled " << direction << endl << endl;
			current_location = exit->getNextLocation();
			current_location->DisplayInformation();
		}
	}
}

Item * MainCharacter::FindItem(list<Item*> item_list, const string& itemName)
{
	for (Item* const item : item_list) {
		if (_stricmp(itemName.c_str(), item->getName().c_str()) == 0) {
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
		cout << "You picked " << item->getName() << endl;
		cout << endl;
	}
	else {
		cout << "There where no items to pick" << endl;
		cout << endl;
	}
}

void MainCharacter::Pick(string item_name) { 
	Item* item = FindItem(current_location->getItems(), item_name);
	if (item) {
		AddToInventory(item);
		current_location->RemoveItem(item);
		cout << "You picked " << item->getName() << endl;
		cout << endl;
	} else {
		cout << item_name << " not found" << endl;
		cout << endl;
	}
}

void MainCharacter::Drop() {
	Item* item = inventory.back();
	if (item) {
		RemoveFromInventory(item);
		current_location->AddItem(item);
		cout << item->getName() << " was dropped" << endl;
		cout << endl;
	}
	else {
		cout << "There where no items to drop" << endl;
		cout << endl;
	}
}

void MainCharacter::Drop(string item_name) {
	Item* item = FindItem(inventory, item_name);
	if (item) {
		RemoveFromInventory(item);
		current_location->AddItem(item);
		cout << item->getName() << " was dropped" << endl;
		cout << endl;
	}
	else {
		cout << item_name << " not found" << endl;
		cout << endl;
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
		cout << endl;
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