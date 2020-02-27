#ifndef COMP345_VGMAP_H
#define COMP345_VGMAP_H

#include <string>
#include "Cpp-Graph-Library-master/Graph.h"
#include <vector>

using std::string;
using std::vector;

class VGMap{
private:
    string villageName;
    vector<bool>* resourceFlags;
public:
    Graph *board;
    VGMap(string name);
    VGMap();
    ~VGMap();

    string getName();
    Graph* getBoard();
    vector<bool>* getFlags();
    double getTileData(string position);
    void setTileData(string position, double data);
    string getNorth(string position);
    string getSouth(string position);
    string getEast(string position);
    string getWest(string position);
};

#endif //COMP345_VGMAP_H
