#include <iostream>
#include <string>
#include "GBMap.h"
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

int main(){
    cout << "GBMap tests";
    GBMap* gbMap = new GBMap(4);
    gbMap->setTileData("10", 22341);
    gbMap->setTileData("11", 11122);
    gbMap->setTileData("20", 33123);
    gbMap->setTileData("13", 14144);
    cout << gbMap->getTileData("10");
    cout << "Enter a node to see its immediate neighbors: \n";
    string nodeName;
    cin >> nodeName;
    vector<string> reachableNodes;
    reachableNodes = gbMap->getBoard()->neighborNames(nodeName);
    for (int t = 0; t < reachableNodes.size(); t++) {
        cout << reachableNodes.at(t) << "\n";
    }
    cout << "All board information";
    cout << gbMap->getBoard()->getInfo();
}