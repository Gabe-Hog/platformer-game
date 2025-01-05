#include "Game.h"
#include <stdlib.h>
#include <iostream>
#include <Windows.h>

using namespace std;


BOOL WINAPI catchWrongfulClosing(DWORD signal);
Game* game;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	game = new Game();
	int srand(time(0));
	SetConsoleCtrlHandler(catchWrongfulClosing, TRUE);
	game->run();
	
	delete game;
	return 0;
}


BOOL WINAPI catchWrongfulClosing(DWORD signal)
{
	if (signal == CTRL_CLOSE_EVENT)
	{

		cout << "Caught WrongFul Closing! Memory will be cleaned" << endl;
		delete game;
		return TRUE;
	}
	return FALSE;
}