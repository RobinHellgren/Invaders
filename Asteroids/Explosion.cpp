#include "Explosion.h"
#include "Game.h"


Explosion::Explosion(Game* game, Enemy* enemy){
	mGame = game;
	mSprite = new sf::Sprite;
	mSprite->setTexture(*mGame->getGameTextures());
	mSprite->setTextureRect(sf::IntRect(200, 0, 100, 100));
	mSprite->setOrigin(50, 50);
	mType = ObjectType::EXPLOSION;
	mFaction = Faction::NEUTRAL;
	radius = 50;
	mAnimationTimer = 0;
	mMarkedForDeletion = false;
	mSprite->setPosition(enemy->getMSprite()->getPosition());
	std::cout << "Explosion!" << std::endl;
}

Explosion::~Explosion(){
}

void Explosion::update(){
	animate();

	if (mAnimationTimer > ANIMATION_TIME) {
		mMarkedForDeletion = true;
	}
}

void Explosion::spawn(){
}

void Explosion::colide(GameObject * objectColidedWith){
}

void Explosion::animate(){
	if (mAnimationTimer > (ANIMATION_TIME / 10) * 10) {
		mSprite->setTextureRect(sf::IntRect(300, 300, 100, 100));
	}
	else if (mAnimationTimer > (ANIMATION_TIME / 10) * 9) {
		mSprite->setTextureRect(sf::IntRect(300, 200, 100, 100));
	}
	else if (mAnimationTimer > (ANIMATION_TIME / 10) * 8) {
		mSprite->setTextureRect(sf::IntRect(300, 100, 100, 100));
	}
	else if (mAnimationTimer > (ANIMATION_TIME / 10) * 7) {
		mSprite->setTextureRect(sf::IntRect(300, 0, 100, 100));
	}
	else if (mAnimationTimer > (ANIMATION_TIME / 10) * 6) {
		mSprite->setTextureRect(sf::IntRect(200, 500, 100, 100));
	}
	else if (mAnimationTimer > (ANIMATION_TIME / 10) * 5) {
		mSprite->setTextureRect(sf::IntRect(200, 400, 100, 100));
	}
	else if (mAnimationTimer > (ANIMATION_TIME / 10) * 4) {
		mSprite->setTextureRect(sf::IntRect(200, 300, 100, 100));
	}
	else if (mAnimationTimer > (ANIMATION_TIME / 10) * 3) {
		mSprite->setTextureRect(sf::IntRect(200, 200, 100, 100));
	}
	else if (mAnimationTimer > (ANIMATION_TIME / 10) * 2) {
		mSprite->setTextureRect(sf::IntRect(200, 100, 100, 100));
	}
	else if (mAnimationTimer > (ANIMATION_TIME / 10) * 1) {
		mSprite->setTextureRect(sf::IntRect(200, 0, 100, 100));
	}
	mAnimationTimer += mGame->getDeltaTime();
}
