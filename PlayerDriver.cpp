#include "Player.h"
#include "GBMap.h"
#include <iostream>

using std::cout;

int main(){
    cout << "Player Tests\n";
    Player* p1 = new Player(3, "Jamestown");
    cout << *(p1->playerID) << "\n";

    cout << "Facilities Tests\nResource Calculation\n";
    GBMap* gbMap = new GBMap(3);
    gbMap->getBoard()->setNodeValue("10", 23120);
    gbMap->getBoard()->setNodeValue("5", 23230);
    gbMap->getBoard()->setNodeValue("0", 22230);
    gbMap->getBoard()->setNodeValue("1", 23320);
    gbMap->getBoard()->setNodeValue("11", 22120);
    p1->resourceTracker = p1->resourceGatherer->CollectResources(gbMap, 10);
    cout << p1->resourceTracker->at(0) << " ";
    cout << p1->resourceTracker->at(1) << " ";
    cout << p1->resourceTracker->at(2) << " ";
    cout << p1->resourceTracker->at(3) << " ";

    cout << "\nVillage Calculation\n";
    p1->village->setTileData("0", 141);
    p1->village->setTileData("1", 160);
    p1->village->setTileData("2", 160);
    p1->village->setTileData("3", 160);
    p1->village->setTileData("4", 160);
    p1->village->setTileData("5", 250);
    p1->village->setTileData("10", 240);
    p1->village->setTileData("15", 230);
    p1->village->setTileData("20", 320);
    p1->village->setTileData("25", 310);
    p1->village->setTileData("6", 431);
    p1->village->setTileData("7", 431);
    cout << p1->scoreCounter->CalculateScore(p1->getVillage());
}