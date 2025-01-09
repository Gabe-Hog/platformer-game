#ifndef GAME_H
#define GAME_H
#include "Timer.h"
#include "GameObjects.h"
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Enemy.h"
#include "Platform.h"
#include <vector>
#include "Timer.h"
#include "assetHandler.h"
#include <stdlib.h>

using namespace std;

static float WIDTH = 900;
static float HEIGHT = 600;

class Game
{
private:
	sf::RenderWindow window;
	Timer timer;
	sf::Sprite windowBackground;
	sf::Texture windowBackgroundTexture;
	assetHandler<sf::Font>* fontHandler = new assetHandler<sf::Font>;
	assetHandler<sf::Texture>* textureHandler = new assetHandler<sf::Texture>;
	vector<GameObjects*> objects;
	bool roundEnded = false;
	
	void eventHandle();
	void update(float dTime);
	void render();
	void updateObjectPosition(float dTime);
	void makeCollisionCheck();
	void prepareGame();
	void initGameObjects();
	void initBackground();
	void endRound(const Player&);
	void writeScoreToFile(string score);
	void updatePlayersScore(const Player& player);
public:
	
	Game();
	Game(const Game& other);
	~Game();
	void run();
	bool addObject(GameObjects* aObject);
	

	
	

	



};

#endif