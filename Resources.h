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
	HarvestTile(const HarvestTile& harvestTile);
	~HarvestTile();
	HarvestTile(int indexOfHT);
	HarvestTile& operator=(const HarvestTile& h);
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
	HarvestTile drawHarvestTile();
	int howManyHarvestTiles();
};

class Building {
private:
	int* number;
	string* color;
	string* label;

public:
	Building();
	Building(const Building& building);
	~Building();
	Building(int indexOfB);
	Building& operator=(const Building& b);
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
	Building drawBuilding();
	int howManyBuildings();
};

class Hand {
private:
	vector<HarvestTile>* harvestTiles;
	vector<Building>* buildings;
public:
	Hand();
	void exchange(GBMap* board, int playerID, int indexOfHarvestTile, string position, int orientation);
	~Hand();
    Building getBuilding(int handIndex);
    HarvestTile getHarvestTile(int handIndex);
	void deleteBuilding(int indexOfBuilding);
	void deleteHarvestTile(int indexOfHarvestTile);
	void addBuilding(Building building);
	void addHarvestTile(HarvestTile harvestTile);
	string toString();
};

#endif //COMP345_RESOURCES_H    
