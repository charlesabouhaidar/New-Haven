//
// Created by Charles Abou Haidar on 2020-01-22.
//

#ifndef COMP345_PLAYER_H
#define COMP345_PLAYER_H

using namespace std;//change to individual usings

class Player {
    private:
        VGMap* village;
        vector<Tile>* harvestTiles;
        vector<Building>* buildings;
        int* resourceMarkers[4];
        ResourceGatherer* resourceGatherer;
        ScoreCounter* scoreCounter;

    public:
        Player(string villageName);
        PlaceHarvestTile(Tile tile, int location,8 int orientation);
        DrawBuilding();
        DrawHarvestTile();
        ResourceTracker(); //?
        BuildVillage(Building building, int location, bool flipped);
        CalculateResources(int newTileLocation); //?
        VGMAP getVillage();
        vector<Tile> getHarvestTiles();
        vector<Building> getBuildings();
        int* getResourceMarkers();
        setResourceMarkers(int[4] markers);
};

class ResourceGatherer{
    public:
        ResourceGatherer();
        CollectResources(int newTileLocation); //?
};

class ScoreCounter{
    public:
        ScoreCounter();
        int CalculateScore(VGMap village);
};

#endif //COMP345_PLAYER_H
