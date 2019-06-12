#include "Game.h"
#include "Ship.h"
#include "Map.h"
#include "Config.h"

int main()
{
	Game game;
	Map map;

	Config config("configFile.txt");
	config.readFile(map);
	map.createMap();
	map.printMap();

}