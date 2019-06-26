#include "Port.h"

Port::Port(char name, int cargoBuyPrice, int cargoSellPrice, int fishSellPrice, int soldier, bool isAlly) : 
	name(name), 
	cargoBuyPrice(cargoBuyPrice), 
	cargoSellPrice(cargoSellPrice), 
	fishSellPrice(fishSellPrice),
	soldier(soldier),
	isAlly(isAlly)
{}
