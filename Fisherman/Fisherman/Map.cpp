#include "Map.h"
#include "Tile.h"
#include <iostream>
#include <vector>


Map::Map()
{
	this->column_size = 0;
	this->row_size = 0;
}

Map::~Map()
{
	
}

void Map::printMap()
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[0].size(); j++)
		{
			std::cout << map[i][j]->getType();
		}
		std::cout << std::endl;
	}
}

void Map::createMap()
{
	int column = Map::getColumnSize();
	int row = Map::getRowSize();

	for (int i = 0; i < row; i++)
	{
		std::vector <Tile*> aux;

		for (int j = 0; j < column; j++)
		{
			Tile* newTile = new Tile();
			aux.push_back(newTile);
		}
		map.push_back(aux);
	}
}


