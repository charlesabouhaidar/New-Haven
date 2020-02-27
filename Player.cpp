#include "Player.h"

using std::string;
using std::vector;

vector<int>* ResourceGatherer::CollectResources(GBMap* board, int newTileLocation) {
    string position = to_string(newTileLocation);
    vector<int>* resources = new vector<int>;
    resources->assign(4, 0);
//need a copy of board****
    int data = board->getTileData(position);

    resources->at(data/10%10-1)++;
    resources->at(data/100%10-1)++;
    resources->at(data/1000%10-1)++;
    resources->at(data/10000%10-1)++;
    board->setTileData(position, 55550);

    resources->at(data/10000%10-1) += collect(board, board->getNorth(position), 2, data/10000%10);
    resources->at(data/10000%10-1) += collect(board, board->getWest(position), 1, data/10000%10);

    resources->at(data/1000%10-1) += collect(board, board->getNorth(position), 3, data/1000%10);
    resources->at(data/1000%10-1) += collect(board, board->getEast(position), 0, data/1000%10);

    resources->at(data/100%10-1) += collect(board, board->getWest(position), 3, data/100%10);
    resources->at(data/100%10-1) += collect(board, board->getSouth(position), 0, data/100%10);

    resources->at(data/10%10-1) += collect(board, board->getSouth(position), 1, data/10%10);
    resources->at(data/10%10-1) += collect(board, board->getEast(position), 2, data/10%10);

    return resources;
}

int ResourceGatherer::collect(GBMap* board, string position, int corner, int resource){
    if(!position.empty()) {
        int data = board->getTileData(position);
        if (corner == 0 && data/10000%10 == resource) {
            string dataStr = to_string(data);
            dataStr[0] = '5';
            board->setTileData(position, stod(dataStr));
            return 1 + collect(board, board->getWest(position), 1, resource)
                     + collect(board, board->getNorth(position), 2, resource)
                     + collect(board, position, 1, resource)
                     + collect(board, position, 2, resource);
        } else if (corner == 1 && data/1000%10 == resource) {
            string dataStr = to_string(data);
            dataStr[1] = '5';
            board->setTileData(position, stod(dataStr));
            return 1 + collect(board, board->getNorth(position), 3, resource)
                   + collect(board, board->getEast(position), 0, resource)
                   + collect(board, position, 3, resource)
                   + collect(board, position, 0, resource);
        } else if (corner == 2 && data/100%10 == resource) {
            string dataStr = to_string(data);
            dataStr[2] = '5';
            board->setTileData(position, stod(dataStr));
            return 1 + collect(board, board->getSouth(position), 0, resource)
                   + collect(board, board->getWest(position), 3, resource)
                   + collect(board, position, 0, resource)
                   + collect(board, position, 3, resource);
        } else if (corner == 3 && data/10%10 == resource) {
            string dataStr = to_string(data);
            dataStr[3] = '5';
            board->setTileData(position, stod(dataStr));
            return 1 + collect(board, board->getEast(position), 2, resource)
                   + collect(board, board->getSouth(position), 1, resource)
                   + collect(board, position, 2, resource)
                   + collect(board, position, 1, resource);
        }
    }
    return 0;
}

int ScoreCounter::CalculateScore(VGMap* village) {
    //calculate based on rows, double if none flipped
    //calculate based on columns, double if none flipped
    //sum and return total
    return 0;
}

Player::Player(){
    int id = 0;
    playerID = &id;
    village = new VGMap();
    hand = new Hand();
    resourceTracker = new vector<int>;
    resourceTracker->assign(4, 0);
    resourceGatherer = new ResourceGatherer();
    scoreCounter = new ScoreCounter();
}

Player::Player(int id, string villageName) {
    playerID = &id;
    village = new VGMap(villageName);
    hand = new Hand();
    resourceTracker = new vector<int>;
    resourceTracker->assign(4, 0);
    resourceGatherer = new ResourceGatherer();
    scoreCounter = new ScoreCounter();
}

Player::~Player() {
    delete playerID;
    delete village;
    delete hand;
    delete resourceTracker;
    delete resourceGatherer;
    delete scoreCounter;
}

bool Player::PlaceHarvestTile(GBMap* board, int tileIndex, int location, int orientation) {
    if(board->getTileData(to_string(location)) == 0) {
        hand->exchange(board, *playerID, tileIndex, to_string(location), orientation);
        CalculateResources(board, location);
        return true;
    }
    return false;
}

void Player::DrawBuilding(BuildingDeck buildingDeck) {
    //hand->getBuildings()->push_back(buildingDeck->drawBuilding());
}

void Player::DrawHarvestTile(HarvestTileDeck tileDeck) {
    //hand->getTiles()->push_back(tileDeck->drawHarvestTile());
}

vector<int>* Player::ResourceTracker() {
    return resourceTracker;
}

bool Player::BuildVillage(int buildingIndex, int location, bool flipped) {
    if(village->getTileData(to_string(location)) == 0) {
        Building* building = hand->getBuilding(buildingIndex);
        int* number = building->getNumber();
        string* color = building->getColor();
        int colorIndex = 0;
        if(*color == "Red")
            colorIndex = 1;
        else if(*color == "Gray")
            colorIndex = 2;
        else if(*color == "Green")
            colorIndex = 3;
        //check if position has valid number
        int row = location/5;
        if(flipped || *number == 6-row){
            //check if there are sufficient resource to place building
            if(resourceTracker->at(colorIndex) >= 6 - row) {
                //check if type is adjacent if placed
                if (!village->getFlags()->at(colorIndex)) {
                    village->getFlags()->at(colorIndex) = true;
                    hand->deleteBuilding(buildingIndex);
                    resourceTracker->at(colorIndex) -= (6-row);
                    double data = 0;
                    if(flipped)
                        data++;
                    data += row*10;
                    data += (colorIndex+1)*100;
                    village->setTileData(to_string(location), data);
                    return true;
                } else {
                    int adjacentData[4] = {0,0,0,0};
                    adjacentData[0] = village->getTileData(village->getEast(to_string(location)));
                    adjacentData[1] = village->getTileData(village->getWest(to_string(location)));
                    adjacentData[2] = village->getTileData(village->getNorth(to_string(location)));
                    adjacentData[3] = village->getTileData(village->getSouth(to_string(location)));
                    bool isAdj = false;
                    for(int i = 0; i > 4; i++){
                        if(adjacentData[i]/100%10 == colorIndex+1){
                            isAdj = true;
                        }
                    }
                    if(isAdj){
                        hand->deleteBuilding(buildingIndex);
                        resourceTracker->at(colorIndex) -= (6-row);
                        double data = 0;
                        if(flipped)
                            data++;
                        data += row*10;
                        data += (colorIndex+1)*100;
                        village->setTileData(to_string(location), data);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void Player::CalculateResources(GBMap* board, int newTileLocation) {
    resourceTracker = resourceGatherer->CollectResources(board, newTileLocation);
}

VGMap* Player::getVillage() {
    return village;
}

Hand* Player::getHand() {
    return hand;
}