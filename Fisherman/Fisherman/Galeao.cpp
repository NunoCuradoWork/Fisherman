#include "Galeao.h"
#include <random>

Galeao::Galeao()
{
	shipType = 'G';
	soldier = 40;
	water = 400;
	cargo = 0;
	storage = 70;
	fish = 0;
}

Galeao::~Galeao()
{
}

bool Galeao::stormEvent()
{
	int soldier;

	//Separate into random function
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 100);

	soldier = getSoldier();
	soldier = soldier - soldier * 0.10;
	setSoldier(soldier);

	if (dist(mt) <= 40)
		return true;
	else
		return false;
}

void Galeao::sellFish(int quantity)
{
	if (quantity > getFish())
		quantity = getFish();

	setFish(getFish() - quantity);
	setStorage(getStorage() + quantity);
}

int Galeao::transferFish(int quantity)
{
	int totalTransfer = quantity;

	if (quantity > getStorage())
		quantity = getStorage();

	setFish(getFish() + quantity);
	setStorage(getStorage() - quantity);

	totalTransfer = totalTransfer - quantity;

	return totalTransfer;
}
