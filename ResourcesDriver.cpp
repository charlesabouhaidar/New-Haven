//
// ResourcesDriver.cpp
// Assignment 1 Part 5
// Created by Alexandre Briere on 02-12-2020
//

#include <vector>
#include "Resources.h"
#include "Player.h"
#include "GBMap.h"

using namespace std;


int main(int argc, const char * argv[]) {

	cout << "This is the driver for the resources in Part 5 \n";

	// Creating a new harvest tile deck and displaying resources on a harvest tile

	HarvestTileDeck* harvestTileDeck = new HarvestTileDeck();
	HarvestTile* harvestTile = new HarvestTile();
	harvestTile->getTopLeftResource();
	harvestTile->getTopRightResource();
	harvestTile->getBottomLeftResource();
	harvestTile->getBottomRightResource();

	// Creating a new building deck and displaying information on a building

	BuildingDeck* buildingDeck = new BuildingDeck();
	Building* building = new Building();
	building->getNumber();
	building->getColor();
	building->getLabel();

	// Creating a new hand object and showing its contents

	Hand* hand = new Hand();

	hand->toString();

	// Exchange method test
  
	GBMap board = new GBMap(3);

    hand->exchange(board, 1, 0, 4, 2);
	hand->toString();


	// Delete the elements to avoid memory leaks and assign the dangling pointers to NULL.
	delete hand;
	hand = NULL;
	delete building;
	building = NULL;
	delete harvestTile;
	harvestTile = NULL;

	return 0;
}
