//
// Resources.h
// Assignment 1 Part 5
// Created by Alexandre Briere on 02-12-2020
//
#ifndef COMP345_RESOURCES_H
#define COMP345_RESOURCES_H
#include <string>
#include <vector>

using namespace std;

class HarvestTile {
private:
	string topLeft;
	string topRight;
	string bottomLeft;
	string bottomRight;

public:
	HarvestTile();
	~HarvestTile();
	HarvestTile(int index);
	string* getTopLeftResource();
	string* getTopRightResource();
	string* getBottomLeftResource();
	string* getBottomRightResource();
};

class HarvestTileDeck {
private:
	vector<HarvestTile*> harvestTiles;
public:
	HarvestTileDeck();
	~HarvestTileDeck();
	HarvestTile* drawHarvestTile();
	int howManyHarvestTiles();
};

class Building {
private:
	int number;
	string color;
	string label;

public:
	Building();
	~Building();
	Building(int index);
	int* getNumber();
	string* getColor();
	string* getLabel();
};

class BuildingDeck {
private:
	vector<Building*> buildings;
public:
	BuildingDeck();
	~BuildingDeck();
	Building* drawBuilding();
	int howManyBuildings();
};

class Hand {
public:
	void exchange();
};

#endif //COMP345_RESOURCES_H    
