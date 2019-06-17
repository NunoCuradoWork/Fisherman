#pragma once
#include <vector>


class Map;
class Player;
class Config;

class Game
{
private:

	int turn;
	Map* map;
	Config* config;
	std::vector<Player*> players;

public:
	
	//Default constructor
	Game();
	
	void execConfig();
};

