#include "GBMap.h"
#include "Player.h"
#include "Resources.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int round_num, activePlayer, playercount;
RevealedBuildings* revealedBuildings;
Player* players[4];
GBMap* gameBoard;

void display_gamestate(){
    cout << string(50, '\n');
    cout << "ROUND " << to_string(round_num) << "  PLAYER " << to_string(activePlayer+1) << "'S TURN\n";

    //get string data
    vector<string> gameBoardStrings = gameBoard->toStrings();
    vector<string> village[4];
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

int main(){
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
    BuildingDeck* buildings = new BuildingDeck();
    HarvestTileDeck* harvestTiles = new HarvestTileDeck();

    //set face up buildings pool
    revealedBuildings = new RevealedBuildings();
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

    for(round_num = 1; round_num < 11; round_num++){
        for(activePlayer = 0; activePlayer < playercount; activePlayer++){
            //set active resource tracker
            vector<int>* resourceTracker = players[activePlayer]->ResourceTracker();

            //place tile, generate resources
            bool usedDelivery = false;


            //place buildings, next players


            //draw buildings
            bool fromPool = false;
            for(int i=0; i<4; i++){
                if(resourceTracker->at(i) == 0){
                    display_gamestate();
                    cout << *players[activePlayer]->getHand();
                    if(!fromPool){
                        string selectedstr = "";
                        int selected = 5;
                        while(selected >= revealedBuildings->getSize()) {
                            cout << "Draw Building:";
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
                        cout << "0:Draw from revealed   1:Draw from deck\nDraw Location:";
                        while(!(option == "0" || option == "1")){
                            cin >> option;
                        }
                        if(option == "0"){
                            string selectedstr;
                            int selected = 5;
                            while(selected >= revealedBuildings->getSize()) {
                                cout << "Draw Building:";
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
                            players[activePlayer]->DrawBuilding(buildings);
                        }
                    }
                }
            }

            //draw harvest tile
            if(!usedDelivery){
                players[activePlayer]->DrawHarvestTile(harvestTiles);
            }

            //replenish face up pool
            int missing = 5 - revealedBuildings->getSize();
            for(int i = 0; i < missing; i++){
                revealedBuildings->addBuilding(buildings->drawBuilding());
            }

            //reset resource tracker
            resourceTracker->assign(4, 0);
        }
    }

    for(int i = 0; i < playercount; i++)
        delete players[i];
    delete gameBoard;
    delete buildings;
    delete harvestTiles;
    delete revealedBuildings;
}