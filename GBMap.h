//
// Created by Charles Abou Haidar on 2020-01-22.
//

#ifndef COMP345_GBMAP_H
#define COMP345_GBMAP_H

#include <iostream>
#include "Cpp-Graph-Library-master/Graph.h"
#include "Cpp-Graph-Library-master/Node.h"
#include <vector>
using std::string;
using std::vector;

class GBMap{
public:
    static Graph board;
    static int fromNode, toSouthNode, toNorthNode, toEastNode, toWestNode, nodeName, i, j, k, l, m, n, o, p, q, r, s, t;
    static void createBoardGame(int numOfPlayers);
    static vector<string> reachableNodes;
};
#endif //COMP345_GBMAP_H
