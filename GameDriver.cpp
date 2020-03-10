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

    //*set face up buildings pool

    //set hands, 6 buildings, 2 harvest tiles
    //*1 shipment tile
    for(int i = 0; i < playercount; i++){
        players[i]->DrawBuilding(buildings);
        players[i]->DrawBuilding(buildings);
        players[i]->DrawBuilding(buildings);
        players[i]->DrawBuilding(buildings);
        players[i]->DrawBuilding(buildings);
        players[i]->DrawBuilding(buildings);
        players[i]->DrawHarvestTile(harvestTiles);
        players[i]->DrawHarvestTile(harvestTiles);
    }

    //loop until one space left (count turns)
    //set active player pointer, set pointer to current players resource tracker?
    //place tile, generate resources, place buildings, next players place buildings
    //draw buildings (atleast one from pool) & harvest tile if applicable, replace face ups
    //reset markers

    for(int i = 0; i < playercount; i++)
        delete players[i];
    delete gameBoard;
    delete buildings;
    delete harvestTiles;
}