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
#include <ostream>

using std::vector;
using std::string;
using std::to_string;
using std::ostream;

/**
 * Tracks harvest tile information and behavior
 */
class HarvestTile {
private:
	string* topLeft;
	string* topRight;
	string* bottomLeft;
	string* bottomRight;

public:
	/**
     	* Default constructor
     	*/
	HarvestTile();
	
	/**
     	* Constructor, initializes parameters of a tile
	* @param harvestTile Harvest tile members initialized from this tile
     	*/
	HarvestTile(const HarvestTile& harvestTile);
	
	/**
     	* Deconstructs a harvest tile object
     	*/
	~HarvestTile();
	
	/**
     	* Sets the resources of the harvest tile based on a random selection of pre-set harvest tile resources
	* @param indexOfHT determines which resources are found on the harvest tile
     	*/
	HarvestTile(int indexOfHT);
	
	/**
     	* Copy constructor
	* @param h determines which resources are found on the copied harvest tile
     	*/
	HarvestTile& operator=(const HarvestTile& h);
	
	/**
     	* Returns the harvest tile's topLeft resource
	* @return The harvest tile's topLeft resource
     	*/
	string* getTopLeftResource();
	
	/**
     	* Returns the harvest tile's topRight resource
	* @return The harvest tile's topRight resource
     	*/
	string* getTopRightResource();
	
	/**
     	* Returns the harvest tile's bottomLeft resource
	* @return The harvest tile's bottomLeft resource
     	*/
	string* getBottomLeftResource();
	
	/**
     	* Returns the harvest tile's bottomRight resource
	* @return The harvest tile's bottomRight resource
     	*/
	string* getBottomRightResource();
	
	/**
     	* Sets the harvest tile's topLeft resource to wanted value
     	*/
	void setTopLeftResource(string* resource);
	
	/**
     	* Sets the harvest tile's topRight resource to wanted value
     	*/
	void setTopRightResource(string* resource);
	
	/**
     	* Sets the harvest tile's bottomLeft resource to wanted value
     	*/
	void setBottomLeftResource(string* resource);
	
	/**
     	* Sets the harvest tile's bottomRight resource to wanted value
     	*/
	void setBottomRightResource(string* resource);
};

/**
 * Tracks harvest tile deck information and behavior
 */
class HarvestTileDeck {
private:
	vector<HarvestTile>* harvestTiles;
public:
	
	/**
     	* Default constructor
     	*/
	HarvestTileDeck();
	
	/**
     	* Deconstructs a harvest tile deck object
     	*/
	~HarvestTileDeck();
	
	/**
     	* Returns a pointer to a harvest tile drawn from the deck
	* @return Pointer to drawn harvest tile
     	*/
	HarvestTile drawHarvestTile();
	
	/**
     	* Returns how many harvest tiles are still in the deck
	* @return Amount of harvest tiles left in the deck
     	*/
	int howManyHarvestTiles();
};

/**
 * Tracks building information and behavior
 */
class Building {
private:
	int* number;
	string* color;
	string* label;

public:
	
	/**
     	* Default constructor
     	*/
	Building();
	
	/**
     	* Initializes a building
	* @param building determines which values are found on the new building
     	*/
	Building(const Building& building);
	
	/**
     	* Deconstructs a building object
     	*/
	~Building();
	
	/**
     	* Sets the values of the building class members based on a random selection of pre-set buildings (number, color, label)
	* @param indexOfB determines which values are found on the building
     	*/
	Building(int indexOfB);
	
	/**
     	* Copy constructor
	* @param b determines which values are found on the copied building
     	*/
	Building& operator=(const Building& b);
	
	/**
     	* Returns the building's number value
	* @return The building's number value
     	*/
	int* getNumber();
	
	/**
     	* Returns the building's color value
	* @return The building's color value
     	*/
	string* getColor();
	
	/**
     	* Returns the building's label value
	* @return The building's label value
     	*/
	string* getLabel();
};

/**
 * Tracks building deck information and behavior
 */
class BuildingDeck {
private:
	vector<Building>* buildings;
public:
	
	/**
     	* Default constructor
     	*/
	BuildingDeck();
	
	/**
     	* Deconstructs a building deck object
     	*/
	~BuildingDeck();
	
	/**
     	* Returns a pointer to a building drawn from the deck
	* @return Pointer to drawn building
     	*/
	Building drawBuilding();
	
	/**
     	* Returns how many buildings are still in the deck
	* @return Amount of buildings left in the deck
     	*/
	int howManyBuildings();
};

/**
 * Tracks hand information and behavior
 */
class Hand {
private:
	vector<HarvestTile>* harvestTiles;
	vector<Building>* buildings;
public:
	
	/**
     	* Default constructor
     	*/
	Hand();
	
	/**
     	* Method that allows a player to place a harvest tile from his hand onto the board. 
	* A double is created based on parameters passed for the exchange information and fed into setTileData() 
	* @param board Which board to place harvest tile on
	* @param playerID Which player is placing the harvest tile
	* @param indexOfHarvestTile Which harvest tile to place form the hand
	* @param position Which node to place the harvest tile on
	* @param orientation In which orientation to place the harvest tile, allows to rotate the tile to selected orientation
     	*/
	void exchange(GBMap* board, int playerID, int indexOfHarvestTile, string position, int orientation);
	~Hand();
	
	/**
     	* Returns a pointer to a building from the hand at specified index
	* @param handIndex Specifies which building to return
	* @return Pointer to building in hand at specified index
     	*/
   	Building getBuilding(int handIndex);
	
	/**
     	* Returns a pointer to a harvest tile from the hand at specified index
	* @param handIndex Specifies which harvest tile to return
	* @return Pointer to harvest tile in hand at specified index
     	*/
    	HarvestTile getHarvestTile(int handIndex);
	
	/**
     	* Deletes a building from the hand at specified index
	* @param indexOfBuilding Specifies which building to delete
     	*/
	void deleteBuilding(int indexOfBuilding);
	
	/**
     	* Deletes a harvest tile from the hand at specified index
	* @param indexOfHarvestTile specifies which harvest tile to delete
     	*/
	void deleteHarvestTile(int indexOfHarvestTile);
	
	/**
     	* Adds a building to the hand
	* @param builing Specifies which building to add
     	*/
	void addBuilding(Building building);
	
	/**
     	* Adds a harvest tile to the hand
	* @param harvestTile Specifies which harvest tile to add
     	*/
	void addHarvestTile(HarvestTile harvestTile);
	
	/**
     	* Displays the hand's resource information
     	*/
	string toString();
	friend ostream& operator<<(ostream& os, const Hand& h);
};
ostream& operator<<(ostream& os, const Hand& h);

#endif //COMP345_RESOURCES_H    
