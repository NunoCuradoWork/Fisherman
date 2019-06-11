#include "Tile.h"
#include "ObjDefs.h"

Tile::Tile()
{
	this->fish = 0;
	this->type = WATER;
	this->port = nullptr;
	this->ship = nullptr;
}

char Tile::getType()
{
	return this->type;
}

int Tile::getFish()
{
	return this->fish;
}

Ship* Tile::getShip()
{
	return this->ship;
}

Port* Tile::getPort()
{
	return this->port;
}
