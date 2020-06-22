#include "item.h"

Item::Item(string name, string description, ItemType type)
	: name(name), description(description), type(type) {
}

Item::~Item() {
}

void Item::AddItem(Item * item) {
	contain_items.push_back(item);
}
