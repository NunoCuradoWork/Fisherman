#include "Fragata.h"
#include <random>

Fragata::Fragata()
{
	shipType = 'F';
	soldier = 50;
	water = 500;
	cargo = NULL;
	storage = NULL;
}

Fragata::~Fragata()
{
}

bool Fragata::stormEvent()
{
	int soldier;

	//Separate into random function
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 100);

	soldier = getSoldier();
	soldier = soldier - soldier * 0.15;
	setSoldier(soldier);

	if (dist(mt) <= 20)
		return true;
	else
		return false;
}

