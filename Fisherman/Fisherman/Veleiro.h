#pragma once
#include "Ship.h"


class Veleiro : public Ship
{
private:
	int fish;
public:

	Veleiro();
	~Veleiro();

	bool stormEvent();

	void sellFish(int quantity);
	int transferFish(int quantity);


	
	int getFish() { return fish; };
	void setFish(int x) { fish = x; };
};