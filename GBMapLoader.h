#ifndef COMP345_GBMAPLOADER_H
#define COMP345_GBMAPLOADER_H

#include <string>
#include <fstream>
#include "GBMap.h"

using std::string;

class GBMapLoader {
public:
    GBMap* load(int numberOfPlayers);
};

#endif //COMP345_GBMAPLOADER_H
