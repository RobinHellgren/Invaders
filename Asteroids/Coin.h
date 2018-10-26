#pragma once
#include "GameObject.h"
#include "Game.h"
#include <random>
class Coin :
	public GameObject
{
public:
	Coin(Game* game);
	~Coin();
	void update() override;
	void spawn() override;
	void colide(GameObject* objectColidedWith)override;
	void setRandomLocation();
private:
	std::mt19937 mRandomGen;
	float mSpawnDelay;
	float mGameOverTimer;
	bool mInPlay;
};

