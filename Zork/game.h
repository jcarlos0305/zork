#pragma once

#include "main_character.h"
#include "non_player_character.h"
#include <string>
#include <iostream>

using namespace std;

class Game {
public:
	Game();
	virtual ~Game();
	
	// Functions
	void StartGame();

private:
	bool playing;

	MainCharacter* player;
};
