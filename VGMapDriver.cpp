#include <iostream>
#include "VGMap.h"
#include "Cpp-Graph-Library-master/Graph.h"
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;

int main(){
    string nodeName;
    vector<string> reachableNodes;
    VGMap *vgBoard = new VGMap();
    cout << vgBoard->getName() << "\n";
    cout << "Enter a node to see its immediate neighbors: " << "\n";
    cin >> nodeName;
    reachableNodes = vgBoard->getBoard()->neighborNames(nodeName);
    for (int t = 0; t < reachableNodes.size(); t++) {
        cout << reachableNodes.at(t) << "\n";
    }
    return 0;
}

