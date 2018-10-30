#include "Player.h"
#include "Game.h"



Player::Player(Game* mGamePointer){
	mGame = mGamePointer;
	mSprite = new sf::Sprite;
	mSprite->setTexture(*mGame->getGameTextures());
	mSprite->setTextureRect(sf::IntRect(0, 0, 96, 105));
	mSprite->setPosition(config::GAME_RESOLUTION.width/2, config::GAME_RESOLUTION.height - radius);
	mSprite->setOrigin(48, 52.5f);
	mType = ObjectType::SHIP;
	mFaction = Faction::PLAYER;
	radius = 35;
	mHealth = 5;
}


Player::~Player(){
	delete mSprite;
}


void Player::movement() {
	mMovement = sf::Vector2f(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		mMovement.x += -PLAYER_FOWARD_SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		mMovement.x += PLAYER_FOWARD_SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		mMovement.y += -PLAYER_FOWARD_SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		mMovement.y += PLAYER_FOWARD_SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		fire();
	}
	if (mMovement.x != 0 || mMovement.y != 0) {
		mSprite->setTextureRect(sf::IntRect(100, 0, 89, 96));
		mSprite->move(mMovement * mGame->getDeltaTime());
	}
	else {
		mSprite->setTextureRect(sf::IntRect(0, 0, 96, 105));
	}

}
void Player::fire(){
	if (mFireTimer > FIRE_DELAY) {
		mGame->mGameObjects->push_back(new Bullet(mGame, *mSprite, mFaction, BulletType::CENTRAl));
		mGame->mGameObjects->push_back(new Bullet(mGame, *mSprite, mFaction, BulletType::LEFT));
		mGame->mGameObjects->push_back(new Bullet(mGame, *mSprite, mFaction, BulletType::RIGHT));
		mFireTimer = 0;
	}
	mFireTimer += mGame->getDeltaTime();

}
void  Player::update() {
	movement();
	constrain();

	if (mHealth <= 0) {
		mGame->setGameIsntOver(false);
	}
}
void Player::spawn() {
	
}

void Player::colide(GameObject* objectColidedWith){
	if (objectColidedWith->mFaction == Faction::ENEMY) {
		mHealth--;
	}
}

void Player::constrain(){
	if (mSprite->getPosition().x < 0 + radius) {
		mSprite->move(PLAYER_FOWARD_SPEED  * mGame->getDeltaTime(), 0);
	}
	if (mSprite->getPosition().x > config::GAME_RESOLUTION.width - radius) {
		mSprite->move(-PLAYER_FOWARD_SPEED  *  mGame->getDeltaTime(), 0);
	}
	if (mSprite->getPosition().y < 0 + radius) {
		mSprite->move(0, PLAYER_FOWARD_SPEED  * mGame->getDeltaTime());
	}
	if (mSprite->getPosition().y > config::GAME_RESOLUTION.height - radius) {
		mSprite->move(0, -PLAYER_FOWARD_SPEED * mGame->getDeltaTime());
	}
}
