#pragma once
#include <vector>

class Tile;

class Map {

private:
	int column_size;
	int row_size;
	std::vector<std::vector<Tile*>> map;
	
public:

	Map() = delete;
	Map(int row, int column);
	~Map();

	void printMap();
};
