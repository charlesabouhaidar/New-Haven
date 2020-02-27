//
// Created by Charles Abou Haidar on 2020-01-22.
//
#include <iostream>
#include "VGMap.h"
#include "Cpp-Graph-Library-master/Graph.h"
#include <vector>
using namespace std;

int main(){
    int nodeNumber{0};
    VGMap *vgBoard = new VGMap();
    Graph *board = vgBoard->getBoard();
    for (int i = 0; i < 30; i++) {
        cout << "Node " << i << " Value: " << board->getNodeValue(to_string(i)) << endl;
        cout << "East node: " << vgBoard->getEast(to_string(i)) << endl;
        cout << "West node: " << vgBoard->getWest(to_string(i)) << endl;
        cout << "North node: " << vgBoard->getNorth(to_string(i)) << endl;
        cout << "South node: " << vgBoard->getSouth(to_string(i)) << endl << endl;
    }
    cout << "Enter a node number to check it's value: " << endl;
    cin >> nodeNumber;
    try{
        cout << "Node number: " << nodeNumber << " Value: " << board->getNodeValue(to_string(nodeNumber));
    }
    catch(exception& e) {
        perror("Node out of bounds/doesn't exist!" );
        exit(EXIT_FAILURE);

    }

    return 0;
}

