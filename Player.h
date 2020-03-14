#ifndef COMP345_PLAYER_H
#define COMP345_PLAYER_H

#include <string>
#include <vector>
#include "VGMap.h"
#include "Resources.h"
#include "GBMap.h"

/**
 * Gathers resources from tile placements
 */
class ResourceGatherer{
    private:
    /**
     * Sums together all chained resources for CollectResources
     * @param board The board to collect off of
     * @param location Tile location on game board
     * @param corner Corner of the tile
     * @param resource Current resource being summed
     * @return The sum of all the chained resource
     */
        int collect(GBMap* board, string location, int corner, int resource);

    public:
        /**
         * Calculates the resources gathered from a tile placement
         * @param board The game board
         * @param newTileLocation The location of the placed tile
         * @return A resource tracker with the gathered resources
         */
        vector<int>* CollectResources(GBMap* board, int newTileLocation);
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
        int CalculateScore(VGMap* village);
};

/**
 * Tracks player information and behavior
 */
class Player {
    private:
        int* playerID;
        VGMap* village;
        Hand* hand;
        vector<int>* resourceTracker;
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

        Player& operator=(const Player &p);

        /**
         * Places a harvest tile onto the game board
         * @param board The game board to place the tile on
         * @param tile The index of the tile to place in the hand
         * @param location The location on the board to place the tile
         * @param orientation The orientation of the tile
         * @return If the placement was successful
         */
        bool PlaceHarvestTile(GBMap* board, int tileIndex, int location, int orientation);

        /**
         * Adds a building to the player's hand from the building deck
         */
        void DrawBuilding(BuildingDeck* buildingDeck);

        /**
         * Adds a harvest tile to the player's hand from the tile deck
         */
        void DrawHarvestTile(HarvestTileDeck* tileDeck);

        /**
         * Gets the player's resource tracker
         * @return The player's resource tracker
         */
        vector<int>* ResourceTracker();

        /**
         * Places a building tile onto the player's village board
         * @param buildingIndex The index of the building to place in the hand
         * @param location The location to place the building
         * @param flipped Whether the building is played face up or flipped
         * @return If the placement was successful
         */
        bool BuildVillage(int buildingIndex, int location, bool flipped, vector<int>* tracker);

        /**
         * Calculates and adds resources to the resource tracker for a tile placement
         * @param newTileLocation The location of the placed tile
         */
        void CalculateResources(GBMap* board, int newTileLocation);

        /**
         * Gets the player's village board
         * @return The player's village board
         */
        VGMap* getVillage();

        /**
         * Gets the player's hand
         * @return The player's hand
         */
        Hand* getHand();

        ScoreCounter* getScoreCounter();

        string tracker_to_string();
};
#endif //COMP345_PLAYER_H
