//
// Created by Charles Abou Haidar on 2020-01-22.
//

#include <iostream>
#include "GBMap.h"
#include "Cpp-Graph-Library-master/Graph.cpp"
#include "Cpp-Graph-Library-master/Graph.h"
#include "Cpp-Graph-Library-master/Node.cpp"
#include "Cpp-Graph-Library-master/Node.h"

using namespace std;

int main(){
    int *numOfPlayers, *numOfNodes;
    cout << "Enter the number of players for this session: " << endl;
    cin >> *numOfPlayers;

    if(*numOfPlayers == 2){
         *numOfNodes = 25;
         Graph();
    }
    else if(*numOfPlayers == 3){
         *numOfNodes = 35;
         Graph();
    }
    else if (*numOfPlayers == 4){
        *numOfNodes = 45;
        Graph();
    }
    return 0;
}
