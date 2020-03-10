#include "VGMap.h"
#include "Cpp-Graph-Library-master/Graph.h"
#include <cctype>

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

VGMap::VGMap(const VGMap &vgMap){
    villageName = vgMap.villageName;
    resourceFlags = new vector<bool>(*vgMap.resourceFlags);
    board = new Graph(*vgMap.board);
}

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

double VGMap::getTileData(string position) const{
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
ostream& operator<<(ostream& os, const VGMap& v){
    os << v.villageName << "\n";
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 5; j++){
            int data = v.getTileData(to_string(j+i*5));
            os << '|';
            if(data == 0){
                if(i<2)
                    os << ' ';
                os << j+i*5;
            }
            else {
                int type = data/100%10;
                int flipped = data%10;
                char c = ' ';
                if (type == 1)
                    c = 'W';
                else if(type == 2)
                    c = 'F';
                else if(type == 3)
                    c = 'Q';
                else if(type == 4)
                    c = 'M';
                if (flipped)
                    c = tolower(c);

                os << " " << c;
            }
        }
        os << "| " << 6-i << "\n";
    }
    os << "  5  4  3  4  5  X\n";
    return os;
}