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
		cout << "There was no exit on that direction" << endl;
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

void MainCharacter::Attack() {
	Character* npc = current_location->getNPCs().back();
	if (npc) {
		Character::Attack(npc);
		cout << "You attacked " << npc->getName() << endl;
		if (npc->getIsAlive()) {
			npc->Attack(this);
			cout << npc->getName() << " attacked you back" << endl;
			cout << endl;
			if (!this->getIsAlive()) {
				cout << "You died!" << endl;
				cout << endl;
				Die();
			}
			else {
				cout << "The fight keeps going" << endl;
				cout << endl;
			}
		}
		else {
			npc->Die();
			current_location->RemoveNPC(npc);
			current_location->getExits().back()->setCanTravel(true);
		}
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

void MainCharacter::Die() {
	*playing = false;
}

void MainCharacter::setCurrentLocation(Area * area) {
	current_location = area;
}