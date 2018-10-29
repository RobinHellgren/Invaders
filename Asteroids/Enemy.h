#pragma once
#include "GameObject.h"
#include "Tools.h"
class Enemy :
	public GameObject
{
public:
	Enemy(Game* game);
	~Enemy();
	void update() override;
	void spawn() override;
	void colide(GameObject* objectColidedWith)override;
private:
	void fire();
	void constrain();
	void movement();
	float mFireDelta;
	sf::Vector2f mMovementVector;
};
namespace {
	const float MAX_X_SPEED = 350;
	const float MIN_X_SPEED = -350;

	const float MAX_Y_SPEED = 250;
	const float MIN_Y_SPEED = 100;

	const float MAX_FIRE_DELAY = 5.0;
	const float MIN_FIRE_DELAY = 0.2;
}

