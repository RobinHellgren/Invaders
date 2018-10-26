#pragma once
#include "SFML/Graphics.hpp"
#include "GameOverScreen.h"
#include "InstructionPage.h"
#include "MainMenu.h"
class MenuManager
{
public:
	MenuManager(Game* game);
	~MenuManager();
	sf::Font* getTitleFont();
	sf::Font* getBreadFont();
	void runMainMenu();
	void runInstructionPage();
	bool getInputDelayed();
	void setInputDelayed(bool state);
	sf::Clock* getInputClock();
	float mInputDelay;
private:
	sf::Font* mTitleFont;
	sf::Font* mBreadFont;
	Game* mGame;
	bool mInputDelayed;
	sf::Clock* mInputClock;
};

