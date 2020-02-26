#include "Player.h"

using std::string;
using std::vector;

vector<int>* ResourceGatherer::CollectResources(GBMap board, int newTileLocation) {
    string position = to_string(newTileLocation);
    vector<int>* resources = new vector<int>;
    resources->assign(4, 0);
//need a copy of board****
    int data = board.getTileData(position);

    resources->at(data/10%10-1)++;
    resources->at(data/100%10-1)++;
    resources->at(data/1000%10-1)++;
    resources->at(data/10000%10-1)++;
    board.setTileData(position, 55550);

    resources->at(data/10000%10-1) += collect(board, board.getNorth(position), 2, data/10000%10);
    resources->at(data/10000%10-1) += collect(board, board.getWest(position), 1, data/10000%10);

    resources->at(data/1000%10-1) += collect(board, board.getNorth(position), 3, data/1000%10);
    resources->at(data/1000%10-1) += collect(board, board.getEast(position), 0, data/1000%10);

    resources->at(data/100%10-1) += collect(board, board.getWest(position), 3, data/100%10);
    resources->at(data/100%10-1) += collect(board, board.getSouth(position), 0, data/100%10);

    resources->at(data/10%10-1) += collect(board, board.getSouth(position), 1, data/10%10);
    resources->at(data/10%10-1) += collect(board, board.getEast(position), 2, data/10%10);

    return resources;
}

int ResourceGatherer::collect(GBMap board, string position, int corner, int resource){
    if(!position.empty()) {
        int data = board.getTileData(position);
        if (corner == 0 && data/10000%10 == resource) {
            string dataStr = to_string(data);
            dataStr[0] = '5';
            board.setTileData(position, stod(dataStr));
            return 1 + collect(board, board.getWest(position), 1, resource)
                     + collect(board, board.getNorth(position), 2, resource)
                     + collect(board, position, 1, resource)
                     + collect(board, position, 2, resource);
        } else if (corner == 1 && data/1000%10 == resource) {
            string dataStr = to_string(data);
            dataStr[1] = '5';
            board.setTileData(position, stod(dataStr));
            return 1 + collect(board, board.getNorth(position), 3, resource)
                   + collect(board, board.getEast(position), 0, resource)
                   + collect(board, position, 3, resource)
                   + collect(board, position, 0, resource);
        } else if (corner == 2 && data/100%10 == resource) {
            string dataStr = to_string(data);
            dataStr[2] = '5';
            board.setTileData(position, stod(dataStr));
            return 1 + collect(board, board.getSouth(position), 0, resource)
                   + collect(board, board.getWest(position), 3, resource)
                   + collect(board, position, 0, resource)
                   + collect(board, position, 3, resource);
        } else if (corner == 3 && data/10%10 == resource) {
            string dataStr = to_string(data);
            dataStr[3] = '5';
            board.setTileData(position, stod(dataStr));
            return 1 + collect(board, board.getEast(position), 2, resource)
                   + collect(board, board.getSouth(position), 1, resource)
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
    //hand = new Hand();
    resourceTracker = new vector<int>;
    resourceTracker->assign(4, 0);
    resourceGatherer = new ResourceGatherer();
    scoreCounter = new ScoreCounter();
}

Player::Player(int id, string villageName) {
    playerID = &id;
    village = new VGMap(villageName);
    //hand = new Hand();
    resourceTracker = new vector<int>;
    resourceTracker->assign(4, 0);
    resourceGatherer = new ResourceGatherer();
    scoreCounter = new ScoreCounter();
}

Player::~Player() {
    delete playerID;
    delete village;
    //delete hand;
    delete resourceTracker;
    delete resourceGatherer;
    delete scoreCounter;
}

void Player::PlaceHarvestTile(GBMap board, HarvestTile tile, int location, int orientation) {
    if(board.getTileData(to_string(location)) == 0) {
        //hand->exchange(board, tile, location, orientation, playerID);
        CalculateResources(board, location);
    }
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

void Player::BuildVillage(Building building, int location, bool flipped) {
    if(village->getTileData(to_string(location)) == 0) {
        //ensure type adjacency, check number value if not flipped
        //hand->getBuilding();? remove building from hand
        //update village if valid and place building, function in VGMap?
    }
}

void Player::CalculateResources(GBMap board, int newTileLocation) {
    resourceTracker = resourceGatherer->CollectResources(board, newTileLocation);
}

VGMap* Player::getVillage() {
    return village;
}

//Hand Player::getHand() {
//    return hand;
//}