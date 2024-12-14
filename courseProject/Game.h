#ifndef GAME_H
#define GAME_H
#include "Timer.h"
#include "GameObjects.h"
#include "SFML/Graphics.hpp"


using namespace std;

class Game
{
private:
	sf::RenderWindow window;
	
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