#pragma once
#include "GameObject.h"
class Bullet :
	public GameObject
{
public:
	Bullet(Game* game, sf::Sprite sprite , Faction faction, BulletType type);
	~Bullet();
	void update() override;
	void spawn() override;
	void colide(GameObject* objectColidedWith)override;

private:
	sf::Vector2f mMovement;
};
namespace {
	const float BULLET_SPEED = 400;
	const float BULLET_ANGLE_SPEED = 250;
}

