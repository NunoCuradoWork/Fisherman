#pragma once
#include <vector>
#include <string>

class Ship;

class Player {

private:

	std::string name;
	int wealth;
	std::vector <Ship*> navy;


public:

	Player(std::string name);
	Player() = delete;

};