#include "Cpp-Graph-Library-master/Graph.h"
#include "Cpp-Graph-Library-master/Node.h"
#include "VGMapLoader.h"
#include "VGMap.h"
#include <iostream>

using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;


VGMap* VGMapLoader::vgMapLoader(String villageName) {
    ifstream myFile("../VGMapLoad.txt");
    string mystring, data, nodeNumber;
    VGMap *vgMap = new VGMap(villageName);
    // Graph *board = new Graph(false);
    if(!myFile.is_open()){
        perror("Error opening");
        exit(EXIT_FAILURE);
    }
    else {

            VGMap *vgMap = new VGMap(villageName);
            while (getline(myFile, mystring)) {
                if(mystring.empty()){ //if empty line just skip
                    continue;
                }
                else if(mystring.size() > 6){ //format is: nodeNumber data (total of 5 characters)
                    perror("Incorrect format, map can't load");
                    exit(EXIT_FAILURE);
                }
                VGMap *vgMap = new VGMap(villageName);
                istringstream var(mystring);
                var >> nodeNumber >> data; //first number is the node number, followed by type, numValue, flipped or not
                vgMap->getBoard()->addNode(stod(data), nodeNumber); //add data to nodeNumber in vgMap
                //output(nodeNumber, data);
                // board->addNode(stod(data), nodeNumber);
            }
            myFile.close();
            return vgMap;

    }
}
/*
void VGMapLoader::output(string nodeNumber, string data){
    cout << "\nNode number: " << nodeNumber << endl;
    cout << "Data: " << data << endl;
}
*/
