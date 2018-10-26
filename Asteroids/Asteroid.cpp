#include "Asteroid.h"
#include "Game.h"

Asteroid::Asteroid(Game* mGamePointer){
	mGame = mGamePointer;
	mSprite = new sf::Sprite;
	mSprite->setTexture(*mGame->getGameTextures());
	std::random_device device;
	mRandomGen = std::mt19937(device());
	std::uniform_int_distribution<int> destI(1, 4);
	std::uniform_int_distribution<int> destPosX(100, 700);
	std::uniform_int_distribution<int> destPosY(100, 500);
	std::uniform_int_distribution<int> destAngle(-5, 5);
	int textureSelector = destI(mRandomGen);
	int spawnSelector = destI(mRandomGen);
	mMarkedForDeletion = false;

	
	switch (textureSelector){
	case 1:
		mSprite->setTextureRect(sf::IntRect(20, 63, 23, 16));
		mSprite->setOrigin(11, 8);
		radius = 5;
		break;
	case 2:
		mSprite->setTextureRect(sf::IntRect(14, 93, 33, 31));
		mSprite->setOrigin(16, 15);
		radius = 8;
		break;
	case 3: 
		mSprite->setTextureRect(sf::IntRect(12, 140, 37, 30));
		mSprite->setOrigin(18, 15);
		radius = 9;
		break;
	case 4:
		mSprite->setTextureRect(sf::IntRect(3, 188, 60, 60));
		mSprite->setOrigin(30, 30);
		radius = 17;
		break;
	default:
		break;
	}
	switch (spawnSelector) {
	case 1:
		mSprite->setPosition(destPosX(mRandomGen), 10);
		mAsteroidMovement = sf::Vector2f(destAngle(mRandomGen), 5.0f);
		break;
	case 2:
		mSprite->setPosition(destPosX(mRandomGen),600 );
		mAsteroidMovement = sf::Vector2f(destAngle(mRandomGen), -5.0f);
		break;
	case 3:
		mSprite->setPosition(10, destPosY(mRandomGen));
		mAsteroidMovement = sf::Vector2f(5.0f, destAngle(mRandomGen));
		break;
	case 4:
		mSprite->setPosition(800, destPosY(mRandomGen));
		mAsteroidMovement = sf::Vector2f(-5.0f, destAngle(mRandomGen));
		break;
	default:
		break;
	}
	mAsteroidRotation = destAngle(mRandomGen);
	mType = ObjectType::ASTEROID;


}


Asteroid::~Asteroid(){
	delete mSprite;
}
void Asteroid::update() {
	mSprite->move(mAsteroidMovement* mGame->getDeltaTime() * 15.0f);
	mSprite->rotate(mAsteroidRotation);
	mGame->getWindow()->draw(*mSprite);
	//std::cout << "Asteroid updated" << std::endl;

}
void Asteroid::spawn() {
	mGame->getWindow()->draw(*mSprite);
}
void Asteroid::colide(GameObject * objectColidedWith) {
	if (objectColidedWith->mType == ObjectType::ASTEROID) {
		mMarkedForDeletion = true;
	}
}
