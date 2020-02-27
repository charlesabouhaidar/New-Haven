#include "Player.h"
#include "GBMap.h"
#include <iostream>

using std::cout;
using std::cin;

int main(){
    cout << "------------Player Tests------------\n";
    Player* p1 = new Player(1, "Jamestown");
    Player* p2 = new Player(2, "Bluesville");
    //**tests?

    cout << "\n------------Facilities Tests------------\nResource Calculation\n";
    GBMap* gbMap1 = new GBMap(3);
    gbMap1->setTileData("10", 23120);
    gbMap1->setTileData("5", 23230);
    gbMap1->setTileData("0", 22230);
    gbMap1->setTileData("1", 23320);
    gbMap1->setTileData("11", 22120);
    p1->resourceTracker = p1->resourceGatherer->CollectResources(gbMap1, 10);
    cout << "Tile data";
    cout << " 0:" << gbMap1->getTileData("0");
    cout << " 1:" << gbMap1->getTileData("1");
    cout << " 5:" << gbMap1->getTileData("5");
    cout << " 10:" << gbMap1->getTileData("10");
    cout << " 11:" << gbMap1->getTileData("11");
    cout << "\nResource tracker for placement of 10: ";
    cout << p1->resourceTracker->at(0) << " ";
    cout << p1->resourceTracker->at(1) << " ";
    cout << p1->resourceTracker->at(2) << " ";
    cout << p1->resourceTracker->at(3) << "\n---\n";

    GBMap* gbMap2 = new GBMap(4);
    gbMap2->setTileData("0", 23120);
    gbMap2->setTileData("3", 23230);
    gbMap2->setTileData("4", 22230);
    gbMap2->setTileData("5", 23320);
    gbMap2->setTileData("13", 22120);
    p2->resourceTracker = p2->resourceGatherer->CollectResources(gbMap2, 3);
    cout << "Tile data";
    cout << " 0:" << gbMap2->getTileData("0");
    cout << " 3:" << gbMap2->getTileData("3");
    cout << " 4:" << gbMap2->getTileData("4");
    cout << " 5:" << gbMap2->getTileData("5");
    cout << " 13:" << gbMap2->getTileData("13");
    cout << "\nResource tracker for placement of 3: ";
    cout << p2->resourceTracker->at(0) << " ";
    cout << p2->resourceTracker->at(1) << " ";
    cout << p2->resourceTracker->at(2) << " ";
    cout << p2->resourceTracker->at(3) << "\n";

    cout << "\nVillage Calculation\nBuilding data";
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
    cout << " 0:" << p1->village->getTileData("0");
    cout << " 0:" << p1->village->getTileData("1");
    cout << " 0:" << p1->village->getTileData("2");
    cout << " 0:" << p1->village->getTileData("3");
    cout << " 0:" << p1->village->getTileData("4");
    cout << " 0:" << p1->village->getTileData("5");
    cout << " 0:" << p1->village->getTileData("10");
    cout << " 0:" << p1->village->getTileData("15");
    cout << " 0:" << p1->village->getTileData("20");
    cout << " 0:" << p1->village->getTileData("25");
    cout << " 0:" << p1->village->getTileData("6");
    cout << " 0:" << p1->village->getTileData("7");
    cout << "\nScore for village: " << p1->scoreCounter->CalculateScore(p1->getVillage()) << "\n---\n";

    p1->village->setTileData("0", 140);
    cout << "Same building data but with building 0 not flipped";
    cout << "\nScore for village: " << p1->scoreCounter->CalculateScore(p1->getVillage()) << "\n";

    system("pause");
}