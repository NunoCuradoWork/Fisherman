#pragma once
#include "Config.h"
#include "Map.h"
#include "CommandLine.h"
#include "Consola.h"

#include <vector>

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
	std::vector<Player*> getPlayers() { return players; }

	Map& getMap();
	Config& getConfig(); 
	CommandLine& getCommandLine();

	void initSettings();
	void createPlayers();
	void printPlayers();

	void runGame();
	void paintMap();


	void setInitialGraphicalOptions();


	void enterCommands();
	void executeCommands();
	void combatePhase();
	void eventPhase();
	void piratePhase();
	

};

