#include "GBMap.h"
#include "Player.h"
#include "Resources.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int round_num, activePlayer, playercount;
bool usedDelivery;
RevealedBuildings* revealedBuildings;
Player* players[4];
GBMap* gameBoard;
BuildingDeck* buildingDeck;
HarvestTileDeck* harvestTileDeck;
vector<int>* resourceTracker;

void display_gamestate(){
    cout << string(50, '\n');
    cout << "ROUND " << to_string(round_num) << "  PLAYER " << to_string(activePlayer+1) << "'S TURN\n";

    //get string data
    vector<string> gameBoardStrings = gameBoard->toStrings();
    vector<string> village[playercount];
    for(int i = 0; i < playercount; i++){
        village[i] = players[i]->getVillage()->toStrings();
    }
    string revealedStr = revealedBuildings->toString();

    //print headers
    cout << "Gameboard";
    if(playercount < 4){
        cout << "           ";
    }
    else{
        cout << "                 ";
    }
    for(int i=0; i < playercount; i++){
        string name = players[i]->getVillage()->getName();
        cout << players[i]->getVillage()->getName();
        cout << string(22-name.length(), ' ');
    }
    cout << "\n";

    //print villages
    for(int i=0; i < 7; i++){
        cout << gameBoardStrings.at(i);
        for(int j=0; j < playercount; j++){
            cout << "    " << village[j].at(i);
        }
        cout << "\n";
    }

    //print faceup building pool
    cout << gameBoardStrings.at(7) << "\n";
    cout << gameBoardStrings.at(8) << "\n";
    cout << gameBoardStrings.at(9) << "    Revealed Buildings\n";
    cout << gameBoardStrings.at(10) << "    " << revealedStr << "\n";

    //print resource tracker
    cout << gameBoardStrings.at(11) << "\n";
    cout << gameBoardStrings.at(12) << "\n";
    cout << gameBoardStrings.at(13) << "    Resource Tracker\n";
    cout << gameBoardStrings.at(14) << "    " << players[activePlayer]->tracker_to_string() << "\n";

    //finish printing gameboard
    for(int i=15; i < gameBoardStrings.size(); i++){
        cout << gameBoardStrings.at(i) << "\n";
    }
    cout << "\n";
}

void initialize(){
    //set player count
    string playercountstr;
    while(!(playercountstr == "2" || playercountstr == "3" || playercountstr == "4")) {
        cout << "Enter number of players:";
        cin >> playercountstr;
    }
    playercount = stoi(playercountstr);

    //set gameboard
    //*use gamemaploader
    gameBoard = new GBMap(playercount);

    //set players
    //*use villagemaploader
    for(int i = 0; i < playercount; i++){
        string villageName;
        cout << "Enter village name for Player " << i+1 << ":";
        cin >> villageName;
        if(villageName.length() > 17)
            villageName = villageName.substr(0, 17);
        players[i] = new Player(i+1, villageName);
    }

    //set decks
    //*not random harvest tiles?
    buildingDeck = new BuildingDeck();
    harvestTileDeck = new HarvestTileDeck();

    //set face up buildings pool
    revealedBuildings = new RevealedBuildings();
    for(int i = 0; i < 5; i++) {
        revealedBuildings->addBuilding(buildingDeck->drawBuilding());
    }

    //set hands, 6 buildings, 2 harvest tiles, 1 shipment tile
    for(int i = 0; i < playercount; i++){
        for(int j = 0; j < 6; j++){
            players[i]->DrawBuilding(buildingDeck);
        }
        players[i]->DrawHarvestTile(harvestTileDeck);
        players[i]->DrawHarvestTile(harvestTileDeck);
        players[i]->getHand()->setDeliveryTile(harvestTileDeck->drawHarvestTile());
    }
}

void placeTile(){

}

void placeBuildings(){

}

void draw(){
    //draw buildings
    bool fromPool = false;
    for(int i=0; i<4; i++){
        if(resourceTracker->at(i) == 0){
            display_gamestate();
            cout << "Player " << to_string(activePlayer+1) << "'s " <<*players[activePlayer]->getHand() << "\n";
            if(!fromPool){
                string selectedstr = "";
                int selected = 5;
                while(selected >= revealedBuildings->getSize()) {
                    cout << "Draw a revealed building:";
                    cin >> selectedstr;
                    if (selectedstr == "0" || selectedstr == "1" || selectedstr == "2" ||
                        selectedstr == "3" || selectedstr == "4") {
                        selected = stoi(selectedstr);
                    }
                }
                players[activePlayer]->getHand()->addBuilding(revealedBuildings->DrawBuilding(selected));
                fromPool = true;
            }
            else{
                string option = "";
                cout << "Draw from revealed (0) or Draw from deck (1)\n";
                while(!(option == "0" || option == "1")){
                    cout << "Draw Location:";
                    cin >> option;
                }
                if(option == "0"){
                    string selectedstr;
                    int selected = 5;
                    while(selected >= revealedBuildings->getSize()) {
                        cout << "Draw a revealed building:";
                        cin >> selectedstr;
                        if (selectedstr == "0" || selectedstr == "1" || selectedstr == "2" ||
                            selectedstr == "3" || selectedstr == "4") {
                            selected = stoi(selectedstr);
                        }
                    }
                    players[activePlayer]->getHand()->addBuilding(revealedBuildings->DrawBuilding(selected));
                    fromPool = true;
                }
                else{
                    players[activePlayer]->DrawBuilding(buildingDeck);
                }
            }
        }
    }

    //draw harvest tile
    if(!usedDelivery){
        players[activePlayer]->DrawHarvestTile(harvestTileDeck);
    }
}

void replenish(){
    int missing = 5 - revealedBuildings->getSize();
    for(int i = 0; i < missing; i++){
        revealedBuildings->addBuilding(buildingDeck->drawBuilding());
    }
}

void end(){
    //calculate scores, declare winner


    string end = "Press enter to end the game";
    cout << end;
    cin >> end;
}

int main(){
    //initialize game
    initialize();

    //game loop
    for(round_num = 1; round_num < 11; round_num++){
        for(activePlayer = 0; activePlayer < playercount; activePlayer++){
            //set active resource tracker
            resourceTracker = players[activePlayer]->ResourceTracker();

            //place tile, generate resources
            placeTile();

            //each player place buildings
            placeBuildings();

            //draw buildings and harvest tile
            draw();

            //replenish face up pool
            replenish();

            //reset resource tracker and flags
            resourceTracker->assign(4, 0);
            usedDelivery = false;
        }
    }

    //calculate scores, declare winner, end the game
    end();

    for(int i = 0; i < playercount; i++)
        delete players[i];
    delete gameBoard;
    delete buildingDeck;
    delete harvestTileDeck;
    delete revealedBuildings;
}