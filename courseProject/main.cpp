
//#include "SFML/Graphics.hpp"
#include "Game.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Game game;
	int srand(time(0));
	game.run();
	
	




	return 0;
}