#include "Veleiro.h"
#include <random>

Veleiro::Veleiro() : fish(0)
{
	soldier = 20;
	water = 200;
	cargo = 0;
	storage = 40;
}

Veleiro::~Veleiro()
{

}

bool Veleiro::stormEvent()
{
	//Separate into random function
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1,100);

	if (getStorage() > 40/2 && dist(mt) <= 35)
		return true;
	else if (getStorage() <= 40 / 2 && dist(mt) <= 20)
		return true;
}

void Veleiro::sellFish(int quantity)
{
	if (quantity > getFish())
		quantity = getFish();
	
	setFish(getFish() - quantity);
	setStorage(getStorage() + quantity);
}

int Veleiro::transferFish(int quantity)
{
	int totalTransfer = quantity;

	if (quantity > getStorage())
		quantity = getStorage();

	setFish(getFish() + quantity);
	setStorage(getStorage() - quantity);

	totalTransfer = totalTransfer - quantity;
}
