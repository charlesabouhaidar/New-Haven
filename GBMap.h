#ifndef COMP345_GBMAP_H
#define COMP345_GBMAP_H

#include "Cpp-Graph-Library-master/Graph.h"
#include <string>

using std::string;

class GBMap{

private:
    Graph *board;
public:
    int numOfPlayers;
    GBMap();
    GBMap(int numOfPlayers);

    Graph* getBoard();
    double getTileData(string position);
    void setTileData(string position, double data);
};



#endif //COMP345_GBMAP_H
