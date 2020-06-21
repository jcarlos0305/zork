#include "game.h"

Game::Game() {
	Area* mountain = new Area("Mountain", "Massive mountain with a thick forest");
	game_map = new Map();
	game_map->areas.push_back(mountain);
	player = new MainCharacter("Capu", "Character in development", mountain);
	
}

Game::~Game() {

}

void Game::GameInformation() {
	cout << "Player name: " << player->name << "\n";
	cout << "Map name: " << player->current_location->name << "\n\n";
}