#include "VGMapLoader.h"
#include "VGMap.h"
#include <iostream>

using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;

VGMap* VGMapLoader::load(string villageName) {
    ifstream myFile("../VGMapLoad.txt");
    string mystring, data, nodeNumber;
    VGMap *vgMap = new VGMap(villageName);
    if(!myFile.is_open()){
        perror("Error opening");
        exit(EXIT_FAILURE);
    }
    else {
        while (getline(myFile, mystring)) {
            if(mystring.size() > 6){ //format is: nodeNumber data (total of 5 characters)
                perror("Incorrect format, map can't load");
                exit(EXIT_FAILURE);
            }
            istringstream var(mystring);
            var >> nodeNumber >> data; //first number is the node number, followed by type, numValue, flipped or not
            vgMap->setTileData(nodeNumber, stod(data)); //add data to nodeNumber in vgMap
        }
        myFile.close();
    }
    return vgMap;
}
