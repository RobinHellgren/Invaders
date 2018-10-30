#pragma once
#include "GameObject.h"
#include "Enemy.h"
class Explosion :
	public GameObject
{
public:
	Explosion(Game* game, Enemy* enemy);
	~Explosion();
	void update() override;
	void spawn() override;
	void colide(GameObject* objectColidedWith)override;
private:
	void animate();
	float mAnimationTimer;

};
namespace { const float ANIMATION_TIME = 0.5f; }

