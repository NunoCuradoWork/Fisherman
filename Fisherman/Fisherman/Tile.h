#pragma once


class Ship;
class Port;

class Tile {

private:

	enum class Fish_Value 
	{
		fish_depleted = 0, 
		fish_creation_1, 
		fish_creation_2,
		fish_available
	};

	bool type;
	int fish;
	Ship* ship;
	Port* port;
	
};