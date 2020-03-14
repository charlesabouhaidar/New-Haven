#ifndef COMP345_VGMAP_H
#define COMP345_VGMAP_H

#include <string>
#include "Cpp-Graph-Library-master/Graph.h"
#include <vector>
#include <ostream>

using std::string;
using std::vector;
using std::ostream;

class VGMap{
private:
    string villageName;
    vector<bool>* resourceFlags;
    int* buildingCount;
public:
    Graph *board;
    VGMap(string name);
    VGMap();
    VGMap(const VGMap &vgMap);
    ~VGMap();

    string getName();
    Graph* getBoard();
    vector<bool>* getFlags();
    double getTileData(string position) const;
    void setTileData(string position, double data);
    string getNorth(string position);
    string getSouth(string position);
    string getEast(string position);
    string getWest(string position);
    int getBuildingCount();
    void incrementBuildingCount();
    vector<string> toStrings();
};
#endif //COMP345_VGMAP_H
