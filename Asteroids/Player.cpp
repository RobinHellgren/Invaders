#include "Player.h"
#include "Game.h"



Player::Player(Game* mGamePointer){
	mGame = mGamePointer;
	mSprite = new sf::Sprite;
	mSprite->setTexture(*mGame->getGameTextures());
	mSprite->setTextureRect(sf::IntRect(0, 0, 96, 105));
	mSprite->setPosition(400, 0);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		mSprite->move(-PLAYER_FOWARD_SPEED * mGame->getDeltaTime(), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		mSprite->move(PLAYER_FOWARD_SPEED * mGame->getDeltaTime(), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		mSprite->move(0, -PLAYER_FOWARD_SPEED * mGame->getDeltaTime());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		mSprite->move(0, PLAYER_FOWARD_SPEED * mGame->getDeltaTime());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		fire();
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
		mSprite->move(PLAYER_FOWARD_SPEED * mGame->getDeltaTime(), 0);
	}
	if (mSprite->getPosition().x > config::GAME_RESOLUTION.width - radius) {
		mSprite->move(-PLAYER_FOWARD_SPEED * mGame->getDeltaTime(), 0);
	}
	if (mSprite->getPosition().y < 0 + radius) {
		mSprite->move(0, PLAYER_FOWARD_SPEED * mGame->getDeltaTime());
	}
	if (mSprite->getPosition().y > config::GAME_RESOLUTION.height - radius) {
		mSprite->move(0, -PLAYER_FOWARD_SPEED * mGame->getDeltaTime());
	}
}
