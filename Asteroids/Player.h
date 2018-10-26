#pragma once
#include "GameObject.h"
#include <iostream>

class Player : public GameObject{

public:
	Player(Game* mGamePointer);
	~Player();
	void movement();
	void update() override;
	void spawn() override;
	void colide(GameObject* objectColidedWith)override;
};
namespace {
	int PLAYER_FOWARD_SPEED = 350;
	int PLAYER_ROTATION_SPEED = 250;
}

