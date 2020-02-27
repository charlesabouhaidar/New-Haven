//
// Resources.h
// Assignment 1 Part 5
// Created by Alexandre Briere on 02-12-2020
//
#ifndef COMP345_RESOURCES_H
#define COMP345_RESOURCES_H
#include <string>
#include <vector>
#include "GBMap.h"

using std::vector;
using std::string;
using std::to_string;

class HarvestTile {
private:
	string* topLeft;
	string* topRight;
	string* bottomLeft;
	string* bottomRight;

public:
	HarvestTile();
	~HarvestTile();
	HarvestTile(int indexOfHT);
	string* getTopLeftResource();
	string* getTopRightResource();
	string* getBottomLeftResource();
	string* getBottomRightResource();
	void setTopLeftResource(string* resource);
	void setTopRightResource(string* resource);
	void setBottomLeftResource(string* resource);
	void setBottomRightResource(string* resource);
};

class HarvestTileDeck {
private:
	vector<HarvestTile>* harvestTiles;
public:
	HarvestTileDeck();
	~HarvestTileDeck();
	HarvestTile* drawHarvestTile();
	int howManyHarvestTiles();
};

class Building {
private:
	int* number;
	string* color;
	string* label;

public:
	Building();
	~Building();
	Building(int indexOfB);
	int* getNumber();
	string* getColor();
	string* getLabel();
};

class BuildingDeck {
private:
	vector<Building>* buildings;
public:
	BuildingDeck();
	~BuildingDeck();
	Building* drawBuilding();
	int howManyBuildings();
};

class Hand {
private:
	HarvestTile* displayHarvestTiles[2];
	Building* displayBuildings[144];
	double TileData;
public:
	Hand();
	void exchange(GBMap* board, int playerID, int indexOfHarvestTile, string position, int orientation);
	~Hand();
    Building* getBuilding(int handIndex);
	void drawHarvestTile();
	void drawBuilding();
	void deleteBuilding(int indexOfBuilding);
	void deleteHarvestTile(int indexOfHarvestTile);
	string toString();

};

#endif //COMP345_RESOURCES_H    
