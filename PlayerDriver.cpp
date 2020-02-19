#include "Player.h"
#include "GBMap.h"

int main(){//friend
    GBMap* board = new GBMap();
    //create building deck
    //create tiles deck
    Player* p1 = new Player();
    Player* p2 = new Player(1, "Jamestown");
    Player* p3 = new Player(2, "Blueville");
    //test drawbuilding, display hand display deck size
    //test drawharvesttile, display hand display deck size
    //test placeharvesttile, display board and test resourcetracker, display tracker, display hand
    //test buildvillage, display village display hand

    //facilities tests
    //write tiles to board and buildings to village
    //p->resourceGatherer(board, 0); display board, display resourcetracker
    //test scorecalculator display village, display calculate score
}
