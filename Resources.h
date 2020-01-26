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

class Hand{ //?
    public:
        exchange(); //?
};

#endif //COMP345_RESOURCES_H
