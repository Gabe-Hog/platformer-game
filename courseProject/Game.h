#ifndef GAME_H
#define GAME_H
#include "Timer.h"
#include "GameObjects.h"
#include "SFML/Graphics.hpp"
#include "GameObjects.h"
#include "Player.h"
#include "Monster.h"
#include "Platform.h"
#include <vector>
#include "Timer.h"
using namespace std;
static float WIDTH = 900;
static float HEIGHT = 600;
class Game
{
private:
	sf::RenderWindow window;
	Timer timer;
	vector<GameObjects*> objects;
	bool roundEnded = false;
	void eventHandle();
	void update(float dTime);
	void render();


public:
	void initGameObjects();
	
	Game();
	~Game();
	void run();
	bool addObject(GameObjects* aObject);
	void updateObjectPosition(float dTime);
	void makeCollisionCheck();
	static void updatePlayersScore(const Player& player);
	void endRound(const Player&);
	void writeScoreToFile(string score);
	void startMainMenu();
	



};

#endif