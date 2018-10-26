#pragma once
#include "GameObject.h"
#include <string>
#include <random>
#include <iostream>
class Asteroid :
	public GameObject
{
public:
	//Constructor
	Asteroid(Game* mGamePointer);
	~Asteroid();
	//Function that runs every frame and updates the state of the asteroid
	void update()override;
	//Function that draws the asteroid on the screen (missleading name? Spawning functions handled by the constructor
	void spawn()override;
	//Function that handles the collision behaviour of asteroids
	void colide(GameObject* objectColidedWith) override;
private:
	//Random generator
	std::mt19937 mRandomGen;
	//Vector that stores the asteroids constant movement across the screen
	sf::Vector2f mAsteroidMovement;
	//Int that stores the asteroids rotation speed
	int mAsteroidRotation;


};


