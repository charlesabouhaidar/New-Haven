#ifndef COMP345_GBMAPLOADER_H
#define COMP345_GBMAPLOADER_H

#include <string>
#include "GBMap.h"

using std::string;

class GBMapLoader {
public:
    GBMapLoader();
    void output(string nodeNumber, string data);
};

#endif //COMP345_GBMAPLOADER_H
