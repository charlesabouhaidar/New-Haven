#ifndef COMP345_VGMAP_H
#define COMP345_VGMAP_H

#include <string>
#include "Cpp-Graph-Library-master/Graph.h"

using std::string;

class VGMap{
private:
    string villageName;
public:
    Graph *board;
    VGMap(string name);
    VGMap();
    ~VGMap();

    string getName();
    Graph* getBoard();
    double getTileData(string position);
    void setTileData(string position, double data);
    string getNorth(string position);
    string getSouth(string position);
    string getEast(string position);
    string getWest(string position);
};

#endif //COMP345_VGMAP_H
