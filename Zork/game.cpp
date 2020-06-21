#include "game.h"

Game::Game() {
	Area* mountain = new Area("Mountain", "You are at the top of a massive mountain with a thick forest.");
	Area* trail = new Area("Trail", "You are in a trail in the forest with low visibility of your surroundings.");
	Area* descent = new Area("Descent", "You are on a descent in one of the sides of the mountain.");

	Exit* mountain_to_trail = new Exit("north", "A trail in the woods can be seen north.", trail);
	Exit* mountain_to_descent = new Exit("east", "There seems to be a way to descent the mountain on the east side.", descent);

	mountain->AddExit(mountain_to_trail);
	mountain->AddExit(mountain_to_descent);

	game_map = new Map();
	game_map->AddArea(mountain);
	game_map->AddArea(trail);
	game_map->AddArea(descent);

	player = new MainCharacter("Capu", "Character in development", mountain);
	this->playing = true;
}

Game::~Game() {

}

void Game::StartGame() {
	cout << "Player name: " << player->getName() << endl;
	cout << "Map name: " << player->getCurrentLocation()->getName() << endl;
	cout << endl;

	cout << player->getCurrentLocation()->getDescription();

	for (Exit* const exit : player->getCurrentLocation()->getExits()) {
		cout << exit->getDescription() << " \n";
	}
	cout << endl;
}
