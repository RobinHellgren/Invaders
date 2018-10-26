#include "Game.h"



int main() {
	Game game;
	game.getMenu()->runMainMenu();
	game.run();
	return 0;
}