#pragma once
#include <vector>
#include "Config.h"
#include "Map.h"
#include "CommandLine.h"

class Player;

class Game
{
private:

	int turn;
	Map map;
	Config config;
	CommandLine commandLine;
	std::vector<Player*> players;

public:
	
	//Default constructor
	Game();
	~Game();

	int getTurn() const { return turn;}
	void setTurn(int updateTurn) { turn = updateTurn; }

	Map& getMap();

	Config& getConfig(); 

	std::vector<Player*> getPlayers(){ return players; }

	void initSettings();
	void createPlayers();
	void printPlayers();

	void receiveLineCommands();
};

