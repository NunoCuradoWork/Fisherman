#pragma once
#include <string>
#include <vector>

class Map;
class Tile;

enum Stats 
{
	WEALTH=0,
	PIRATERATE,
	SHIPPRICE,
	SOLDERPRICE,
	SELLFISHPRICE,
	BUYCARGOPRICE,
	SELLCARGOPRICE,
	PORTSOLDIERS,
	EVENTRATE,
	STORMRATE,
	SIRENRATE,
	STILLRATE,
	RIOTRATE
};

class Config
{
private:
	
	std::string filename;
	std::vector<int> stats;
	std::vector< std::vector<char> > mapChar;

	//General
	int column;
	int row;
	int wealth;
	int portSoldiers;

	//Events
	int pirateRate;
	int stormRate;
	int sirenRate;
	int stillRate;
	int riotRate;
	int eventRate;

	//Prices
	int shipPrice;
	int soldierPrice;
	int sellFishPrice;
	int buyCargoPrice;
	int sellCargoPrice;

public:
	
	//Gets and Sets
	int getColumn() { return this->column; };
	void setColumn(int x) { this->column = x; };

	int getRow() { return this->row; };
	void setRow(int x) { this->row = x; };

	int getWealth() { return this->wealth; };
	void setWealth(int x) { this->wealth = x; };

	int getPortSoldiers() { return this->portSoldiers; };
	void setPortSoldiers(int x) { this->portSoldiers = x; };

	int getPirateRate() { return this->pirateRate; };
	void setPirateRate(int x) { this->pirateRate = x; };

	int getStormRate() { return this->stormRate; };
	void setStormRate(int x) { this->stormRate = x; };

	int getSirenRate() { return this->sirenRate; };
	void setSirenRate(int x) { this->sirenRate = x; };

	int getStillRate() { return this->stillRate; };
	void setStillRate(int x) { this->stillRate = x; };

	int getRiotRate() { return this->riotRate; };
	void setRiotRate(int x) { this->riotRate = x; };

	int getEventRate() { return this->eventRate; };
	void setEventRate(int x) { this->eventRate = x; };

	int getShipPrice() { return this->shipPrice; };
	void setShipPrice(int x) { this->shipPrice = x; };

	int getSoldierPrice() { return this->soldierPrice; };
	void setSoldierPrice(int x) { this->soldierPrice = x; };

	int getSellFishPrice() { return this->sellFishPrice; };
	void setSellFishPrice(int x) { this->sellFishPrice = x; };

	int getBuyCargoPrice() { return this->buyCargoPrice; };
	void setBuyCargoPrice(int x) { this->buyCargoPrice = x; };

	int getSellCargoPrice() { return this->sellCargoPrice; };
	void setSellCargoPrice(int x) { this->sellCargoPrice = x; };

	std::string getFilename() { return this->filename; }

	//Main methods

	//Constructor
	Config();

	//Read file and fill local variables
	void getConfigFromFile(Map* map);
	//Set config fields
	void setStatsFromConfig();
	//Set initial map


	void setInitialMap(Map* map);
	void printMap();

};