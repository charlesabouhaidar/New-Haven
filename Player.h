//
// Created by Charles Abou Haidar on 2020-01-22.
//

#ifndef COMP345_PLAYER_H
#define COMP345_PLAYER_H

using namespace std;

class Player {
    private:
        VGMap* village;
        vector<double>* harvestTiles;
        vector<double>* buildings;
        int* resourceMarkers[4];
        ResourceGatherer* resourceGatherer;
        ScoreCounter* scoreCounter;
    public:
        Player(string villageName);
        PlaceHarvestTile(double tile, int location, int orientation);
        DrawBuilding();
        DrawHarvestTile();
        ResourceTracker(); //?
        BuildVillage(double building, int location, bool flipped);
        CalculateResources(int newTileLocation); //?
        VGMAP getVillage();
        vector<int> getHarvestTiles();
        vector<string> getBuildings();
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
