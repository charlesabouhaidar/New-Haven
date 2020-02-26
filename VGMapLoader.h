//
// Created by Charles Abou Haidar on 2020-01-22.
//

#ifndef COMP345_VGMAPLOADER_H
#define COMP345_VGMAPLOADER_H

#include "Cpp-Graph-Library-master/Graph.h"
#include "Cpp-Graph-Library-master/Node.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class VGMapLoader {

public:
    VGMapLoader();
    void output(string nodeNumber, string data);

};


#endif //COMP345_VGMAPLOADER_H
