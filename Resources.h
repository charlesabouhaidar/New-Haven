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
};

class HarvestTileDeck {
private:
	vector<HarvestTile*> harvestTiles;
public:
	HarvestTileDeck();
	~HarvestTileDeck();
	HarvestTile* drawHarvestTile();
	int* howManyHarvestTiles();
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
	vector<Building*> buildings;
public:
	BuildingDeck();
	~BuildingDeck();
	Building* drawBuilding();
	int* howManyBuildings();
};

class HandObject {
private:
	static HarvestTile* displayHarvestTiles[2];
	static Building* displayBuildings[];
public:
	HandObject();
	HarvestTile* exchange(int row, int column);
	~HandObject();
	void toString();

};

#endif //COMP345_RESOURCES_H    
