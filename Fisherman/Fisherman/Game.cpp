#include "Game.h"
#include "Player.h"
#include <iostream>
#include <string>



Game::Game():turn(0)
{
}

Game::~Game()
{
}

Map& Game::getMap()
{
	return map;
}

Config& Game::getConfig()
{
	return config;
}

void Game::initSettings()
{
	config.Config::getConfigFromFile(&map);
	map.Map::createMap();
	config.Config::setInitialMap(&map);
	createPlayers();
}

void Game::createPlayers()
{
	Player* setPlayer = new Player ("Player");
	Player* setPirate = new Player ("Pirate");

	players.push_back(setPlayer);
	players.push_back(setPirate);
}

void Game::printPlayers()
{
	for (int i = 0; i < players.size(); i++)
		std::cout << players[i]->getName() << ' ' << players[i]->getWealth() << std::endl;
}

void Game::receiveLineCommands()
{
	std::string input;
	commandLine.getListofCommands().clear();

	while (input.compare("prox") != 0)
	{
		std::getline(std::cin, input);
		commandLine.getListofCommands().push_back(input);
	}
}
