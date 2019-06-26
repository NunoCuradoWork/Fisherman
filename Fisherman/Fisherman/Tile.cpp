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

void Tile::setType(char x)
{
	this->type = x;
}

int Tile::getFish()
{
	return this->fish;
}

Ship* Tile::getShip()
{
	return this->ship;
}

void Tile::setShip(Ship& ship)
{
	this->ship = &ship;
}

Port* Tile::getPort()
{
	return this->port;
}

void Tile::setPort(Port& port)
{
	this->port = &port;
}
