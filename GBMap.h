
//
// Created by Charles Abou Haidar on 2020-01-22.
//

#ifndef COMP345_GBMAP_H
#define COMP345_GBMAP_H

#include <iostream>
#include <vector>
#include "Cpp-Graph-Library-master/Graph.h"
using namespace std;

class GBMap{

private:
    Graph *board;
public:
    int numOfPlayers;
    GBMap();
    GBMap(int numOfPlayers);
};



#endif //COMP345_GBMAP_H
