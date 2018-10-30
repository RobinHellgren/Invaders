#pragma once
#include "GameObject.h"
#include <iostream>
#include "Bullet.h"

class Player : public GameObject{

public:
	Player(Game* mGamePointer);
	~Player();

	void update() override;
	void spawn() override;
	void colide(GameObject* objectColidedWith)override;
private:
	void constrain();
	void movement();
	void fire();

	sf::Vector2f mMovement;
	float mFireTimer;
	int mHealth;
};
namespace {
	const float PLAYER_FOWARD_SPEED = 350;
	const float FIRE_DELAY = 0.2;
}

