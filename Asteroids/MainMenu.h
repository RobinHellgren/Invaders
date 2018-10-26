#pragma once
#include "SFML/Graphics.hpp"

enum class MenuItem { PLAY, QUIT, INTRUCTIONS };
class Game;
class MenuManager;
class MainMenu {

public:
	MainMenu(Game* game,MenuManager* menuMngr );
	~MainMenu();
	void run();
	void menuControlls();

	MenuManager* mMenu;
	Game* mGame;
	sf::Text mTitle;
	sf::Text mPlayButton;
	sf::Text mQuitButton;
	sf::Text mInstructionButton;
	sf::Text mMenuPointer;
	MenuItem mCurrentMenuItem;

	bool mMainMenuRunning;
};

