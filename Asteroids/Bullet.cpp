#include "Bullet.h"
#include "Game.h"


Bullet::Bullet(Game* game, sf::Sprite sprite , GameObject::Faction faction, GameObject::BulletType type){
	mGame = game;
	mSprite = new sf::Sprite;
	mSprite->setTexture(*mGame->getGameTextures());
	if (faction == GameObject::Faction::PLAYER) {
		if (type == BulletType::CENTRAl) {
			mSprite->setTextureRect(sf::IntRect(150, 105, 13, 20));
			mSprite->setOrigin(7, 10);
			mType = ObjectType::BULLET;
			mFaction = Faction::PLAYER;
			radius = 7;
			mMovement = sf::Vector2f(0, -BULLET_SPEED);
			mSprite->setPosition(sprite.getPosition());

		}
		else if(type == BulletType::LEFT){
			mSprite->setTextureRect(sf::IntRect(154, 127, 11, 14));
			mSprite->setOrigin(5, 7);
			mType = ObjectType::BULLET;
			mFaction = Faction::PLAYER;
			radius = 5;
			mMovement = sf::Vector2f(-BULLET_ANGLE_SPEED, -BULLET_SPEED);
			mSprite->setPosition(sprite.getPosition());
			mSprite->rotate(-45);

		}
		else if (type == BulletType::RIGHT) {
			mSprite->setTextureRect(sf::IntRect(154, 127, 11, 14));
			mSprite->setOrigin(5, 7);
			mType = ObjectType::BULLET;
			mFaction = Faction::PLAYER;
			radius = 5;
			mMovement = sf::Vector2f(BULLET_ANGLE_SPEED, -BULLET_SPEED);
			mSprite->setPosition(sprite.getPosition());
			mSprite->rotate(45);
		}

	}
	else if (faction == Faction::ENEMY) {
		mSprite->setTextureRect(sf::IntRect(168, 106, 12, 18));
		mSprite->setOrigin(6, 9);
		mType = ObjectType::BULLET;
		mFaction = Faction::ENEMY;
		radius = 6;
		mMovement = sf::Vector2f(0, BULLET_SPEED);
		mSprite->setPosition(sprite.getPosition());
		mSprite->rotate(180);
	}
}


Bullet::~Bullet()
{
}

void Bullet::update(){
	mSprite->move(mMovement * mGame->getDeltaTime());
}

void Bullet::spawn()
{
}

void Bullet::colide(GameObject * objectColidedWith){
	if (mFaction != objectColidedWith->mFaction) {
		mMarkedForDeletion = true;
	}
}
