#include "main_character.h"

MainCharacter::MainCharacter(string name, string description, int hit_points, int attack_damage, Area* current_location, bool* playing) :
	Character(name, description, hit_points, attack_damage), current_location(current_location), playing(playing) {
}

MainCharacter::~MainCharacter() {
}

void MainCharacter::Go(string direction) {
	Exit* exit = current_location->FindExit(direction);
	if (exit) { 
		
		if (exit->getNextLocation()) {
			cout << "You traveled " << exit->getDirection() << endl << endl;
			current_location = exit->getNextLocation();
			current_location->DisplayInformation();
			if (current_location->getIsLastArea()) {
				cout << "You are saved!!" << endl;
				cout << endl;
				*playing = false;
			}
		}
	}
	else {
		cout << "You can't go there" << endl;
		cout << endl;
	}
}

Item * MainCharacter::FindItem(list<Item*> item_list, const string& itemName) {
	for (Item* const item : item_list) {
		if (Utils::stringCompare(itemName.c_str(), item->getName().c_str()) == 0) {
			return item;
		}
	}
	return nullptr;
}

void MainCharacter::Pick() { 
	Item* item = current_location->getItems().back();
	if (item) {
		cout << "You picked " << item->getName() << endl;
		cout << endl;
		AddToInventory(item);
		current_location->RemoveItem(item);
	}
	else {
		cout << "There where no items to pick" << endl;
		cout << endl;
	}
}

void MainCharacter::Pick(string item_name) { 
	Item* item = FindItem(current_location->getItems(), item_name);
	if (item) {
		cout << "You picked " << item->getName() << endl;
		cout << endl;
		AddToInventory(item);
		current_location->RemoveItem(item);
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

Character * MainCharacter::FindNpc(list<Character*> npc_list, const string& enemy_name) {
	for (Character* const npc : npc_list) {
		if (Utils::stringCompare(enemy_name.c_str(), npc->getName().c_str()) == 0) {
			return npc;
		}
	}
	return nullptr;
}

void MainCharacter::Attack() {
	if (current_location->getNPCs().size()) {
		Character* npc = current_location->getNPCs().back();
		Character::Attack(npc, this);
	}
	else {
		this->TakeDamage(1);
		cout << "You hit yourself in confusion" << endl;
		cout << endl;
	}
}

void MainCharacter::Attack(string enemy) {
	Character* npc = FindNpc(current_location->getNPCs(), enemy);
	if (npc) {
		Character::Attack(npc, this);
	}
	else {
		this->TakeDamage(1);
		cout << "You hit yourself in confusion" << endl;
		cout << endl;
	}
}

Area* MainCharacter::getCurrentLocation() {
	return current_location;
}

void MainCharacter::Die() {
	*playing = false;
}

void MainCharacter::setCurrentLocation(Area * area) {
	current_location = area;
}