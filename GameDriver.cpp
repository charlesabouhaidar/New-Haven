#include "GBMap.h"
#include "Player.h"
#include "Resources.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int round_num, activePlayer, playercount, deliveryPos;
bool usedDelivery;
HarvestTile* deliveryTile;
RevealedBuildings* revealedBuildings;
Player* players[4];
GBMap* gameBoard;
BuildingDeck* buildingDeck;
HarvestTileDeck* harvestTileDeck;

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

bool valid_tile_pos(string pos){
    bool valid = false;
    if(playercount >= 2){
        if(pos == "0" || pos == "1" || pos == "2" || pos == "3" || pos == "4" || pos == "5" || pos == "6"
        || pos == "7" || pos == "8" || pos == "9" || pos == "10" || pos == "11" || pos == "12" || pos == "13"
        || pos == "14" || pos == "15" || pos == "16" || pos == "17" || pos == "18" || pos == "19" || pos == "20"
        || pos == "21" || pos == "22" || pos == "23" || pos == "24")
            valid = true;

    }
    if(playercount >= 3){
        if(pos == "25" || pos == "26" || pos == "27" || pos == "28" || pos == "29" || pos == "30" || pos == "31"
           || pos == "32" || pos == "33" || pos == "34")
            valid = true;
    }
    if(playercount == 4){
        if(pos == "35" || pos == "36" || pos == "37" || pos == "38" || pos == "39" || pos == "40" || pos == "41"
           || pos == "42" || pos == "43" || pos == "44")
            valid = true;
    }
    return valid;
}

bool valid_building_pos(string pos){
    return (pos == "0" || pos == "1" || pos == "2" || pos == "3" || pos == "4" || pos == "5" || pos == "6"
           || pos == "7" || pos == "8" || pos == "9" || pos == "10" || pos == "11" || pos == "12" || pos == "13"
           || pos == "14" || pos == "15" || pos == "16" || pos == "17" || pos == "18" || pos == "19" || pos == "20"
           || pos == "21" || pos == "22" || pos == "23" || pos == "24" || pos == "25" || pos == "26" || pos == "27"
           || pos == "28" || pos == "29");
}

bool is_number(string str)
{
    bool isNumber = true;
    for(int i=0; i < str.size(); i++) {
        if(str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5'
        && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9')
            isNumber = false;
    }
    return isNumber;
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

    deliveryTile = new HarvestTile();
    usedDelivery = false;
}

void placeTile(){
    display_gamestate();
    cout << "Player " << to_string(activePlayer+1) << "'s " <<*players[activePlayer]->getHand() << "\n";
    string tilestr = "";
    bool validTile = false;
    while(!validTile) {
        cout << "Select harvest tile to play:";
        cin >> tilestr;
        if(tilestr == "0" || tilestr == "1")
            validTile = true;
        else if(tilestr == "2" && players[activePlayer]->getHand()->hasDeliveryTile())
            validTile = true;
    }
    int tile = stoi(tilestr);
    //using delivery tile
    if(tile == 2){
        usedDelivery = true;
        string data[4] = {"","","",""};
        string mes[4] = {"top left", "top right", "bottom left", "bottom right"};
        HarvestTile* placedTile = new HarvestTile();
        *deliveryTile = players[activePlayer]->getHand()->useDeliveryTile();
        cout << "Select tile data (Wheat, Timber, Rock, Sheep)\n";
        for(int i=0; i < 4; i++) {
            while (data[i] != "Wheat" && data[i] != "Timber" && data[i] != "Rock" && data[i] != "Sheep") {
                cout << "Select " << mes[i] << " data:";
                cin >> data[i];
            }
        }
        placedTile->setTopLeftResource(&data[0]);
        placedTile->setTopRightResource(&data[1]);
        placedTile->setBottomLeftResource(&data[2]);
        placedTile->setBottomRightResource(&data[3]);
        players[activePlayer]->getHand()->addHarvestTile(*placedTile);

        string posstr = "";
        bool validPos = false;
        while(!validPos){
            cout << "Select position for tile:";
            cin >> posstr;
            if(valid_tile_pos(posstr)) {
                deliveryPos = stoi(posstr);
                validPos = players[activePlayer]->PlaceHarvestTile(gameBoard, 2, deliveryPos, 0);
            }
        }
        delete placedTile;
    }
    //using normal tile
    else{
        string rotstring = "";
        while(rotstring != "0" && rotstring != "1" && rotstring != "2" && rotstring != "3") {
            cout << "Select rotation (0:none 1:90cw 2:180cw 3:270cw):";
            cin >> rotstring;
        }
        string posstr = "";
        bool validPos = false;
        while(!validPos){
            cout << "Select position for tile:";
            cin >> posstr;
            if(valid_tile_pos(posstr))
                validPos = players[activePlayer]->PlaceHarvestTile(gameBoard, tile, stoi(posstr), stoi(rotstring));
        }
    }
}

void placeBuildings(){
    for(int i=0; i < playercount; i++){
        bool placing = true;
        while(placing) {
            if (players[(activePlayer + i) % playercount]->getHand()->getNumOfBuildings() > 0) {
                display_gamestate();
                cout << "Player " << to_string((activePlayer+i)%playercount+1) << "'s "
                     << *players[(activePlayer+i)%playercount]->getHand() << "\n";

                string option = "";
                while (option != "0" && option != "1") {
                    cout << "Place building (0) or Skip (1):";
                    cin >> option;
                }
                if (option == "0") {

                    string buildingStr = "";
                    int building = 0;
                    bool validBuilding = false;
                    while (!validBuilding) {
                        cout << "Select building to place:";
                        cin >> buildingStr;
                        if (is_number(buildingStr)) {
                            building = stoi(buildingStr);
                            if (building >= 0 && building < players[(activePlayer + i) % playercount]->getHand()->getNumOfBuildings()) {
                                validBuilding = true;
                            }
                        }
                    }

                    string flippedStr = "";
                    bool flipped = false;
                    while(flippedStr != "0" && flippedStr != "1"){
                        cout << "Place building face up (0) or flipped (1):";
                        cin >> flippedStr;
                    }
                    if(flippedStr == "1")
                        flipped = true;

                    string buildPos = "";
                    while(!valid_building_pos(buildPos)){
                        cout << "Select position to build:";
                        cin >> buildPos;
                    }

                    players[(activePlayer + i) % playercount]->BuildVillage(building, stoi(buildPos), flipped, players[activePlayer]->ResourceTracker());
                }
                else {
                    placing = false;
                }
            }
            else{
                placing = false;
            }
        }
    }
}

void draw(){
    //draw buildings
    bool fromPool = false;
    for(int i=0; i<4; i++){
        if(players[activePlayer]->ResourceTracker()->at(i) == 0){
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

void reset(){
    //replenish face up buildings
    int missing = 5 - revealedBuildings->getSize();
    for(int i = 0; i < missing; i++){
        revealedBuildings->addBuilding(buildingDeck->drawBuilding());
    }

    //flip used delivery tile
    if(usedDelivery) {
        players[activePlayer]->getHand()->addHarvestTile(*deliveryTile);
        players[activePlayer]->getHand()->exchange(gameBoard, activePlayer + 1, 2, to_string(deliveryPos), 0);
    }

    //reset
    players[activePlayer]->ResourceTracker()->assign(4, 0);
    usedDelivery = false;
}

void ComputeScore(){
    //get scores and counts
    int scores[playercount];
    int buildingCount[playercount];
    int handBuildings[playercount];
    for(int i=0; i < playercount; i++){
        scores[i] = players[i]->getScoreCounter()->CalculateScore(players[i]->getVillage());
        buildingCount[i] = players[i]->getVillage()->getBuildingCount();
        handBuildings[i] = players[i]->getHand()->getNumOfBuildings();
    }
    //score comparison
    vector<int> topScorePlayers;
    int highestScore = 0;
    for(int i=0; i < playercount; i++){
        if(scores[i] == highestScore) {
            topScorePlayers.push_back(i);
        }
        else if(scores[i] > highestScore){
            topScorePlayers.clear();
            topScorePlayers.push_back(i);
            highestScore = scores[i];
        }
    }
    //board building count comparison
    vector<int> topBuildingPlayers;
    int highestCount = 0;
    for(int i=0; i < topScorePlayers.size(); i++){
        if(buildingCount[topScorePlayers.at(i)] == highestCount) {
            topBuildingPlayers.push_back(topScorePlayers.at(i));
        }
        else if(buildingCount[topScorePlayers.at(i)] > highestCount){
            topBuildingPlayers.clear();
            topBuildingPlayers.push_back(topScorePlayers.at(i));
            highestCount = buildingCount[topScorePlayers.at(i)];
        }
    }
    //hand building count comparison
    vector<int> topHandPlayers;
    int smallestHand = INT_MAX;
    for(int i=0; i < topBuildingPlayers.size(); i++){
        if(handBuildings[topBuildingPlayers.at(i)] == smallestHand) {
            topHandPlayers.push_back(topBuildingPlayers.at(i));
        }
        else if(handBuildings[topBuildingPlayers.at(i)] < smallestHand){
            topHandPlayers.clear();
            topHandPlayers.push_back(topBuildingPlayers.at(i));
            smallestHand = handBuildings[topBuildingPlayers.at(i)];
        }
    }

    //declare winner(s)
    cout << "PLAYER(S) " << topHandPlayers.at(0)+1;
    for(int i = 1; i < topHandPlayers.size(); i++){
        cout << " & " << topHandPlayers.at(i)+1;
    }
    cout << " WIN!\n\n";

    string end = "Press enter to end the game";
    cout << end;
    cin >> end;

    for(int i = 0; i < playercount; i++)
        delete players[i];
    delete deliveryTile;
    delete gameBoard;
    delete buildingDeck;
    delete harvestTileDeck;
    delete revealedBuildings;
}

int main(){
    //initialize game
    initialize();

    //game loop
    for(round_num = 1; round_num < 11; round_num++){
        for(activePlayer = 0; activePlayer < playercount; activePlayer++){
            //place tile, generate resources
            placeTile();

            //each player place buildings
            placeBuildings();

            //draw buildings and harvest tile
            draw();

            //replenish face up pool, reset vars and flip delivery if used
            reset();
        }
    }

    //calculate scores, declare winner, end the game
    ComputeScore();

    return 0;
}