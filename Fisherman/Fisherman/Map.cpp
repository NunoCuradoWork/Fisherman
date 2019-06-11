#include "Map.h"
#include "Tile.h"
#include <iostream>
#include <vector>


Map::Map(int row, int column)
{
	this->column_size = column;
	this->row_size = row;

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


