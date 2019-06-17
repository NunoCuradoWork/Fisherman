#include "Game.h"
#include "Config.h"
#include "Map.h"
#include "Player.h"


Game::Game()
{
	turn = 0;
	config = new Config("configFile.txt");
	map = new Map();
}

void Game::execConfig()
{
	config->Config::getConfigFromFile(map);
	map->Map::createMap();
	config->Config::setInitialMap(map);
}
