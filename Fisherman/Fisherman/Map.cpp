#include "Map.h"
#include "Tile.h"
#include "Consola.h"
#include "Ship.h"

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
	int counter = 0;
	for (unsigned int i = 0; i < map.size(); i++)
	{
		if (counter < column_size)
		{
			std::cout << map[i]->getType();
			counter++;
		}	
		else
		{
			std::cout << std::endl;
			counter = 0;
		}
	}
}

void Map::createMap()
{
	int size = row_size * column_size;
	int x = 0, y = 0;
	int counter = 0;

	for (int i = 0; i < size; i++)
	{
		if (counter < column_size)
		{
			counter++;
			x++;
		}
		else
		{
			counter = 0;
			x = 0;
			y++;
		}
		Tile* newTile = new Tile(x, y);
		map.push_back(newTile);
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

void Map::drawTiles()
{
	int startY = 6;
	int startX = 7;
	int spaceX = 145 / column_size;
	int spaceY = 55 / row_size;
	int marginsX = spaceX / 2;
	int marginsY = spaceY / 2;
	int y = 6;
	int x = 7;

	int counter = 0;

	Consola::gotoxy(startX+marginsX,startY+marginsY);

	for (unsigned int i = 0; i < map.size(); ++i)
	{
		if (map[i]->getShip() != nullptr)
			std::cout << map[i]->getShip()->getShipType();
		else
			std::cout << map[i]->getType();

		if (counter < column_size - 1)
		{
			x += spaceX;
			Consola::gotoxy(x + marginsX, y + marginsY);
			counter++;
		}
		else
		{
			y += spaceY;
			counter = 0;
			x = startX;
			Consola::gotoxy(startX + marginsX, y + marginsY);
		}	
	}
}

std::vector<Tile> Map::getNeighbors(Tile& tile) const
{
	std::vector<Tile*> neighbors;
	int x, y;

	int OriginX = tile.getPoint().getX();
	int OriginY = tile.getPoint().getY();

	for (auto it : map)
	{
		x = it->getPoint.getX();
		y = it->getPoint.getY();

		if (x == OriginX && y == OriginY)
		{}
		else
		{
			//Generic case
			if (OriginX != row_size - 1 && OriginY != column_size - 1)
			{
				if (x == OriginX - 1 || x == OriginX || x == OriginX + 1)
				{
					if (y == OriginY - 1 || y == OriginY || y == OriginY + 1)
					{
						neighbors.push_back(it);
					}
				}
			}

			//Bottom X
			else if (OriginX == row_size - 1)
			{
				if (x == OriginX - 1)
				{
					if (y == OriginY - 1 || y == OriginY || y == OriginY + 1)
					{
						neighbors.push_back(it);
					}
				}
				else if (x == OriginX)
				{
					if (y == OriginY - 1 || y == OriginY + 1)
					{
						neighbors.push_back(it);
					}
				}
				else if (x == OriginX - row_size - 1)
				{
					if (y == OriginY - 1 || y == OriginY || y == OriginY + 1)
					{
						neighbors.push_back(it);
					}
				}
			}

			//Up X
			else if (OriginX == 0)
			{
				if (x == OriginX + 1)
				{
					if (y == OriginY - 1 || y == OriginY || y == OriginY + 1)
					{
						neighbors.push_back(it);
					}
				}
				else if (x == OriginX)
				{
					if (y == OriginY - 1 || y == OriginY + 1)
					{
						neighbors.push_back(it);
					}
				}
				else if (x == row_size - 1)
				{
					if (y == OriginY - 1 || y == OriginY || y == OriginY + 1)
					{
						neighbors.push_back(it);
					}
				}
			}

			//Right Y
			else if (OriginY == column_size - 1)
			{
				if (y == column_size - 1)
				{
					if (x == OriginX - 1 || x == OriginX || x == OriginX + 1)
					{
						neighbors.push_back(it);
					}
				}
				else if (y == OriginY)
				{
					if (x == OriginX - 1 || x == OriginX + 1)
					{
						neighbors.push_back(it);
					}
				}
				else if (y == OriginY - column_size - 1)
				{
					if (x == OriginX - 1 || x == OriginX || x == OriginX + 1)
					{
						neighbors.push_back(it);
					}
				}
			}

			//Left Y
			else if (OriginY ==0)
			{
				if (y == column_size + 1)
				{
					if (x == OriginX - 1 || x == OriginX || x == OriginX + 1)
					{
						neighbors.push_back(it);
					}
				}
				else if (y == OriginY)
				{
					if (x == OriginX - 1 || x == OriginX + 1)
					{
						neighbors.push_back(it);
					}
				}
				else if (y == column_size - 1)
				{
					if (x == OriginX - 1 || x == OriginX || x == OriginX + 1)
					{
						neighbors.push_back(it);
					}
				}
			}
			//Corner UL
			else if (OriginY == 0 && OriginX == 0)
			{
				if (y == OriginY + 1 && x == OriginX)
				{
					neighbors.push_back(it);
				}
				else if (y == OriginY + 1 && x == OriginX + 1)
				{
					neighbors.push_back(it);
				}
				else if (y == OriginY && x == OriginX + 1)
				{
					neighbors.push_back(it);
				}
				else if (y == column_size -1 && x == OriginX)
				{
					neighbors.push_back(it);
				}
				else if (y == column_size - 1 && x == OriginX + 1)
				{
					neighbors.push_back(it);
				}
				else if (y == column_size - 1 && x == row_size - 1)
				{
					neighbors.push_back(it);
				}
				else if (y == OriginY && x == row_size - 1)
				{
					neighbors.push_back(it);
				}
				else if (y == OriginY +1 && x == row_size - 1)
				{
					neighbors.push_back(it);
				}
				
			}
		}
		
	}



	return std::vector<Tile>();
}



