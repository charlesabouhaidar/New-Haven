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

void Player::PlaceHarvestTile(Tile tile, int location, int orientation) {
    //validate placement or UI side?
    hand->exchange(tile, location, orientation);
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
    //hand->getBuilding(); remove building from hand
    //check valid placement of building on board? done on UI side?
    //update village if valid and place building
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

ResourceGatherer::ResourceGatherer() {}//needed?

int* ResourceGatherer::CollectResources(int newTileLocation) {
    //...
}

ScoreCounter::ScoreCounter() {}//needed?

int ScoreCounter::CalculateScore() {
    //...
}