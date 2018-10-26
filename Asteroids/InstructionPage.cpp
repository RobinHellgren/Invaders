#include "InstructionPage.h"
#include "MenuManager.h"
#include "Game.h"


InstructionPage::InstructionPage(Game * game, MenuManager * menuMngr){
	mGame = game;
	mMenu = menuMngr;

	mInstructionPageRunning = true;

	mTitle.setFont(*mMenu->getTitleFont());
	mTitle.setFillColor(sf::Color::White);
	mTitle.setString("INSTRUCTIONS");
	mTitle.setCharacterSize(78);
	mTitle.setPosition(150, 10);

	mInstructions.setFont(*mMenu->getBreadFont());
	mInstructions.setFillColor(sf::Color::White);
	mInstructions.setCharacterSize(25);
	mInstructions.setPosition(10, 150);
	mInstructions.setString("The aim of this game is to collect the yellow orb while \n avoiding the asteroids.\n If the player is hit by an asteroid or fails to pick up the orb in 5 seconds \n the game will end.\n Every time a coin is picked up more asteroids will spawn.\n Use A and D to rotate the ship and W to move the ship foward.");

	mBackToMainButton.setFont(*mMenu->getBreadFont());
	mBackToMainButton.setFillColor(sf::Color::White);
	mBackToMainButton.setString("Back to main menu");
	mBackToMainButton.setCharacterSize(47);
	mBackToMainButton.setPosition(200, 300);

	mMenuSelector.setFont(*mMenu->getBreadFont());
	mMenuSelector.setFillColor(sf::Color::White);
	mMenuSelector.setString("*");
	mMenuSelector.setCharacterSize(34);
	mMenuSelector.setPosition(180, 310);
}

InstructionPage::~InstructionPage(){
	
}
void InstructionPage::run() {
	while (mGame->getWindow()->isOpen() && mInstructionPageRunning) {
		sf::Event event;
		while (mGame->getWindow()->pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				mGame->getWindow()->close();
				return;
			}
		}
		mGame->getWindow()->clear(sf::Color::Black);
		menuControlls();
		mGame->getWindow()->draw(mTitle);
		mGame->getWindow()->draw(mInstructions);
		mGame->getWindow()->draw(mBackToMainButton);
		mGame->getWindow()->draw(mMenuSelector);
		mGame->getWindow()->display();


	}

}

void InstructionPage::menuControlls(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
		mInstructionPageRunning = false;
		mMenu->runMainMenu();
	}
}
