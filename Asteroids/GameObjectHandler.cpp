#include "GameObjectHandler.h"
#include "Game.h"
#include "Asteroid.h"
#include "iostream"
#include <math.h>

GameObjectHandler::GameObjectHandler(Game* game){
	mGame = game;
	mAsteroidAmount = 0;
	remainingGameObjects = new GameObjectList();
	mTrashBin = new GameObjectList();
}


GameObjectHandler::~GameObjectHandler(){
	delete mGame;
}
void GameObjectHandler::spawnAsteroids() {
	mAsteroidSpawnClock += mGame->getDeltaTime();
	while (mAsteroidAmount < BASE_NUMBER_OF_ASTEROIDS +(ASTEROID_SPAWN_DELTA * mGame->getLevel()) && mAsteroidSpawnClock > ASTEROID_SPAWN_DELAY){
		mGame->mGameObjects->push_back(new Asteroid(mGame));
		mAsteroidAmount++;
		mAsteroidSpawnClock = 0;
	};
}
void GameObjectHandler::pruneGameObjects() {

	for (unsigned int i = 0; i < mGame->mGameObjects->size(); i++) {
		if (mGame->mGameObjects->at(i)->getMSprite()->getPosition().y < 0) {
			mTrashBin->push_back(mGame->mGameObjects->at(i));
			mAsteroidAmount--;
		}
		else if (mGame->mGameObjects->at(i)->getMSprite()->getPosition().y > 600) {
			mTrashBin->push_back(mGame->mGameObjects->at(i));
			mAsteroidAmount--;
		}
		else if (mGame->mGameObjects->at(i)->getMSprite()->getPosition().x < 0) {
			mTrashBin->push_back(mGame->mGameObjects->at(i));
			mAsteroidAmount--;
		}
		else if (mGame->mGameObjects->at(i)->getMSprite()->getPosition().x > 800) {
			mTrashBin->push_back(mGame->mGameObjects->at(i));
			mAsteroidAmount--;
		}
		else if (mGame->mGameObjects->at(i)->mMarkedForDeletion == true) {
			mTrashBin->push_back(mGame->mGameObjects->at(i));
			mAsteroidAmount--;
		}
		else {
			remainingGameObjects->push_back(mGame->mGameObjects->at(i));
		}
		
		for (unsigned int i = 0; i < mTrashBin->size(); i++) {
			delete mTrashBin->at(i);
		}
		mTrashBin->clear();
		
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
