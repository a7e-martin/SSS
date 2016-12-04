#include <stdio.h>
#include <iostream>

#include "game.h"
#include "log.h"

int main(int argc, char* argv[]) {

	Game game;
	try
	{
		gLog.init();
	}
	catch (int)
	{
		exit(2);
	}

	if (game.Init())
	{
		game.Load();
		
		game.Loop();
		game.Quit();
	}
	LOG("Exit\n\n");
	gLog.close();

	return 0;
}