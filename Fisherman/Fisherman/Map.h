#pragma once
#include <vector>

class Tile;
class Config;

class Map {

private:
	int column_size;
	int row_size;
	std::vector<std::vector<Tile*>> map;
	
public:

	Map();
	~Map();

	void printMap();
	void createMap();

	//Gets and Sets
	void setColumnSize(int x) { this->column_size = x; }
	int getColumnSize() const { return this->column_size; }

	void setRowSize(int x) { this->row_size = x; }
	int getRowSize() const { return this->row_size; }

	std::vector<std::vector<Tile*>> getMap() const { return this->map; }
};
