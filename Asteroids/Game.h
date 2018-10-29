#pragma once
#include <vector>
#include <string>
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "GameObjectHandler.h"
#include "SFML/Graphics.hpp"
class Game{
	typedef std::vector<GameObject*> GameObjectList;
public:
	Game();
	~Game();
	void run();
	float getDeltaTime();
	sf::Texture* getGameTextures();
	sf::RenderWindow* getWindow();
	GameObjectList* mGameObjects;

	void setGameIsntOver(bool newValue);
private:
	float mDeltaTime;

	sf::Texture* mGameTextures;
	sf::RenderWindow* mWindow;
	bool mGameIsntOver;
	Game* mGamePointer;
	sf::Clock* mGameClock;
	GameObjectHandler* mGameObjectHandler;
};
namespace config{
	const sf::VideoMode GAME_RESOLUTION = sf::VideoMode(1980, 1020);
	const std::string WINDOW_TITLE = "Asteroids";
	const std::string TEXTURE_PATH = "./Textures/Textures.png";
	const int FRAMERATE_LIMIT = 60;
	const sf::Color BACKGROUND_COLOR = sf::Color::Black;
};

