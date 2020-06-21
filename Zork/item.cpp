#include "item.h"

Item::Item()
{
}

Item::~Item()
{
}

void Item::AddItem(Item * item) {
	contain_items.push_back(item);
}
