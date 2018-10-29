#include "Game.h"

Game::Game(){

	mGameTextures = new sf::Texture;
	if(!mGameTextures->loadFromFile(config::TEXTURE_PATH)){
		std::cout << "Error  loading textures" << std::endl;
	}
	mGameObjects = new GameObjectList;
	mGameObjects->push_back(new Player(this));
	mGameClock = new sf::Clock;
	mGameObjectHandler = new GameObjectHandler(this);
	mWindow = new sf::RenderWindow(config::GAME_RESOLUTION, config::WINDOW_TITLE);
	mWindow->setFramerateLimit(config::FRAMERATE_LIMIT);
	
	mGameIsntOver = true;

	

	for (unsigned int i = 0; i < mGameObjects->size(); i++) {
		mGameObjects->at(i)->spawn();
	}
}


Game::~Game(){
}
void Game::run() {

	while (mWindow->isOpen() && mGameIsntOver) {
		mDeltaTime = mGameClock->restart().asSeconds();
		sf::Event event;
		while (mWindow->pollEvent(event)) {
			
			if (event.type == sf::Event::Closed) {
				mWindow->close();
				return;
			}
		}

		mWindow->clear(config::BACKGROUND_COLOR);
		for (unsigned int i = 0; i < mGameObjects->size(); i++) {
			mGameObjects->at(i)->update();
		}
		mGameObjectHandler->spawnInvaders();
		mGameObjectHandler->checkForCollisions();
		mGameObjectHandler->drawObjects();
		mGameObjectHandler->pruneGameObjects();
		mGameObjectHandler->reformGameObjectList();

		mWindow->display();


	}
}
float Game::getDeltaTime() {
	return mDeltaTime;
}
void Game::setGameIsntOver(bool newValue) {
	mGameIsntOver = newValue;
}
sf::Texture* Game::getGameTextures() {
	return mGameTextures;
}
sf::RenderWindow* Game::getWindow() {
	return mWindow;
}



