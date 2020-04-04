#include "GBMapLoader.h"
#include "GBMap.h"
#include <iostream>
#include <sstream>

using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;
using std::to_string;

GBMap* GBMapLoader::load(int numberOfPlayers) {
    ifstream myFile("../map"+to_string(numberOfPlayers)+".txt");
    string mystring, data, nodeNumber;
    GBMap *gbMap = new GBMap(numberOfPlayers);
    if (!myFile.is_open()) {
        perror("Error opening");
        exit(EXIT_FAILURE);
    } else {
        while (getline(myFile, mystring)) {
            if (mystring.size() > 8) {
                perror("Incorrect format, map can't load");
                exit(EXIT_FAILURE);
            }
            istringstream var(mystring);
            var >> nodeNumber >> data; //first number is the node number, second number is the data inside of that node(topRight,topLeft,bottomRight,bottomLeft, playerID)
            gbMap->setTileData(nodeNumber,stod(data));
        }
        myFile.close();
        return gbMap;
    }
}
