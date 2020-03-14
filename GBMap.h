#ifndef COMP345_GBMAP_H
#define COMP345_GBMAP_H

#include "Cpp-Graph-Library-master/Graph.h"
#include <string>
#include <ostream>
#include <vector>

using std::string;
using std::ostream;
using std::vector;

class GBMap{

private:
    Graph *board;
public:
    int playerCount;
    GBMap();
    GBMap(int numOfPlayers);
    GBMap(GBMap &gbMap);
    Graph* getBoard();
    double getTileData(string position) const;
    void setTileData(string position, double data);
    string getNorth(string position);
    string getSouth(string position);
    string getEast(string position);
    string getWest(string position);
    vector<string> toStrings();
};
#endif //COMP345_GBMAP_H
