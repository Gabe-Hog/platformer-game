#include "Game.h"
#include <stdlib.h>
#include <iostream>
#include <Windows.h>

using namespace std;


BOOL WINAPI catchWrongfulClosing(DWORD signal);



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	SetConsoleCtrlHandler(catchWrongfulClosing, TRUE);
	
	Game game;

	int srand(time(0));
	game.run();

	return 0;
}


BOOL WINAPI catchWrongfulClosing(DWORD signal)
{
	if (signal == CTRL_CLOSE_EVENT)
	{
		cout << "Caught WrongFul Closing! Memory will be cleaned" << endl;
		return TRUE;
	}
	return FALSE;
}
