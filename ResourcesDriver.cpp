//
// ResourcesDriver.cpp
// Assignment 1 Part 5
// Created by Alexandre Briere on 02-12-2020
//

#include <vector>
#include "Resources.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;


int main() {

	cout << "This is the driver for the resources in Part 5 \n";

	// Creating a new harvest tile deck and displaying resources on a harvest tile
	HarvestTileDeck* harvestTileDeck = new HarvestTileDeck();
	HarvestTile* harvestTile = new HarvestTile(1);
	cout << *(harvestTile->getTopLeftResource()) << " ";
	cout << *(harvestTile->getTopRightResource()) << " ";
	cout << *(harvestTile->getBottomLeftResource()) << " ";
	cout << *(harvestTile->getBottomRightResource()) << "\n";

	cout << "Number of harvest tiles in the deck: " << to_string(harvestTileDeck->howManyHarvestTiles()) << "\n";

	// Creating a new building deck and displaying information on a building
	BuildingDeck* buildingDeck = new BuildingDeck();
	Building* building = new Building(1);
	cout << *(building->getNumber()) << " ";
	cout << *(building->getColor()) << " ";
	cout << *(building->getLabel()) << "\n";

    cout << "Number of buildings in the deck: " << to_string(buildingDeck->howManyBuildings()) << "\n";
    system("pause");
}
