#ifndef GAME_H
#define GAME_H
#include "Timer.h"
#include "GameObjects.h"
#include "SFML/Graphics.hpp"
#include "GameObjects.h"
#include "Player.h"
#include "Monster.h"
#include "Platform.h"

using namespace std;
static int WIDTH = 900;
static int HEIGHT = 600;
class Game
{
private:
	sf::RenderWindow window;
	Platform platform;

	void eventHandle();
	void update();
	void render();


public:

	Game();
	~Game();
	void run();
	bool addObject();
	



};

#endif