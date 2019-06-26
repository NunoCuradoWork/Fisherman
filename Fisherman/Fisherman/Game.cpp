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
	config.Config::setStatsFromConfig();
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

void Game::runGame()
{
	enterCommands();
	executeCommands();
	combatePhase();
	eventPhase();
	piratePhase();
}

void Game::paintMap()
{
	//map.Map::printMap();
	map.drawMapBorders();
	map.drawLogBorders();
	map.cmdLineBorders();
	
}

void Game::setInitialGraphicalOptions()
{
	Consola::setScreenSize(150, 300);
}

void Game::enterCommands()
{
	getCommandLine().receiveLineCommands();
}

void Game::executeCommands()
{
	std::string cmd;



	for (int i = 0; i < commandLine.getListofCommands().size(); i++)
	{
		cmd = commandLine.getListofCommands().at(i).command;

		if (cmd.compare("sair") == 0)
		{

		}
		else if (cmd.compare("delg") == 0)
		{

		}
		else if (cmd.compare("loadg") == 0)
		{

		}
		else if (cmd.compare("saveg") == 0)
		{

		}
		else if (cmd.compare("comprasold") == 0)
		{

		}
		else if (cmd.compare("vaipara") == 0)
		{
			if (commandLine.getListofCommands().at(i).arguments.size() == 2)
			{

			}
			else
			{

			}

		}
		else if (cmd.compare("evnav") == 0)
		{

		}
		else if (cmd.compare("evpos") == 0)
		{

		}
		else if (cmd.compare("pirata") == 0)
		{

		}
		else if (cmd.compare("stop") == 0)
		{

		}
		else if (cmd.compare("auto") == 0)
		{

		}
		else if (cmd.compare("move") == 0)
		{

		}
		else if (cmd.compare("vende") == 0)
		{

		}
		else if (cmd.compare("compra") == 0)
		{

		}
		else if (cmd.compare("lista") == 0)
		{

		}
		else if (cmd.compare("vendenav") == 0)
		{

		}
		else if (cmd.compare("compranav") == 0)
		{

		}
		else if (cmd.compare("exec") == 0)
		{

		}
	}
}

void Game::combatePhase()
{
}

void Game::eventPhase()
{
}

void Game::piratePhase()
{
}

CommandLine& Game::getCommandLine()
{
	return commandLine;
}
