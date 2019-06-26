#pragma once

class Ship;
class Port;

class Tile {

private:

	//enum class Fish_Value 
	//{
	//	fish_depleted = 0, 
	//	fish_creation_1, 
	//	fish_creation_2,
	//	fish_available
	//};

	char type;

	int fish;


	Ship* ship;
	Port* port;

public:
	Tile();

	char getType();
	void setType(char x);

	int getFish();
	void setFish(int x) { fish = x; }


	Ship* getShip();
	void setShip(Ship& ship);

	Port* getPort();
	void setPort(Port& port);

};