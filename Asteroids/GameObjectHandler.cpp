#include "GameObjectHandler.h"
#include "Game.h"
#include "iostream"
#include <math.h>

GameObjectHandler::GameObjectHandler(Game* game){
	mGame = game;
	mInvaderAmount = 0;
	mInvaderSpawnClock = 0;
	remainingGameObjects = new GameObjectList();
	mTrashBin = new GameObjectList();
}


GameObjectHandler::~GameObjectHandler(){
	delete mGame;
}

void GameObjectHandler::pruneGameObjects() {

	for (unsigned int i = 0; i < mGame->mGameObjects->size(); i++) {
		if (mGame->mGameObjects->at(i)->getMSprite()->getPosition().y < 0 && mGame->mGameObjects->at(i)->mType != GameObject::ObjectType::SHIP) {
			if (mGame->mGameObjects->at(i)->mType == GameObject::ObjectType::SHIP) {
				mInvaderAmount--;
			}
			mTrashBin->push_back(mGame->mGameObjects->at(i));

		}
		else if (mGame->mGameObjects->at(i)->getMSprite()->getPosition().y > config::GAME_RESOLUTION.height) {
			if (mGame->mGameObjects->at(i)->mType == GameObject::ObjectType::SHIP) {
				mInvaderAmount--;
			}
			mTrashBin->push_back(mGame->mGameObjects->at(i));
		}
		else if (mGame->mGameObjects->at(i)->getMSprite()->getPosition().x < 0) {
			if (mGame->mGameObjects->at(i)->mType == GameObject::ObjectType::SHIP) {
				mInvaderAmount--;
			}
			mTrashBin->push_back(mGame->mGameObjects->at(i));

		}
		else if (mGame->mGameObjects->at(i)->getMSprite()->getPosition().x > config::GAME_RESOLUTION.width) {
			if (mGame->mGameObjects->at(i)->mType == GameObject::ObjectType::SHIP) {
				mInvaderAmount--;
			}
			mTrashBin->push_back(mGame->mGameObjects->at(i));

		}
		else if (mGame->mGameObjects->at(i)->mMarkedForDeletion == true) {
			if (mGame->mGameObjects->at(i)->mType == GameObject::ObjectType::SHIP) {
				mInvaderAmount--;
			}
			mTrashBin->push_back(mGame->mGameObjects->at(i));
		}
		else {
			remainingGameObjects->push_back(mGame->mGameObjects->at(i));
		}
		
		for (unsigned int i = 0; i < mTrashBin->size(); i++) {
			delete mTrashBin->at(i);
		}
		mTrashBin->clear();
		std::cout << mInvaderAmount << std::endl;
		
	}
}
void GameObjectHandler::reformGameObjectList() {
	*mGame->mGameObjects = *remainingGameObjects;
	remainingGameObjects->clear();

}
void GameObjectHandler::checkForCollisions() {
	for (unsigned int i = 0; i < mGame->mGameObjects->size(); i++){
		for (unsigned int j = i + 1; j < mGame->mGameObjects->size(); j++ ) {
			if (getDistanceBetweenObjects(mGame->mGameObjects->at(i), mGame->mGameObjects->at(j)) <= mGame->mGameObjects->at(i)->radius + mGame->mGameObjects->at(j)->radius ) {
				mGame->mGameObjects->at(i)->colide(mGame->mGameObjects->at(j));
				mGame->mGameObjects->at(j)->colide(mGame->mGameObjects->at(i));
			}
		}

	}
}
int GameObjectHandler::getDistanceBetweenObjects(GameObject* obj1, GameObject* obj2) {
	int distanceX = obj1->getMSprite()->getPosition().x - obj2->getMSprite()->getPosition().x;
	int distanceY = obj1->getMSprite()->getPosition().y - obj2->getMSprite()->getPosition().y;
	return sqrt(pow(distanceX, 2) + pow(distanceY, 2));
}

void GameObjectHandler::spawnInvaders(){
	if(mInvaderAmount < INVADER_LIMIT && mInvaderSpawnClock > INVADER_SPAWN_DELAY){
		mGame->mGameObjects->push_back(new Enemy(mGame));
		mInvaderAmount++;
		mInvaderSpawnClock = 0;
	}
		mInvaderSpawnClock += mGame->getDeltaTime();
}

void GameObjectHandler::drawObjects() {
	for (unsigned int i = 0; i < mGame->mGameObjects->size(); i++) {
		if (mGame->mGameObjects->at(i)->mType == GameObject::ObjectType::BULLET) {
			mGame->getWindow()->draw(*mGame->mGameObjects->at(i)->getMSprite());
		}
	}
	for (unsigned int i = 0; i < mGame->mGameObjects->size(); i++) {
		if (mGame->mGameObjects->at(i)->mType == GameObject::ObjectType::SHIP) {
			mGame->getWindow()->draw(*mGame->mGameObjects->at(i)->getMSprite());
		}
	}
	for (unsigned int i = 0; i < mGame->mGameObjects->size(); i++) {
		if (mGame->mGameObjects->at(i)->mType == GameObject::ObjectType::EXPLOSION) {
			mGame->getWindow()->draw(*mGame->mGameObjects->at(i)->getMSprite());
		}
	}
}

