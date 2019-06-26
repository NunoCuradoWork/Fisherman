#pragma once
#include <vector>

class Ship;

class Port
{
private:

	bool isAlly;
	int soldier;

	char name;
	int cargoBuyPrice;
	int cargoSellPrice;
	int fishSellPrice;

	std::vector <Ship* > port_navy;

public:

	Port(char name, int cargoBuyPrice, int cargoSellPrice, int fishSellPrice, int soldier, bool isAlly);

};
