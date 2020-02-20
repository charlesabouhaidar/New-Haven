//
// Created by Charles Abou Haidar on 2020-01-22.
//


#ifndef COMP345_VGMAP_H
#define COMP345_VGMAP_H

#include "Cpp-Graph-Library-master/Graph.h"

class VGMap{
public:
    Graph *vgBoard;
    VGMap();
    ~VGMap();
    void checkDoublePoints(VGMap *vgBoard);
};

#endif //COMP345_VGMAP_H
