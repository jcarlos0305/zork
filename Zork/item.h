#pragma once

#include <list>

using namespace std;

class Item {
public:
	Item();
	virtual ~Item();

private:
	list<Item*> contain_items;
};