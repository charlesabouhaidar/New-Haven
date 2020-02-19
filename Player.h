#ifndef COMP345_PLAYER_H
#define COMP345_PLAYER_H

#include <string>
#include "VGMap.h"
#include "Resources.h"
#include "GBMap.h"

/**
 * Gathers resources from tile placements
 */
class ResourceGatherer{
    public:
        /**
         * Calculates the resources gathered from a tile placement
         * @param board The game board
         * @param newTileLocation The location of the placed tile
         * @return A resource tracker with the gathered resources
         */
        int* CollectResources(GBMap board, int newTileLocation);
};

/**
 * Calculates village score
 */
class ScoreCounter{
    public:
        /**
         * Calculates the score from a given village
         * @param village The village to calculate the score from
         * @return The calculated score
         */
        int CalculateScore(VGMap village);
};

/**
 * Tracks player information and behavior
 */
class Player {
    private:
        int* playerID;
        VGMap* village;
        Hand* hand;
        int* resourceTracker[4];
        ResourceGatherer* resourceGatherer;
        ScoreCounter* scoreCounter;

    public:
        /**
         * Constructs a new player with an unspecified village name and ID zero
         */
        Player();

        /**
         * Constructs a new player with a given village name and ID
         * @param id The ID to use for the player
         * @param villageName The name to use for the player's village
         */
        Player(int id, string villageName);

        /**
         * Deconstructs a player object
         */
        ~Player();

        /**
         * Places a harvest tile onto the game board
         * @param board The game board to place the tile on
         * @param tile The tile to place
         * @param location The location on the board to place the tile
         * @param orientation The orientation of the tile
         */
        void PlaceHarvestTile(GBMap board, HarvestTile tile, int location, int orientation);

        /**
         * Adds a building to the player's hand from the building deck
         */
        void DrawBuilding(BuildingDeck buildingDeck);

        /**
         * Adds a harvest tile to the player's hand from the tile deck
         */
        void DrawHarvestTile(HarvestTileDeck tileDeck);

        /**
         * Gets the player's resource tracker
         * @return The player's resource tracker
         */
        int* ResourceTracker();

        /**
         * Places a building tile onto the player's village board
         * @param building The building to place
         * @param location The location to place the building
         * @param flipped Whether the building is played face up or flipped
         */
        void BuildVillage(Building building, int location, bool flipped);

        /**
         * Calculates and adds resources to the resource tracker for a tile placement
         * @param newTileLocation The location of the placed tile
         */
        void CalculateResources(int newTileLocation);

        /**
         * Gets the player's village board
         * @return The player's village board
         */
        VGMap getVillage();

        /**
         * Gets the player's hand
         * @return The player's hand
         */
        Hand getHand();
};
#endif //COMP345_PLAYER_H
