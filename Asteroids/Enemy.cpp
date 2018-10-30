#include "Enemy.h"
#include "Game.h"
#include "Explosion.h"

Enemy::Enemy(Game* game){
	mGame = game;
	mSprite = new sf::Sprite;
	mSprite->setTexture(*mGame->getGameTextures());
	mSprite->setTextureRect(sf::IntRect(0, 105, 147, 221-105));
	mSprite->setOrigin(53, 58);
	mType = ObjectType::SHIP;
	mFaction = Faction::ENEMY;
	radius = 58;
	mSprite->rotate(180);

	mSprite->setPosition(Tools::generateRandomFloat(0.0f + radius, config::GAME_RESOLUTION.width - radius), 0 - radius*2);
	mMovementVector = sf::Vector2f(Tools::generateRandomFloat(MIN_X_SPEED, MAX_X_SPEED), Tools::generateRandomFloat(MIN_Y_SPEED, MAX_Y_SPEED));
}


Enemy::~Enemy()
{
}

void Enemy::update(){
	movement();
	constrain();
	fire();
}

void Enemy::spawn()
{
}

void Enemy::colide(GameObject * objectColidedWith){
	if (objectColidedWith->mFaction == Faction::PLAYER) {
		mMarkedForDeletion = true;
		mGame->mGameObjects->push_back(new Explosion(mGame, this));

	}
}

void Enemy::fire(){
	if (mFireDelta > Tools::generateRandomFloat(MIN_FIRE_DELAY, MAX_FIRE_DELAY)) {
		mGame->mGameObjects->push_back(new Bullet(mGame, *mSprite, mFaction, BulletType::CENTRAl));
		mFireDelta = 0;
	}
	mFireDelta += mGame->getDeltaTime();
}

void Enemy::constrain(){
	if (mSprite->getPosition().x < 0 + radius || mSprite->getPosition().x > config::GAME_RESOLUTION.width - radius) {
		mMovementVector.x = -mMovementVector.x;
	}
}

void Enemy::movement(){
	mSprite->move(mMovementVector * mGame->getDeltaTime());
}
