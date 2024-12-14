
//#include "SFML/Graphics.hpp"
#include "Game.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Game game;

	game.run();
	
	



	/*sf::RenderWindow window(sf::VideoMode(800, 800), "test");
	sf::Event e;
	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}
	}*/

	return 0;
}