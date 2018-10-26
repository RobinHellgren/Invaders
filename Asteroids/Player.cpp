#include "Player.h"
#include "Game.h"



Player::Player(Game* mGamePointer){
	mGame = mGamePointer;
	mSprite = new sf::Sprite;
	mSprite->setTexture(*mGame->getGameTextures());
	mSprite->setTextureRect(sf::IntRect(16, 0, 32, 34));
	mSprite->setPosition(400, 300);
	mSprite->setOrigin(16, 16);
	mType = ObjectType::PLAYER;
	radius = 16;
}


Player::~Player(){
	delete mSprite;
}


void Player::movement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		getMSprite()->rotate(mGame->getDeltaTime() * -PLAYER_ROTATION_SPEED);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		getMSprite()->rotate(mGame->getDeltaTime() * PLAYER_ROTATION_SPEED);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		float x = sinf(getMSprite()->getRotation() * 3.14 / 180) * PLAYER_FOWARD_SPEED;
		float y = -cosf(getMSprite()->getRotation() * 3.14 / 180) * PLAYER_FOWARD_SPEED;
		if (getMSprite()->getPosition().x > (800 - radius)) {
			x -= PLAYER_FOWARD_SPEED;
		}
		if (getMSprite()->getPosition().x < (0 + radius)) {
			x += PLAYER_FOWARD_SPEED;
		}
		if (getMSprite()->getPosition().y > (600 - radius)) {
			y-= PLAYER_FOWARD_SPEED;
		}
		if (getMSprite()->getPosition().y < 0 + radius) {
			y+= PLAYER_FOWARD_SPEED;
		}
		getMSprite()->move(x * mGame->getDeltaTime(), y * mGame->getDeltaTime());
	}	
}
void  Player::update() {
	movement();
	mGame->getWindow()->draw(*getMSprite());
}
void Player::spawn() {
	mGame->getWindow()->draw(*mSprite);
}

void Player::colide(GameObject* objectColidedWith){
	if (objectColidedWith->mType == ObjectType::ASTEROID) {
		mGame->setGameIsntOver(false);
	}
	if (objectColidedWith->mType == ObjectType::COIN) {

	}
}
