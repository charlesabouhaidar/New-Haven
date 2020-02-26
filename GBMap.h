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
    GBMap(const GBMap &numOfPlayers);
    Graph* getBoard();
    double getTileData(string position);
    void setTileData(string position, double data);
    string getNorth(string position);
    string getSouth(string position);
    string getEast(string position);
    string getWest(string position);
};
#endif //COMP345_GBMAP_H
