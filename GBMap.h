//
// Created by Charles Abou Haidar on 2020-01-22.
//

#ifndef COMP345_GBMAP_H
#define COMP345_GBMAP_H

#include <iostream>
#include "Cpp-Graph-Library-master/Graph.cpp"
#include "Cpp-Graph-Library-master/Graph.h"
#include "Cpp-Graph-Library-master/Node.cpp"
#include "Cpp-Graph-Library-master/Node.h"
#include <vector>

using namespace std;

class BoardGame{
public:
     int fromNode, toSouthNode, toNorthNode, toEastNode, toWestNode;
     static void createBoardGame(int numOfPlayers);

};

#endif //COMP345_GBMAP_H
