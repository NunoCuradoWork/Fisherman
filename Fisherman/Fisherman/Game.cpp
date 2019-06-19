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
}

void Game::enterCommands()
{
	getCommandLine().receiveLineCommands();
}

void Game::executeCommands()
{
	std::string command;


	for (int i = 0; i < commandLine.getListofCommands().size(); i++)
	{

		if (commandLine.getListofCommands().at(i).command.compare("sair") == 0)
		{

		}
		else if (commandLine.getListofCommands().at(i).command.compare("delg") == 0)
		{

		}
		else if (commandLine.getListofCommands().at(i).command.compare("loadg") == 0)
		{

		}
		else if (commandLine.getListofCommands().at(i).command.compare("saveg") == 0)
		{

		}
		else if (commandLine.getListofCommands().at(i).command.compare("comprasold") == 0)
		{

		}
		else if (commandLine.getListofCommands().at(i).command.compare("vaipara") == 0)
		{
			if (commandLine.getListofCommands().at(i).arguments.size() == 2)
			{

			}
			else
			{

			}

		}
		else if (commandLine.getListofCommands().at(i).command.compare("evnav") == 0)
		{

		}
		else if (commandLine.getListofCommands().at(i).command.compare("evpos") == 0)
		{

		}
		else if (commandLine.getListofCommands().at(i).command.compare("pirata") == 0)
		{

		}
		else if (commandLine.getListofCommands().at(i).command.compare("stop") == 0)
		{

		}
		else if (commandLine.getListofCommands().at(i).command.compare("auto") == 0)
		{

		}
		else if (commandLine.getListofCommands().at(i).command.compare("move") == 0)
		{

		}
		else if (commandLine.getListofCommands().at(i).command.compare("vende") == 0)
		{

		}
		else if (commandLine.getListofCommands().at(i).command.compare("compra") == 0)
		{

		}
		else if (commandLine.getListofCommands().at(i).command.compare("lista") == 0)
		{

		}
		else if (commandLine.getListofCommands().at(i).command.compare("vendenav") == 0)
		{

		}
		else if (commandLine.getListofCommands().at(i).command.compare("compranav") == 0)
		{

		}
		else if (commandLine.getListofCommands().at(i).command.compare("exec") == 0)
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
