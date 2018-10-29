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
	//Function som tar bort object som lämnat skärmen eller object som är märkta för borttagning
	void pruneGameObjects();
	//Reparerar listan men spel object efter den blivit manipulerad
	void reformGameObjectList();
	//Function som kollar om object kolliderar och kör collisions beteendet för båda objecten om dem gör det
	void checkForCollisions();
	//Function that returns the distance between two objects
	int getDistanceBetweenObjects(GameObject* obj1, GameObject* obj2);
	void spawnInvaders();
	void drawObjects();
private:
	//Counter that keep track of how many asteroids are on the screen
	int mInvaderAmount;
	//Timer that delay between asteroid spawns
	float mInvaderSpawnClock;
	//Pointer to the game instance to give access to variables
	Game* mGame; 
	//Tempoary list with gameobjects that are supposed to be deleted
	GameObjectList* mTrashBin;
	//Tempoary list with gameobjects that are keept after pruning
	GameObjectList* remainingGameObjects;

};
//Constant config variables
namespace {
	const int INVADER_LIMIT = 10;
	const float INVADER_SPAWN_DELAY = 1.0f;
}

