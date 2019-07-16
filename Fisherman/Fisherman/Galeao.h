#pragma once
#include "Ship.h"
class Galeao : public Ship
{
private:
	int fish;

public:

	Galeao();
	~Galeao();

	bool stormEvent();

	void sellFish(int quantity);
	int transferFish(int quantity);


	int getFish() { return fish; };
	void setFish(int x) { fish = x; };


};


