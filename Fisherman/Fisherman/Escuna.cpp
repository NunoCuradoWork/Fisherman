#include "Escuna.h"
#include <random>

Escuna::Escuna()
{
	shipType = 'E';
	soldier = 10;
	water = 100;
	cargo = 0;
	storage = 20;
	fish = 0;
}

Escuna::~Escuna()
{
}

bool Escuna::stormEvent()
{
	int soldier;

	//Separate into random function
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 100);

	if (dist(mt) <= 20)
	{
		setCargo(0);
		setFish(0);
	}

	if (dist(mt) <= 35)
		return true;
	else
		return false;
}

void Escuna::sellFish(int quantity)
{
	if (quantity > getFish())
		quantity = getFish();

	setFish(getFish() - quantity);
	setStorage(getStorage() + quantity);
}

void Escuna::receiveFish(int quantity)
{
	if (quantity > getStorage())
		quantity = getStorage();

	setFish(getFish() + quantity);
	setStorage(getStorage() - quantity);

}

