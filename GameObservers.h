#ifndef GAME_GAMEOBSERVERS_H
#define GAME_GAMEOBSERVERS_H

#include <list>
#include "GBMap.h"
#include "Player.h"
#include "Resources.h"
#include "GBMapLoader.h"

using std::list;

//Observer base class
class Observer{
public:
    ~Observer();
    virtual void Update() = 0;
protected:
    Observer();
};

//Subject base class
class Subject{
public:
    virtual void Attach(Observer* o);
    virtual void Detach(Observer* o);
    virtual void Notify();
    Subject();
    ~Subject();
private:
    list<Observer*> *_observers;
};

/**
 * Concrete subject for the game
 * Performs all game operations
 */
class Game : public Subject{
    friend int main();
private:
    int* round_num;
    int* activePlayer;
    int* playercount;
    int* deliveryPos;
    int* handPlayer;
    string* phase;
    bool* usedDelivery;
    HarvestTile* deliveryTile;
    RevealedBuildings* revealedBuildings;
    Player** players;
    GBMap* gameBoard;
    BuildingDeck* buildingDeck;
    HarvestTileDeck* harvestTileDeck;
    string* winStr;
    bool valid_tile_pos(string pos);
    bool valid_building_pos(string pos);
    bool is_number(string str);
public:
    Game();                                     //Constructor
    ~Game();                                    //Destructor
    void initialize();                          //sets up the game
    void placeTilePhase();                      //place tile and generate resources
    void placeBuildingsPhase();                 //each player place buildings
    void drawPhase();                           //draw buildings and harvest tile
    void nextTurn();                            //set game for next turn
    void ComputeScore();                        //calculate scores, set winner, end the game
    bool gameDone();                            //returns if the game is done or not
    int getRound();                             //gets the current game round
    int getActivePlayer();                      //gets which player's turn it currently is
    int getPlayerCount();                       //gets the number of players in the game
    vector<string> getGameBoardStrs();          //gets the game board as a vector of strings
    vector<vector<string>> getVillagesStrs();   //gets all the villages each as a vector of strings
    string getRevealedBuildingsStr();           //gets the pool of revealed buildings as a string
    vector<string> getVillageNames();           //gets the village names
    string getTrackerStr();                     //gets the currently active resource tracker as a string
    int getHandPlayer();                        //gets the relevant player for the current game action
    void printCurrentHand();                    //prints the hand of the relevant player for the current game action
    string getPhase();                          //gets the current game phase
    vector<string> getStatsStrs();              //gets the win condition statistics for each player as strings
    string getWinnerStr();                      //gets the winner declaration
};

/**
 * Concrete observer for part 1
 * View for relevant turn playing information
 */
class TurnObserver : public Observer{
public:
    TurnObserver();
    TurnObserver(Game* g);
    ~TurnObserver();
    void Update();
    void display();
private:
    Game* _subject;
};

/**
 * Concrete observer for part 2
 * View for win condition statistics
 */
class StatsObserver : public Observer{
public:
    StatsObserver();
    StatsObserver(Game* g);
    ~StatsObserver();
    void Update();
    void display();
private:
    Game* _subject;
};

#endif //GAME_GAMEOBSERVERS_H
