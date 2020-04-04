#ifndef COMP345_VGMAPLOADER_H
#define COMP345_VGMAPLOADER_H

#include "VGMap.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::string;

class VGMapLoader {

public:
    VGMap* load(string villageName);
};


#endif //COMP345_VGMAPLOADER_H
