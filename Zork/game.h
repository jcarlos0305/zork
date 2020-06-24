#pragma once

#include "main_character.h"
#include "non_player_character.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Game {
public:
	Game();
	virtual ~Game();
	
	// Functions
	void StartGame();
	void GameLoop();

private:
	bool playing;

	MainCharacter* player;
};
