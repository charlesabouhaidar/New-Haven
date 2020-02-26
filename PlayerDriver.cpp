#include "Player.h"
#include "GBMap.h"
#include <iostream>

using std::cout;

int main(){
    cout << "Player Tests\n";
    Player* p1 = new Player(3, "Jamestown");
    cout << *(p1->playerID) << "\n";

    cout << "Facilities Tests\n";
    GBMap* gbMap = new GBMap(3);
    gbMap->getBoard()->setNodeValue("10", 23120);
    gbMap->getBoard()->setNodeValue("5", 23230);
    gbMap->getBoard()->setNodeValue("0", 22230);
    gbMap->getBoard()->setNodeValue("1", 23320);
    gbMap->getBoard()->setNodeValue("11", 22120);

    p1->resourceTracker = p1->resourceGatherer->CollectResources(*gbMap, 10);
    cout << p1->resourceTracker->at(0) << " ";
    cout << p1->resourceTracker->at(1) << " ";
    cout << p1->resourceTracker->at(2) << " ";
    cout << p1->resourceTracker->at(3) << " ";

    cout << "\n" << gbMap->getBoard()->getNodeValue("10");
    cout << "\n" << gbMap->getBoard()->getNodeValue("5");
    cout << "\n" << gbMap->getBoard()->getNodeValue("0");
    cout << "\n" << gbMap->getBoard()->getNodeValue("1");
    cout << "\n" << gbMap->getBoard()->getNodeValue("11");
}