#pragma once

class Tile;

class Map {

private:
	int column_size;
	int row_size;
	Tile* tile;

	void create(int column, int row);

public:

	Map(int column, int row);
};
