#include "game.h"

Game::Game() {

	/* Game entities creation */

	/* Areas */
	Area* mountain = new Area("Mountain", "It all started as a nice trip to an unexplored mountain, it got dark really quick and you find yourself lost somewhere near the top of the massive the mountain.");
	Area* trail = new Area("Trail", "You are now in a trail in the forest with low visibility of your surroundings.");
	Area* descent = new Area("Descent", "You are on a descent in one of the sides of the mountain.");
	Area* waterfall = new Area("Waterfall", "You just arrived are at the top of a waterfall and there seems that there is no other way than going back where you came from.");
	Area* cave = new Area("Cave", "You just entered an small cave that seems to connect the two sides of the mountain.");
	Area* town = new Area("Town", "You found a town with welcoming people willing to help you!.", true);

	/* Mountain exits */
	Exit* mountain_to_trail = new Exit("north", "A trail in the woods can be seen north.", trail);
	Exit* mountain_to_descent = new Exit("east", "There seems to be a way to descent the mountain on the east side.", descent);
	mountain->AddExit(mountain_to_trail);
	mountain->AddExit(mountain_to_descent);

	/* Trail exits */
	Exit* trail_to_mountain = new Exit("south", "Going south you are able to go back to the area you came from.", mountain);
	Exit* trail_to_waterfall = new Exit("west", "You can hear a river flow west of where you are.", waterfall);
	trail->AddExit(trail_to_mountain);
	trail->AddExit(trail_to_waterfall);

	/* Waterfall exits */
	Exit* waterfall_to_trail = new Exit("east", "To the east you are able to go back to the area you came from.", trail);
	waterfall->AddExit(waterfall_to_trail);

	/* Descent exits */
	Exit* descent_to_mountain = new Exit("west", "To the west you are able to go back to the area you came from.", mountain);
	Exit* descent_to_cave = new Exit("south", "It looks like there is a cave south of where you are.", cave);
	descent->AddExit(descent_to_mountain);
	descent->AddExit(descent_to_cave);

	/* Cave exits */
	Exit* cave_to_descent = new Exit("north", "You can go back north to the area you came from.", descent);
	Exit* cave_to_town = new Exit("east", "The cave's exit seems to be on the east side.", town, false);
	cave->AddExit(cave_to_descent);
	cave->AddExit(cave_to_town);

	/* Town exits */
	Exit* town_to_cave = new Exit("west", "", cave);
	town->AddExit(town_to_cave);

	/* NPC creation */
	NonPlayerCharacter* npc = new NonPlayerCharacter("Wolf", "A really angry-looking wolf stands on the way to the exit.", 45, 15);
	cave->AddNPC(npc);

	/* Item creation */
	Item* wood_stick = new Item("Stick", "Laying on the ground there is a stick that looks that might come handy if something were to happen to you", WEAPON);
	wood_stick->setAttackDamage(10);
	trail->AddItem(wood_stick);

	Item* sharp_rock = new Item("Rock", "There is a rock with sharp edges near the water, it might improve your chances of surviving.", WEAPON);
	sharp_rock->setAttackDamage(10);
	waterfall->AddItem(sharp_rock);

	/* Character creation */
	player = new MainCharacter("Capu", "Character in development", 50, 10, mountain, &playing);

	/* Start game */
	this->playing = true;
	parser = new Parser();
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