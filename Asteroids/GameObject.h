#pragma once
#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>
class Game;
class GameObject {
	
public:
	enum class ObjectType { PLAYER, ASTEROID, COIN };
	GameObject();
	~GameObject();
	
	virtual void spawn() = 0;
	virtual void update()= 0;
	virtual void colide(GameObject* objectColidedWith) = 0;
	sf::Sprite* getMSprite();
	
	ObjectType mType;
	int radius;
	Game* mGame;
	sf::Sprite* mSprite;
	bool mMarkedForDeletion;

};