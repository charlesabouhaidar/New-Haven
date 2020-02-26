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
    for(j = 0; j < 5; j++){
        fromNode = j;
        toSouthNode = fromNode + 5;
        toEastNode = fromNode + 1;
        toWestNode = fromNode - 1;
        vgBoard->addEdge(to_string(fromNode), to_string(toSouthNode));
        if(fromNode == 0){
            vgBoard->addEdge(to_string(fromNode), to_string(toEastNode));
        }
        else if(fromNode == 4){
            vgBoard->addEdge(to_string(fromNode), to_string(toWestNode));
        }
        else{
            vgBoard->addEdge(to_string(fromNode), to_string(toEastNode));
            vgBoard->addEdge(to_string(fromNode), to_string(toWestNode));
        }
    }
    for(k = 5; k < 25; k++){
        fromNode = k;
        toSouthNode = fromNode + 5;
        toNorthNode = fromNode - 5;
        toEastNode = fromNode + 1;
        toWestNode = fromNode - 1;
        vgBoard->addEdge(to_string(fromNode), to_string(toNorthNode));
        vgBoard->addEdge(to_string(fromNode), to_string(toSouthNode));
        if(fromNode % 5 == 0){//left end side of vg board, not connected to west nodes
            vgBoard->addEdge(to_string(fromNode), to_string(toEastNode));
        }
        else if(fromNode % 5 == 4){ //right end side of vg board, not connected to east nodes
            vgBoard->addEdge(to_string(fromNode), to_string(toWestNode));
        }
        else{ //connected to 4 nodes
            vgBoard->addEdge(to_string(fromNode), to_string(toWestNode));
            vgBoard->addEdge(to_string(fromNode), to_string(toEastNode));
        }
    }
    for( l = 25; l < 30; l++){
        fromNode = l;
        toNorthNode = fromNode - 5;
        toEastNode = fromNode + 1;
        toWestNode = fromNode - 1;
        vgBoard->addEdge(to_string(fromNode), to_string(toNorthNode));
        if(fromNode == 25){
            vgBoard->addEdge(to_string(fromNode), to_string(toEastNode));
        }
        else if(fromNode == 29){
            vgBoard->addEdge(to_string(fromNode), to_string(toWestNode));
        }
        else{
            vgBoard->addEdge(to_string(fromNode), to_string(toWestNode));
            vgBoard->addEdge(to_string(fromNode), to_string(toEastNode));
        }
    }
    cout << "Enter a node to see its immediate neighbors: " << endl;
    cin >> nodeName;
    reachableNodes = vgBoard->neighborNames(to_string(nodeName));
    for( m = 0; m < reachableNodes.size(); m++){
        cout << reachableNodes.at(m) << endl;
    }

}

VGMap::~VGMap()= default;

