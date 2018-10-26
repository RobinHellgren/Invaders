#include "MenuManager.h"



MenuManager::MenuManager(Game* game){
	mGame = game;
	mTitleFont = new sf::Font;
	mBreadFont = new sf::Font;
	mInputClock = new sf::Clock;
	mTitleFont->loadFromFile("./Fonts/Championship.ttf");
	mBreadFont->loadFromFile("./Fonts/AldotheApache.ttf");
}


MenuManager::~MenuManager(){
}

sf::Font* MenuManager::getTitleFont(){
	return mTitleFont;
}

sf::Font* MenuManager::getBreadFont(){
	return mBreadFont;
}

void MenuManager::runMainMenu(){
	MainMenu main(mGame, this);
	main.run();
}

void MenuManager::runInstructionPage(){
	InstructionPage instrPg(mGame, this);
	instrPg.run();
}

bool MenuManager::getInputDelayed()
{
	return mInputDelayed;
}

void MenuManager::setInputDelayed(bool state){
	mInputDelayed = state;
}

sf::Clock* MenuManager::getInputClock()
{
	return mInputClock;
}
