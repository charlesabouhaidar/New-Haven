#include "VGMap.h"
#include "Cpp-Graph-Library-master/Graph.h"

using std::string;
using std::to_string;

VGMap::VGMap(string name){
    resourceFlags = new vector<bool>;
    resourceFlags->assign(4, false);
    villageName = name;
    board = new Graph(false);
    vector<string> reachableNodes;
    int nodeName, fromNode, toNorthNode, toSouthNode, toEastNode, toWestNode, i, j, k, l, m;
    for( i = 0; i < 30; i++){ //create 25 nodes for the vgboard
        board->addNode(0, to_string(i));
    }
    for(j = 0; j < 5; j++){
        fromNode = j;
        toSouthNode = fromNode + 5;
        toEastNode = fromNode + 1;
        toWestNode = fromNode - 1;
        board->addEdge(to_string(fromNode), to_string(toSouthNode));
        if(fromNode == 0){
            board->addEdge(to_string(fromNode), to_string(toEastNode));
        }
        else if(fromNode == 4){
            board->addEdge(to_string(fromNode), to_string(toWestNode));
        }
        else{
            board->addEdge(to_string(fromNode), to_string(toEastNode));
            board->addEdge(to_string(fromNode), to_string(toWestNode));
        }
    }
    for(k = 5; k < 25; k++){
        fromNode = k;
        toSouthNode = fromNode + 5;
        toNorthNode = fromNode - 5;
        toEastNode = fromNode + 1;
        toWestNode = fromNode - 1;
        board->addEdge(to_string(fromNode), to_string(toNorthNode));
        board->addEdge(to_string(fromNode), to_string(toSouthNode));
        if(fromNode % 5 == 0){//left end side of vg board, not connected to west nodes
            board->addEdge(to_string(fromNode), to_string(toEastNode));
        }
        else if(fromNode % 5 == 4){ //right end side of vg board, not connected to east nodes
            board->addEdge(to_string(fromNode), to_string(toWestNode));
        }
        else{ //connected to 4 nodes
            board->addEdge(to_string(fromNode), to_string(toWestNode));
            board->addEdge(to_string(fromNode), to_string(toEastNode));
        }
    }
    for( l = 25; l < 30; l++){
        fromNode = l;
        toNorthNode = fromNode - 5;
        toEastNode = fromNode + 1;
        toWestNode = fromNode - 1;
        board->addEdge(to_string(fromNode), to_string(toNorthNode));
        if(fromNode == 25){
            board->addEdge(to_string(fromNode), to_string(toEastNode));
        }
        else if(fromNode == 29){
            board->addEdge(to_string(fromNode), to_string(toWestNode));
        }
        else{
            board->addEdge(to_string(fromNode), to_string(toWestNode));
            board->addEdge(to_string(fromNode), to_string(toEastNode));
        }
    }
}

VGMap::VGMap() : VGMap("unspecified"){}

VGMap::~VGMap(){
    delete resourceFlags;
    delete board;
};

string VGMap::getName(){
    return villageName;
}

Graph* VGMap::getBoard() {
    return board;
}

vector<bool>* VGMap::getFlags() {
    return resourceFlags;
}

double VGMap::getTileData(string position) {
    return board->getNodeValue(position);
}

void VGMap::setTileData(string position, double data) {
    board->setNodeValue(position, data);
}

string VGMap::getNorth(string position){
    vector<string> neighbors = board->neighborNames(position);
    for (int i = 0; i < neighbors.size(); i++) {
        if(stoi(neighbors.at(i)) <= stoi(position)-5)
            return neighbors.at(i);
    }
    return "";
}
string VGMap::getSouth(string position){
    vector<string> neighbors = board->neighborNames(position);
    for (int i = 0; i < neighbors.size(); i++) {
        if(stoi(neighbors.at(i)) >= stoi(position)+5)
            return neighbors.at(i);
    }
    return "";
}
string VGMap::getEast(string position){
    vector<string> neighbors = board->neighborNames(position);
    for (int i = 0; i < neighbors.size(); i++) {
        if(stoi(neighbors.at(i)) == stoi(position)+1)
            return neighbors.at(i);
    }
    return "";
}
string VGMap::getWest(string position){
    vector<string> neighbors = board->neighborNames(position);
    for (int i = 0; i < neighbors.size(); i++) {
        if(stoi(neighbors.at(i)) == stoi(position)-1)
            return neighbors.at(i);
    }
    return "";
}


