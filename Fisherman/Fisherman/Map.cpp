#include "Map.h"
#include "Tile.h"
#include "Consola.h"

#include <iostream>
#include <vector>
#include <iostream>


Map::Map():column_size(0), row_size(0)
{

}

Map::~Map()
{
	
}

void Map::printMap()
{
	for (unsigned int i = 0; i < map.size(); i++)
	{
		for (unsigned int j = 0; j < map[0].size(); j++)
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

std::vector<Port*>& Map::getPortList()
{
	return this->portList;
}

void Map::drawMapBorders()
{
	int i = 6;
	Consola::gotoxy(5, 5);
	std::cout << (char)201;
	Consola::gotoxy(6, 5);

	while (i < 150)
	{
		Consola::gotoxy(i, 5);
		std::cout << (char)205;
		i++;	
	}
	Consola::gotoxy(150, 5);
	std::cout << (char)187;

	i = 6;
	Consola::gotoxy(5, 60);
	std::cout << (char)200;

	while (i < 150)
	{
		Consola::gotoxy(i, 60);
		std::cout << (char)205;
		i++;
	}
	Consola::gotoxy(150, 60);
	std::cout << (char)188;

	i = 6;
	while (i < 60)
	{
		Consola::gotoxy(5, i);
		std::cout << (char)186;
		i++;
	}

	i = 6;
	while (i < 60)
	{
		Consola::gotoxy(150, i);
		std::cout << (char)186;
		i++;
	}
}

void Map::drawLogBorders()
{
	int i = 153;
	Consola::gotoxy(152, 5);
	std::cout << (char)201;
	Consola::gotoxy(153, 5);

	while (i < 200)
	{
		Consola::gotoxy(i, 5);
		std::cout << (char)205;
		i++;
	}
	Consola::gotoxy(200, 5);
	std::cout << (char)187;

	i = 153;
	Consola::gotoxy(152, 60);
	std::cout << (char)200;

	while (i < 200)
	{
		Consola::gotoxy(i, 60);
		std::cout << (char)205;
		i++;
	}
	Consola::gotoxy(200, 60);
	std::cout << (char)188;

	i = 6;
	while (i < 60)
	{
		Consola::gotoxy(152, i);
		std::cout << (char)186;
		i++;
	}

	i = 6;
	while (i < 60)
	{
		Consola::gotoxy(200, i);
		std::cout << (char)186;
		i++;
	}

	
}

void Map::cmdLineBorders()
{
	int i = 6;
	Consola::gotoxy(5,62) ;
	std::cout << (char)201;
	Consola::gotoxy(6, 5);

	while (i < 150)
	{
		Consola::gotoxy(i, 62);
		std::cout << (char)205;
		i++;
	}
	Consola::gotoxy(150, 62);
	std::cout << (char)187;

	i = 6;
	Consola::gotoxy(5, 70);
	std::cout << (char)200;
	
	while (i < 150)
	{
		Consola::gotoxy(i, 70);
		std::cout << (char)205;
		i++;
	}
	Consola::gotoxy(150, 70);
	std::cout << (char)188;

	i = 63;
	while (i < 70)
	{
		Consola::gotoxy(5, i);
		std::cout << (char)186;
		i++;
	}

	i = 63;

	while (i < 70)
	{
		Consola::gotoxy(150, i);
		std::cout << (char)186;
		i++;
	}
	
}



