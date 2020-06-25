#include "game.h"

Game::Game() {

	/* Environment creation */
	Area* mountain = new Area("Mountain", "You are at the top of a massive mountain with a thick forest.");
	Area* trail = new Area("Trail", "You are in a trail in the forest with low visibility of your surroundings.");
	Area* descent = new Area("Descent", "You are on a descent in one of the sides of the mountain.");

	Exit* mountain_to_trail = new Exit("north", "A trail in the woods can be seen north.", trail);
	Exit* mountain_to_descent = new Exit("east", "There seems to be a way to descent the mountain on the east side.", descent);

	Exit* trail_to_mountain = new Exit("south", "Going south you are able to go back to the area you came from.", mountain);
	Exit* descent_to_mountain = new Exit("west", "To the west you are able to go back to the area you came from.", mountain);

	mountain->AddExit(mountain_to_trail);
	mountain->AddExit(mountain_to_descent);

	trail->AddExit(trail_to_mountain);
	descent->AddExit(descent_to_mountain);

	NonPlayerCharacter* npc = new NonPlayerCharacter("Pajarito", "a really angry-looking bird stands in the middle looking straight at you.", 40, 15);
	trail->AddNPC(npc);

	/* Item creation */
	Item* sword = new Item("Sword", "It doesn't look like it can hurt anything", WEAPON);
	sword->setAttackDamage(10);

	Item* dagger = new Item("Dagger", "It doesn't look like it can hurt anything", WEAPON);
	dagger->setAttackDamage(10);
	mountain->AddItem(dagger);

	/* Character creation */
	player = new MainCharacter("Capu", "Character in development", 50, 20, mountain, &playing);
	player->AddToInventory(sword);

	this->playing = true;
}

Game::~Game() {

}

void Game::StartGame() {
	cout << "Player name: " << player->getName() << endl;
	cout << "Map name: " << player->getCurrentLocation()->getName() << endl;
	cout << endl;

	player->getCurrentLocation()->DisplayInformation();

	GameLoop();
}

void Game::GameLoop() {

	string user_input;
	vector<string> args;

	while (playing) {
		cout << "> ";
		
		getline (cin, user_input);

		cout << endl;

		istringstream ss(user_input);
		string token = "";

		while (getline(ss, token, ' ')) {
			args.push_back(token);
		}

		Instruction* instruction = parser->parse(args);
		instruction->execute(&playing, player);
		args.clear();
	}
}