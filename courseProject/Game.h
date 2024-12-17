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
	Timer clock;
	vector<GameObjects*> objects;
	void eventHandle();
	void update(float dTime);
	void render();


public:

	Game();
	~Game();
	void run();
	bool addObject(GameObjects* aObject);
	



};

#endif