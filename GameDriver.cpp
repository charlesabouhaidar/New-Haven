#include "GBMap.h"
#include "Player.h"
#include "Resources.h"
#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::string;

int main(){
    //set player count
    string playercountstr;
    while(!(playercountstr == "2" || playercountstr == "3" || playercountstr == "4")) {
        cout << "Enter number of players:";
        cin >> playercountstr;
    }
    int playercount = stoi(playercountstr);

    //set gameboard
    //*use gamemaploader
    GBMap* gameBoard = new GBMap(playercount);

    //set players
    //*use villagemaploader
    Player* players[playercount];
    for(int i = 0; i < playercount; i++){
        string villageName;
        cout << "Enter village name for Player " << i+1 << ":";
        cin >> villageName;
        players[i] = new Player(i+1, villageName);
    }

    //set decks
    //*not random harvest tiles?
    BuildingDeck* buildings = new BuildingDeck();
    HarvestTileDeck* harvestTiles = new HarvestTileDeck();

    //set face up buildings pool
    RevealedBuildings* revealedBuildings = new RevealedBuildings();
    for(int i = 0; i < 5; i++) {
        revealedBuildings->addBuilding(buildings->drawBuilding());
    }

    //set hands, 6 buildings, 2 harvest tiles, 1 shipment tile
    for(int i = 0; i < playercount; i++){
        for(int j = 0; j < 6; j++){
            players[i]->DrawBuilding(buildings);
        }
        players[i]->DrawHarvestTile(harvestTiles);
        players[i]->DrawHarvestTile(harvestTiles);
        players[i]->getHand()->setDeliveryTile(harvestTiles->drawHarvestTile());
    }

    for(int round = 1; round < 11; round++){
        cout << "-----ROUND " << round << "-----\n";
        for(int activePlayer = 0; activePlayer < playercount; activePlayer++){
            cout << "Player " << activePlayer+1 << "'s Turn\n";
            vector<int>* resourceTracker = players[activePlayer]->ResourceTracker();

            //place tile, generate resources, place buildings, next players place buildings
            //draw buildings (atleast one from pool) & harvest tile if applicable, replace face ups
            //reset markers
        }
    }

    for(int i = 0; i < playercount; i++)
        delete players[i];
    delete gameBoard;
    delete buildings;
    delete harvestTiles;
    delete revealedBuildings;
}