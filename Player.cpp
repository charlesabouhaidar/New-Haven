#include "Player.h"
using std::string;
using std::vector;

vector<int>* ResourceGatherer::CollectResources(GBMap board, int newTileLocation) {
    //graph traversal
    //nested behavior in tiles
    //mark passed over resources
    //save values in array and return at end
    vector<int>* resources;
    return resources;
}

//int ScoreCounter::CalculateScore(VGMap village) {
//    //calculate based on rows, double if none flipped
//    //calculate based on columns, double if none flipped
//    //sum and return total
//}

Player::Player(){
    int id = 0;
    playerID = &id;
    //village = new VGMap("Unspecified");
    //hand = new Hand();
    resourceGatherer = new ResourceGatherer();
    scoreCounter = new ScoreCounter();
}

Player::Player(int id, string villageName) {
    playerID = &id;
    //village = new VGMap(villageName);
    //hand = new Hand();
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
    //Check if location is unoccupied if(board->getTile(location)...);
    //hand->exchange(board, tile, location, orientation, playerID);
    CalculateResources(board, location);
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
    //check valid placement of building on board, function in VGMap?
    //hand->getBuilding();? remove building from hand
    //update village if valid and place building, function in VGMap?
}

void Player::CalculateResources(GBMap board, int newTileLocation) {
//    resourceTracker =
    resourceGatherer->CollectResources(board, newTileLocation);
}

//VGMap Player::getVillage() {
//    return village;
//}

//Hand Player::getHand() {
//    return hand;
//}