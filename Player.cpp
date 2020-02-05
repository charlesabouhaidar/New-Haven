#include "Player.h"

Player::Player(string villageName) {
    village = new VGMap(villageName);
    hand = new Hand();
    resourceTracker = {0,0,0,0};
    resourceGatherer = new ResourceGatherer();
    scoreCounter = new ScoreCounter();
}

Player::~Player() {
    delete village;
    delete hand;
    delete[] resourceTracker;
    delete resourceGatherer;
    delete scoreCounter;
}

void Player::PlaceHarvestTile(GBMap board, Tile tile, int location, int orientation) {
    //Check if location is unoccupied
    hand->exchange(board, tile, location, orientation);
    CalculateResources(location);
}

void Player::DrawBuilding(Deck buildingDeck) {
    hand->getBuildings()->push_back(buildingDeck->draw());
}

void Player::DrawHarvestTile(Deck tileDeck) {
    hand->getTiles()->push_back(buildingDeck->draw());
}

int* Player::ResourceTracker() {
    return resourceTracker;
}

void Player::BuildVillage(Building building, int location, bool flipped) {
    //check valid placement of building on board
    //update village if valid and place building
    //hand->getBuilding();? remove building from hand
}

void Player::CalculateResources(int newTileLocation) {
    resourceTracker = resourceGatherer->CollectResources(newTileLocation);
}

VGMap Player::getVillage() {
    return village;
}

Hand Player::getHand() {
    return hand;
}

int* ResourceGatherer::CollectResources(GBMap board, int newTileLocation) {
    //...
}

int ScoreCounter::CalculateScore(VGMap village) {
    //...
}