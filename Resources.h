//
// Created by Charles Abou Haidar on 2020-01-22.
//

#ifndef COMP345_RESOURCES_H
#define COMP345_RESOURCES_H

using namespace std;

class Resources {
    private:
        Deck* tiles;
        Deck* buildings;

    public:
        Resources();
        Deck getTiles();
        Deck getBuildings();
};

class Deck{
    private:
        vector<double>* deckContents;

    public:
        Deck(vector<double> contents);
        double draw();
};

class Hand{
    public:
        exchange();
};

class Tile{
    private:
        int[2][2]* resources;

    public:
        Tile(int topLeft, int topRight, int bottomLeft, int bottomRight);
        int* getResources();
};

class Building{
    private:
        int* type;
        int* cost;

    public:
        Building(int type, int cost);
        int getType();
        int getCost();
};

#endif //COMP345_RESOURCES_H