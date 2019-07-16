#pragma once
#include "Ship.h"
class Escuna : public Ship
{
private:
	int fish;

public:

	Escuna();
	~Escuna();

	bool stormEvent();

	void sellFish(int quantity);
	void receiveFish(int quantity);


	int getFish() { return fish; };
	void setFish(int x) { fish = x; };


};
