#pragma once
#include <vector>
#include "GameObject.h"
//Type def to shorten the variable name for the GameObjectList
typedef std::vector<GameObject*> GameObjectList;
//Name inclusion to stop circular inclusion
class Game;
class GameObjectHandler
{

public:
	//Constructor
	GameObjectHandler(Game* game);
	~GameObjectHandler();
	//Function that spawns new asteroids if the spawn delay is big enough and if there aren't enough asteroids on the screen
	void spawnAsteroids();
	//Function som tar bort object som lämnat skärmen eller object som är märkta för borttagning
	void pruneGameObjects();
	//Reparerar listan men spel object efter den blivit manipulerad
	void reformGameObjectList();
	//Function som kollar om object kolliderar och kör collisions beteendet för båda objecten om dem gör det
	void checkForCollisions();
	//Function that returns the distance between two objects
	int getDistanceBetweenObjects(GameObject* obj1, GameObject* obj2);
private:
	//Counter that keep track of how many asteroids are on the screen
	int mAsteroidAmount;
	//Timer that delay between asteroid spawns
	float mAsteroidSpawnClock;
	//Pointer to the game instance to give access to variables
	Game* mGame; 
	//Tempoary list with gameobjects that are supposed to be deleted
	GameObjectList* mTrashBin;
	//Tempoary list with gameobjects that are keept after pruning
	GameObjectList* remainingGameObjects;

};
//Constant config variables
namespace {
	const int BASE_NUMBER_OF_ASTEROIDS = 5;
	const double ASTEROID_SPAWN_DELTA = 0.5;
	const float ASTEROID_SPAWN_DELAY = 0.1f;
}

