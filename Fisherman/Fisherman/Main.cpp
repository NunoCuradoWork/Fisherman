#include "Game.h"
#include "Ship.h"
#include "Map.h"
#include "Config.h"
#include <vector>
#include <iostream>




int main()
{
	Game game;
	bool isRunning = true;


	game.initSettings();
	game.printPlayers();

	while (isRunning)
	{
		game.receiveLineCommands();
		isRunning = false;
	}
	
	std::cout << "END" << std::endl;
	return 0;
}