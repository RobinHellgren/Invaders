#pragma once
#include "SFML/Graphics.hpp"
class Game;
class MenuManager;
class InstructionPage
{
public:
	InstructionPage(Game* game, MenuManager* menuMngr);
	~InstructionPage();
	void run();
	void menuControlls();
private:
	sf::Text mTitle;
	sf::Text mInstructions;
	sf::Text mBackToMainButton;
	sf::Text mMenuSelector;

	bool mInstructionPageRunning;

	Game* mGame;
	MenuManager* mMenu;
};

