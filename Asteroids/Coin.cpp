#include "Coin.h"



Coin::Coin(Game* game){
	mGame = game;
	mSprite = new sf::Sprite;
	mSprite->setTexture(*mGame->getGameTextures());
	mSprite->setTextureRect(sf::IntRect(12, 265, 40, 43));
	setRandomLocation();
	mSprite->setOrigin(17, 16);
	mType = ObjectType::COIN;
	radius = 17;
	mSprite->setColor(sf::Color::Yellow);
}


Coin::~Coin()
{
}

void Coin::update(){
	if (!mInPlay) {
		mSpawnDelay += mGame->getDeltaTime();
	}
	if (mSpawnDelay > 5.0f && mInPlay == false) {
		mInPlay = true;
		mSpawnDelay = 0;
		mGameOverTimer = 0;
		mSprite->setColor(sf::Color::Yellow);
		
	}
	if (mGameOverTimer > 3.0) {
		mSprite->setColor(sf::Color::Red);
	}
	if (mGameOverTimer > 5.0) {
		mGame->setGameIsntOver(false);
	}
	if (mInPlay) {
		mGame->getWindow()->draw(*mSprite);
		mGameOverTimer += mGame->getDeltaTime();
	}
	
}

void Coin::spawn(){
}



void Coin::setRandomLocation(){
	std::random_device device;
	mRandomGen = std::mt19937(device());
	std::uniform_real_distribution<float> destPosX(100.0f, 700.0f);
	std::uniform_real_distribution<float> destPosY(100.0f, 500.0f);
	mSprite->setPosition(destPosX(mRandomGen), destPosY(mRandomGen));
}
