#pragma once

#include "map.h"
#include "main_character.h"
#include <iostream>

using namespace std;

class Game {
public:
	Game();
	virtual ~Game();
	void GameInformation();

private:
	MainCharacter* player;
	Map* game_map;
};
