//Driver for parts 1,2
#include "GameObservers.h"
#include <iostream>

using std::cout;
using std::cin;

int main(){
    Game* game = new Game();
    TurnObserver* turnObserver = new TurnObserver(game);
    StatsObserver* statsObserver = new StatsObserver(game);

    //initialize game
    game->initialize();

    //game loop
    while (!game->gameDone()) {
        //place tile, generate resources
        game->placeTilePhase();

        //each player place buildings
        game->placeBuildingsPhase();

        //draw buildings and harvest tile
        game->drawPhase();

        //set game for next turn
        game->nextTurn();

        //option to skip to game end for testing
        string skip = "";
        while (skip != "Y" && skip != "N") {
            cout << "Skip to game end (Y/N)?";
            cin >> skip;
        }
        if(skip == "Y"){
            *(game->activePlayer) = 0;
            *(game->handPlayer) = 0;
            *(game->round_num) = 11;
        }
    }

    //calculate scores, declare winner, end the game
    game->ComputeScore();

    string end = "Enter anything to end the game";
    cout << end;
    cin >> end;

    delete game;
    delete turnObserver;
    delete statsObserver;
    return 0;
}