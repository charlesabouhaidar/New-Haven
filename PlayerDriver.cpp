#include "Player.h"
#include "GBMap.h"
#include <iostream>

using std::cout;

int main(){
    cout << "Player Tests\n";
    Player* p1 = new Player();
    cout << *(p1->playerID) << "\n";

    cout << "Facilities Tests\n";
    GBMap* gbMap = new GBMap(4);
}