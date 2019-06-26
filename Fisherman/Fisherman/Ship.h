#pragma once
#include <iostream>


class Ship
{
protected:
	
	int soldier;
	int water;
	int storage;
	int cargo;

public:



	//Return true if event is applied
	virtual bool stormEvent() = 0;

	void buyCargo();
	void sellCargo();

	void attack();
	void move();

	int getSoldier() { return soldier; }
	void setSoldier(int x) { soldier = x; }

	int getWater() { return water; }
	void setWater(int x) { water = x; }

	int getStorage() { return storage; }
	void setStorage(int x) { storage = x; }

	int getCargo() { return cargo; }
	void setCargo(int x) { cargo = x; }
};
