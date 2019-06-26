#include "Game.h"


#include <vector>
#include <iostream>


int main()
{
	Game game;
	game.setInitialGraphicalOptions();


	bool isRunning = true;


	
	game.initSettings();
	game.paintMap();

	//while (isRunning)
	//{
	//	
	//	game.runGame();

	//	
	//	isRunning = false;
	//}
	
	std::cout << "END" << std::endl;
	return 0;

}