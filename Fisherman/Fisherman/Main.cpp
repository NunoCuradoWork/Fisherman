#include "Game.h"
#include "Ship.h"
#include "Map.h"
#include "Config.h"
#include <vector>
#include <iostream>


int main()
{
	Game game;
	Map map;
	Config config("configFile.txt");


	config.getConfigFromFile(map);
	map.createMap();
	config.setInitialMap(map);
	map.printMap();


	std::cout << "END" << std::endl;
}