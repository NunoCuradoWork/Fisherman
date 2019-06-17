#include "Config.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "Map.h"
#include "Tile.h"


Config::Config(std::string filename)
{
	this->filename = filename;
	this->column = 0;
	this->row = 0;
	this->wealth = 0;
	this->portSoldiers = 0;
	this->pirateRate = 0;
	this->stormRate = 0;
	this->sirenRate = 0;
	this->stillRate = 0;
	this->riotRate = 0;
	this->eventRate = 0;
	this->shipPrice = 0;
	this->soldierPrice = 0;
	this->sellFishPrice = 0;
	this->buyCargoPrice = 0;
	this->sellCargoPrice = 0;
}

void Config::getConfigFromFile(Map* map)
{
	std::ifstream myfile(getFilename());
	std::string token;
	char mapSymbols;
	int value;
	int counter = 0;
	int mapCounter = 0;

	if (myfile.is_open())
	{
		std::string line;
		while (std::getline(myfile, line))
		{
			std::istringstream iss(line);
			if (counter == 0)
			{
				iss >> token >> value;
				map->setRowSize(value);
			}
			else if (counter == 1)
			{
				iss >> token >> value;
				map->setColumnSize(value);
			}
			else if (counter > map->getRowSize()+1)
			{
				iss >> token >> value; 
				stats.push_back(value);
			}
			else
			{
				std::vector<char> aux;
				while(iss.get(mapSymbols))
				{
					aux.push_back(mapSymbols);
				}
				mapChar.push_back(aux);
			}
			counter++;
		}
	}
	else
	{
		std::cout << "ERROR, cannot open configFile" << std::endl;
	}
	myfile.close();
}

void Config::setStatsFromConfig()
{
	for (int i = 0; i < stats.size(); i++)
	{
		switch (i)
		{
			case Stats::WEALTH:
				setWealth(stats[i]);
				break;

			case Stats::PIRATERATE:
				setPirateRate(stats[i]);
				break;

			case Stats::SHIPPRICE:
				setShipPrice(stats[i]);
				break;

			case Stats::SOLDERPRICE:
				setSoldierPrice(stats[i]);
				break;

			case Stats::SELLFISHPRICE:
				setSellFishPrice (stats[i]);
				break;

			case Stats::BUYCARGOPRICE:
				setBuyCargoPrice(stats[i]);
				break;

			case Stats::SELLCARGOPRICE:
				setSellCargoPrice(stats[i]);
				break;

			case Stats::PORTSOLDIERS:
				setPortSoldiers(stats[i]);
				break;

			case Stats::EVENTRATE:
				setEventRate(stats[i]);
				break;

			case Stats::STORMRATE:
				setStormRate(stats[i]);
				break;

			case Stats::SIRENRATE:
				setSirenRate(stats[i]);
				break;

			case Stats::STILLRATE:
				setStillRate(stats[i]);
				break;

			case Stats::RIOTRATE:
				setRiotRate(stats[i]);
				break;

			default:
				break;
		}
	}
}

void Config::setInitialMap(Map* map)
{
	for (int i = 0; i < map->getMap().size(); i++)
	{
		for (int j = 0; j < map->getMap()[0].size(); j++)
		{
			map->getMap()[i][j]->setType(mapChar[i][j]);
		}
	}	
}

void Config::printMap()
{
	for (int i = 0; i < mapChar.size(); i++)
	{
		for (int j = 0; j < mapChar[0].size(); j++)
		{
			std::cout << mapChar[i][j];
		}
		std::cout << std::endl;
	}
}
