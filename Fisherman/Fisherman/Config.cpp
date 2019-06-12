#include "Config.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "Map.h"


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

void Config::readFile(Map& map)
{
	std::ifstream myfile(getFilename());
	std::string token;
	int value;
	int counter = 0;

	if (myfile.is_open())
	{
		std::string line;
		while (std::getline(myfile, line))
		{
			std::istringstream iss(line);
			if (counter == 0)
			{
				iss >> token >> value;
				map.setRowSize(value);
			}
			else if (counter == 1)
			{
				iss >> token >> value;
				map.setColumnSize(value);
			}
			else if (counter > map.getRowSize()+1)
			{
				iss >> token >> value; 
				stats.push_back(value);
			}
			else
			{
				 iss >> token;
				 mapString.push_back(token);
			}
			counter++;
		}
	}
	else
	{
		std::cout << "ERROR" << std::endl;
	}
	myfile.close();
}
