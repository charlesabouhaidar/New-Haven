//
// Created by Charles Abou Haidar on 2020-01-22->
//

#include "VGMap.h"
#include "Cpp-Graph-Library-master/Graph.h"
#include <iostream>
#include <vector>
using namespace std;

VGMap::VGMap(){
    vgBoard = new Graph(false);
    vector<string> reachableNodes;
    int nodeName, fromNode, toNorthNode, toSouthNode, toEastNode, toWestNode, i, j, k, l, m;
    Node *node[30];
    for( i = 0; i < 30; i++){ //create 25 nodes for the vgboard
        node[i] = new Node(1, to_string(i));
        vgBoard->addNode(1, to_string(i));
    }
    for(j = 0; j < 5; j++){ //first 5 nodes all have south nodes, but no north nodes
        fromNode = j;
        toSouthNode = fromNode + 5;
        toEastNode = fromNode + 1;
        toWestNode = fromNode - 1;
        vgBoard->addEdge(to_string(fromNode), to_string(toSouthNode));
        if(fromNode == 0){ //top left node (no west node)
            vgBoard->addEdge(to_string(fromNode), to_string(toEastNode));
        }
        else if(fromNode == 4){ //top right node (no east node)
            vgBoard->addEdge(to_string(fromNode), to_string(toWestNode));
        }
        else{ //all other nodes that aren't in corners
            vgBoard->addEdge(to_string(fromNode), to_string(toEastNode));
            vgBoard->addEdge(to_string(fromNode), to_string(toWestNode));
        }
    }
    for(k = 5; k < 25; k++){ //remaining nodes until right before the last row
        fromNode = k;
        toSouthNode = fromNode + 5;
        toNorthNode = fromNode - 5;
        toEastNode = fromNode + 1;
        toWestNode = fromNode - 1;
        vgBoard->addEdge(to_string(fromNode), to_string(toNorthNode)); //all these nodes have a north node
        vgBoard->addEdge(to_string(fromNode), to_string(toSouthNode)); //all these nodes have a south node
        if(fromNode % 5 == 0){//left end side of vg board, not connected to west nodes
            vgBoard->addEdge(to_string(fromNode), to_string(toEastNode));
        }
        else if(fromNode % 5 == 4){ //right end side of vg board, not connected to east nodes
            vgBoard->addEdge(to_string(fromNode), to_string(toWestNode));
        }
        else{ //connected to 4 nodes (all other cases)
            vgBoard->addEdge(to_string(fromNode), to_string(toWestNode));
            vgBoard->addEdge(to_string(fromNode), to_string(toEastNode));
        }
    }
    for( l = 25; l < 30; l++){
        fromNode = l;
        toNorthNode = fromNode - 5;
        toEastNode = fromNode + 1;
        toWestNode = fromNode - 1;
        vgBoard->addEdge(to_string(fromNode), to_string(toNorthNode)); //all these nodes have north nodes but no south nodes (bottom of the board)
        if(fromNode == 25){ //bottom left corner doesn't have a west node
            vgBoard->addEdge(to_string(fromNode), to_string(toEastNode));
        }
        else if(fromNode == 29){ //bottom right corner doesn't have an east node
            vgBoard->addEdge(to_string(fromNode), to_string(toWestNode));
        }
        else{ //all other cases that have both east and west nodes
            vgBoard->addEdge(to_string(fromNode), to_string(toWestNode));
            vgBoard->addEdge(to_string(fromNode), to_string(toEastNode));
        }
    }


}

VGMap::~VGMap()= default;


Graph* VGMap::getBoard() {
    return vgBoard;
}


string VGMap::getNorth(string position){
    vector<string> neighbors = vgBoard->neighborNames(position);
    for (int i = 0; i < neighbors.size(); i++) {
        if(stoi(neighbors.at(i)) <= stoi(position)-5)
            return neighbors.at(i);
    }
    return "";
}
string VGMap::getSouth(string position){
    vector<string> neighbors = vgBoard->neighborNames(position);
    for (int i = 0; i < neighbors.size(); i++) {
        if(stoi(neighbors.at(i)) >= stoi(position)+5)
            return neighbors.at(i);
    }
    return "";
}
string VGMap::getEast(string position){
    vector<string> neighbors = vgBoard->neighborNames(position);
    for (int i = 0; i < neighbors.size(); i++) {
        if(stoi(neighbors.at(i)) == stoi(position)+1)
            return neighbors.at(i);
    }
    return "";
}
string VGMap::getWest(string position){
    vector<string> neighbors = vgBoard->neighborNames(position);
    for (int i = 0; i < neighbors.size(); i++) {
        if(stoi(neighbors.at(i)) == stoi(position)-1)
            return neighbors.at(i);
    }
    return "";
}



