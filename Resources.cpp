//
// Resources.cpp
// Assignment 1 Part 5
// Created by Alexandre Briere on 02-12-2020
//

#include "Resources.h"
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <chrono>

using std::string;
using std::vector;
using std::to_string;
using std::chrono::system_clock;

// HARVEST TILE CLASS ------------------------------------------------------------------------------------------

HarvestTile::HarvestTile() {
    bottomLeft = new string("");
    bottomRight = new string("");
    topLeft = new string("");
    topRight = new string("");
}
HarvestTile::HarvestTile(const HarvestTile& harvestTile){
    bottomLeft = new string;
    bottomRight = new string;
    topLeft = new string;
    topRight = new string;
    *bottomLeft = *harvestTile.bottomLeft;
    *bottomRight = *harvestTile.bottomRight;
    *topLeft = *harvestTile.topLeft;
    *topRight = *harvestTile.topRight;
}
HarvestTile::HarvestTile(int indexOfHT) {

    topLeft = new string;
    topRight = new string;
    bottomLeft = new string;
    bottomRight = new string;
	switch (indexOfHT) {
		// 3 Different Resources Harvest Tiles

	case 1:  *topLeft = "Rock";  *topRight = "Rock";  *bottomLeft = "Wheat";  *bottomRight = "Sheep"; break;
	case 2:  *topLeft = "Rock";  *topRight = "Rock";  *bottomLeft = "Wheat";  *bottomRight = "Timber"; break;
	case 3:  *topLeft = "Rock";  *topRight = "Rock";  *bottomLeft = "Sheep";  *bottomRight = "Timber"; break;
	case 4:  *topLeft = "Timber"; *topRight = "Timber"; *bottomLeft = "Sheep";  *bottomRight = "Rock"; break;
	case 5:  *topLeft = "Timber"; *topRight = "Timber"; *bottomLeft = "Wheat";  *bottomRight = "Rock"; break;
	case 6:  *topLeft = "Timber"; *topRight = "Timber"; *bottomLeft = "Sheep";  *bottomRight = "Wheat"; break;
	case 7:  *topLeft = "Wheat";  *topRight = "Wheat";  *bottomLeft = "Sheep";  *bottomRight = "Rock"; break;
	case 8:  *topLeft = "Wheat";  *topRight = "Wheat";  *bottomLeft = "Sheep";  *bottomRight = "Timber"; break;
	case 9:  *topLeft = "Wheat";  *topRight = "Wheat";  *bottomLeft = "Rock";  *bottomRight = "Timber"; break;
	case 10: *topLeft = "Sheep";  *topRight = "Sheep";  *bottomLeft = "Rock";  *bottomRight = "Timber"; break;
	case 11: *topLeft = "Sheep";  *topRight = "Sheep";  *bottomLeft = "Rock";  *bottomRight = "Wheat"; break;
	case 12: *topLeft = "Sheep";  *topRight = "Sheep";  *bottomLeft = "Wheat";  *bottomRight = "Timber"; break;
		
		// 2 Different Resources Harvest Tiles

	case 13: *topLeft = "Rock";  *topRight = "Rock";  *bottomLeft = "Rock"; *bottomRight = "Sheep"; break;
	case 14: *topLeft = "Rock";  *topRight = "Rock";  *bottomLeft = "Rock"; *bottomRight = "Timber"; break;
	case 15: *topLeft = "Rock";  *topRight = "Rock";  *bottomLeft = "Rock"; *bottomRight = "Wheat"; break;
	case 16: *topLeft = "Timber"; *topRight = "Timber"; *bottomLeft = "Timber"; *bottomRight = "Wheat"; break;
	case 17: *topLeft = "Timber"; *topRight = "Timber"; *bottomLeft = "Timber"; *bottomRight = "Sheep"; break;
	case 18: *topLeft = "Timber"; *topRight = "Timber"; *bottomLeft = "Timber"; *bottomRight = "Rock"; break;
	case 19: *topLeft = "Wheat";  *topRight = "Wheat";  *bottomLeft = "Wheat";  *bottomRight = "Rock"; break;
	case 20: *topLeft = "Wheat";  *topRight = "Wheat";  *bottomLeft = "Wheat";  *bottomRight = "Timber"; break;
	case 21: *topLeft = "Wheat";  *topRight = "Wheat";  *bottomLeft = "Wheat";  *bottomRight = "Sheep"; break;
	case 22: *topLeft = "Sheep";  *topRight = "Sheep";  *bottomLeft = "Sheep";  *bottomRight = "Rock"; break;
	case 23: *topLeft = "Sheep";  *topRight = "Sheep";  *bottomLeft = "Sheep";  *bottomRight = "Timber"; break;
	case 24: *topLeft = "Sheep";  *topRight = "Sheep";  *bottomLeft = "Sheep";  *bottomRight = "Wheat"; break;

	}
}

// Destructor method
HarvestTile::~HarvestTile() {
    delete topLeft;
    delete topRight;
    delete bottomLeft;
    delete bottomRight;
}

HarvestTile& HarvestTile::operator=(const HarvestTile& h){
    if (this == &h)
        return *this;
    delete topLeft;
    delete topRight;
    delete bottomLeft;
    delete bottomRight;
    topLeft = new string(*h.topLeft);
    topRight = new string(*h.topRight);
    bottomLeft = new string(*h.bottomLeft);
    bottomRight = new string(*h.bottomRight);
    return *this;
}
// Accessor and mutator methods
string* HarvestTile::getTopLeftResource() {
	return topLeft;
}

string* HarvestTile::getTopRightResource() {
	return topRight;
}

string* HarvestTile::getBottomLeftResource() {
	return bottomLeft;
}

string* HarvestTile::getBottomRightResource() {
	return bottomRight;
}

void HarvestTile::setTopLeftResource(string* resource) {
	topLeft = resource;
}
void HarvestTile::setTopRightResource(string* resource) {
	topRight = resource;
}
void HarvestTile::setBottomLeftResource(string* resource) {
	bottomLeft = resource;
}
void HarvestTile::setBottomRightResource(string* resource) {
	bottomRight = resource;
}

// Harvest Tile Deck CLASS

// Constructor
HarvestTileDeck::HarvestTileDeck() {
    harvestTiles = new vector<HarvestTile>;
	if (harvestTiles->size() == 0) {
		for (int i = 0; i < 60; i++) {
			HarvestTile* pointer = new HarvestTile(rand() % 24 + 1);
			harvestTiles->push_back(*pointer);
			delete pointer;
		}
	}
}

// Destructor
HarvestTileDeck::~HarvestTileDeck() {
	delete harvestTiles;
}

// Method that returns a pointer to the harvest tile drawn from the deck
HarvestTile HarvestTileDeck::drawHarvestTile() {
	HarvestTile temp = harvestTiles->back();
	harvestTiles->pop_back();
	return temp;
}


// Returns the number of harvest tiles in the deck
int HarvestTileDeck::howManyHarvestTiles() {
	return harvestTiles->size();
}

// BUILDING CLASS ------------------------------------------------------------------------------------------

Building::Building() {
    color = new string("");
    label = new string("");
    number = new int(0);
}
Building::Building(const Building& building){
    color = new string;
    label = new string;
    number = new int;
    *number = *building.number;
    *color = *building.color;
    *label = *building.label;
}
Building::Building(int indexOfB) {
    number = new int;
    color = new string;
    label = new string;

	switch (indexOfB) {
		// 6 Buildings for green

	case 1: *number = 1; *color = "Green"; *label = "Meadow"; break;
	case 2: *number = 2; *color = "Green"; *label = "Meadow"; break;
	case 3: *number = 3; *color = "Green"; *label = "Meadow"; break;
	case 4: *number = 4; *color = "Green"; *label = "Meadow"; break;
	case 5: *number = 5; *color = "Green"; *label = "Meadow"; break;
	case 6: *number = 6; *color = "Green"; *label = "Meadow"; break;

		// 6 Buildings for gray
	case 7: *number = 1; *color = "Gray"; *label = "Quarry"; break;
	case 8: *number = 2; *color = "Gray"; *label = "Quarry"; break;
	case 9: *number = 3; *color = "Gray"; *label = "Quarry"; break;
	case 10: *number = 4; *color = "Gray"; *label = "Quarry"; break;
	case 11: *number = 5; *color = "Gray"; *label = "Quarry"; break;
	case 12: *number = 6; *color = "Gray"; *label = "Quarry"; break;

		// 6 Buildings for red
	case 13: *number = 1; *color = "Red"; *label = "Forest"; break;
	case 14: *number = 2; *color = "Red"; *label = "Forest"; break;
	case 15: *number = 3; *color = "Red"; *label = "Forest"; break;
	case 16: *number = 4; *color = "Red"; *label = "Forest"; break;
	case 17: *number = 5; *color = "Red"; *label = "Forest"; break;
	case 18: *number = 6; *color = "Red"; *label = "Forest"; break;

		// 6 Buildings for yellow
	case 19: *number = 1; *color = "Yellow"; *label = "Wheatfield"; break;
	case 20: *number = 2; *color = "Yellow"; *label = "Wheatfield"; break;
	case 21: *number = 3; *color = "Yellow"; *label = "Wheatfield"; break;
	case 22: *number = 4; *color = "Yellow"; *label = "Wheatfield"; break;
	case 23: *number = 5; *color = "Yellow"; *label = "Wheatfield"; break;
	case 24: *number = 6; *color = "Yellow"; *label = "Wheatfield"; break;

	}
}

// Destructor method

Building::~Building() {
    delete number;
    delete color;
    delete label;
}

Building& Building::operator=(const Building& b){
    if (this == &b)
        return *this;
    delete number;
    delete color;
    delete label;
    number = new int(*b.number);
    color = new string(*b.color);
    label = new string(*b.label);
    return *this;
}

// Accessor methods

int* Building::getNumber() {
	return number;
}

string* Building::getColor() {
	return color;
}


string* Building::getLabel() {
	return label;
}

// Building Deck CLASS

// Constructor
BuildingDeck::BuildingDeck() {
    buildings = new vector<Building>;
    for(int i = 0; i < 6; i++) {
        for (int j = 1; j < 25; j++) {
            Building *pointer = new Building(j);
            buildings->push_back(*pointer);
            delete pointer;
        }
    }
}

// Destructor
BuildingDeck::~BuildingDeck() {
	buildings->clear();
	delete buildings;
}


// Method that returns a pointer to the building drawn from the deck
Building BuildingDeck::drawBuilding() {
    srand(system_clock::now().time_since_epoch().count());
    int a = rand() % buildings->size();
	Building temp = buildings->at(a);
	buildings->erase(buildings->begin()+a);
	return temp;
}

// Returns the number of buildings in the deck
int BuildingDeck::howManyBuildings() {
	return buildings->size();
}



// HAND OBJECT CLASS ------------------------------------------------------------------------------------------

// Constructor
Hand::Hand() {
    harvestTiles = new vector<HarvestTile>;
    buildings = new vector<Building>;
    deliveryTile = nullptr;
}

Hand::Hand(const Hand &h){
    harvestTiles = new vector<HarvestTile>(*h.harvestTiles);
    buildings = new vector<Building>(*h.buildings);
    deliveryTile = nullptr;
}

// Destuctors
Hand::~Hand() {
    delete buildings;
    delete harvestTiles;
    delete deliveryTile;
}

void Hand::deleteBuilding(int indexOfBuilding) {
	buildings->erase(buildings->begin()+indexOfBuilding);
}

void Hand::deleteHarvestTile(int indexOfHarvestTile) {
    harvestTiles->erase(harvestTiles->begin()+indexOfHarvestTile);
}

// Accessor method to get a specific building in hand
Building Hand::getBuilding(int handIndex){
    return buildings->at(handIndex);
}

HarvestTile Hand::getHarvestTile(int handIndex){
    return harvestTiles->at(handIndex);
}

// exchange() method that allows the player to select the Harvest tile from 
// its position in the row and the column on the Game Board and assign the
// resource markers a value of the accumulated resources from the Harvest Tiles
void Hand::exchange(GBMap* board, int playerID, int indexOfHarvestTile, string position, int orientation) {

	HarvestTile* pointer = &(harvestTiles->at(indexOfHarvestTile));

	for(int i = 1; i < orientation; i++ ) {
		// Store top left resource temporarily
		string* temp = pointer->getTopLeftResource();
		// Shift resources on tile 90 degrees
		pointer->setTopLeftResource(pointer->getBottomLeftResource());
		pointer->setBottomLeftResource(pointer->getBottomRightResource());
		pointer->setBottomRightResource(pointer->getTopRightResource());
		pointer->setTopRightResource(temp);
	}

	//Creating data based on tile to input into setTileData() function

	int TileData = 0;

	// 1st digit of data

	if (*pointer->getTopLeftResource() == "Wheat")
		TileData = TileData + 10000;
	else if (*pointer->getTopLeftResource() == "Timber")
		TileData = TileData + 20000;
	else if (*pointer->getTopLeftResource() == "Rock")
		TileData = TileData + 30000;
	else if (*pointer->getTopLeftResource() == "Sheep")
		TileData = TileData + 40000;
	// 2nd digit of data

	if (*pointer->getTopRightResource() == "Wheat")
		TileData = TileData + 1000;
	else if (*pointer->getTopRightResource() == "Timber")
		TileData = TileData + 2000;
	else if (*pointer->getTopRightResource() == "Rock")
		TileData = TileData + 3000;
	else if (*pointer->getTopRightResource() == "Sheep")
		TileData = TileData + 4000;

	// 3rd digit of data

	if (*pointer->getBottomLeftResource() == "Wheat")
		TileData = TileData + 100;
	else if (*pointer->getBottomLeftResource() == "Timber")
		TileData = TileData + 200;
	else if (*pointer->getBottomLeftResource() == "Rock")
		TileData = TileData + 300;
	else if (*pointer->getBottomLeftResource() == "Sheep")
		TileData = TileData + 400;

	// 4th digit of data

	if (*pointer->getBottomRightResource() == "Wheat")
		TileData = TileData + 10;
	else if (*pointer->getBottomRightResource() == "Timber")
		TileData = TileData + 20;
	else if (*pointer->getBottomRightResource() == "Rock")
		TileData = TileData + 30;
	else if (*pointer->getBottomRightResource() == "Sheep")
		TileData = TileData + 40;

	// 5th digit of data
	TileData = TileData + playerID;
	// Set the tile on the board using the data generated

	board->setTileData(position, TileData);

	// Delete placed harvest tile from hand

	deleteHarvestTile(indexOfHarvestTile);
}

void Hand::addBuilding(Building building){
    buildings->push_back(building);
}

void Hand::addHarvestTile(HarvestTile harvestTile){
    harvestTiles->push_back(harvestTile);
}

HarvestTile Hand::useDeliveryTile() {
    HarvestTile temp = *deliveryTile;
    delete deliveryTile;
    deliveryTile = nullptr;
    return temp;
}

bool Hand::hasDeliveryTile() {
    return deliveryTile;
}

void Hand::setDeliveryTile(HarvestTile h) {
    deliveryTile = new HarvestTile(h);
}

ostream& operator<<(ostream& os, const Hand& h){
    os << "Hand\n";
    if(h.harvestTiles->empty()){
        os << "No Harvest Tiles\n";
    }
    else {
        os << "Harvest Tiles\n";
        for (int i = 0; i < h.harvestTiles->size(); i++) {
            HarvestTile tile = h.harvestTiles->at(i);
            os << i << ":" << (*tile.getTopLeftResource())[0] << (*tile.getTopRightResource())[0] << "  ";
        }
        if(h.deliveryTile)
            os << "2:Delivery Tile";
        os << "\n";
        for (int i = 0; i < h.harvestTiles->size(); i++) {
            HarvestTile tile = h.harvestTiles->at(i);
            os << "  " << (*tile.getBottomLeftResource())[0] << (*tile.getBottomRightResource())[0] << "  ";
        }
        os << "\n";
    }

    if(h.buildings->empty()){
        os << "No Buildings\n";
    }
    else{
        os << "Buildings\n";
        for (int i = 0; i < h.buildings->size(); i++) {
            Building building = h.buildings->at(i);
            os << i << ":" << (*building.getLabel())[0] << (*building.getNumber()) << "  ";
        }
        os << "\n";
    }
    return os;
}

RevealedBuildings::RevealedBuildings(){
    buildings = new vector<Building>;
}

RevealedBuildings::~RevealedBuildings(){
    buildings->clear();
    delete buildings;
}

void RevealedBuildings::addBuilding(Building b) {
    buildings->push_back(b);
}

Building RevealedBuildings::DrawBuilding(int index) {
    Building temp = buildings->at(index);
    buildings->erase(buildings->begin()+index);
    return temp;
}

int RevealedBuildings::getSize(){
    return buildings->size();
}

string RevealedBuildings::toString(){
    string str = "";
    for (int i = 0; i < buildings->size(); i++) {
        Building building = buildings->at(i);
        str += to_string(i);
        str += ":";
        str += (*building.getLabel())[0];
        str += to_string(*building.getNumber());
        str += "  ";
    }
    return str;
}