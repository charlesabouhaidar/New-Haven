#include "GameObservers.h"
#include <iostream>
using std::cout;
void Subject::attach(Observer *o){
    obs.push_back(o);
}

void Subject::detach(Observer *o){
    obs.erase(std::remove(obs.begin(), obs.end(), o), obs.end());
}


/*
 *another way to implement the subject class is to have 2 concrete subjects
 *that are the turn subject and the game statistics subject to be in line with
 *assignment description for Nora
 *(one challenge is that this update relies on updates for both objects that are
 *in the same function *reset*)
 */ 
Subject::Subject(int i) : state(i){};

void Subject::setState(int i) {
    state = i;
}

void Subject::getState() {
    return state;
}

void Subject::notifyAllObservers() {
    for (auto o : obs) {
        o->update();
    }
}

virtual void Observer::update() = 0;

/*
 * Game State Observer
 */ 
// GameStateObserver::GameStateObserver(Subject *subject){
//   this->subject = subject;
// }
// /*
//  *line 31 (round and active player)
//  */ 

// @Override
// virtual void GameStateObserver::update(){
// 	/*
// 	 * update code here
// 	 */
// 	cout << "Game state observer updated...";
// }

/*
 * Place tile observer
 */ 
PlaceTileObserver::PlaceTileObserver(Subject *subject){
	this->subject = subject;
}
/*
 * line 177 on github
 * line 191 (harvest tile or delivery tile) increments resource tracker
 */ 
@Override
virtual void PlaceTileObserver::update(){
/*
 * update code here
 */
 cout << "Place tile observer updated... notify game state observer"
}
/*
 * Place building observer
 * 
 */ 
PlaceBuildingObserver::PlaceBuildingObserver(Subject *subject){
  this->subject = subject;
}

/*
 * line 246 on github
 * line 286 on github
 * line 217 on github (resource tracker decrements based on delivery tile) NOTE *FIX DELIVERY TILE IMPLEMENTATION THAT DIDN'T WORK DURING DEMO BUT WORKED ON ALEX'S COMPUTER* 
 * line 235 on github (resource tracker decrements based on normal tile)
 */ 

@Override
virtual void PlaceBuildingObserver::update(){
/*
 * update code here
 */
 cout << "Place building observer updated... notify game state observer"
}
/*
 * Draw observer
 */ 
   
DrawObserver::DrawObserver(Subject *subject){
  this->subject = subject;
}
/*
 * line 305 on github (displays updated gamestate)
 * !!!for the next 3 updates, check which one passes to then call the observer!!!
 * line 318 on github (draw building from pool of buildings that are shared)
 * line 339 on github (draw building from pool of revealed buildings) which updates your hand and the deck
 * line 343 on github(draw building from the deck)
 * line 351 on github (draw harvest tile)
 */ 

@Override
virtual void DrawObserver::update(){
/*
 * update code here
 */
 cout << "Draw observer updated... notify game state observer"
}

/*
 * Reset observer
 */ 
ResetObserver::ResetObserver(Subject *subject){
  this->subject = subject;
}

/*
 *line 360 on github (revealed buildings)
 *line 364 on github
 *
 */ 
@Override
virtual void ResetObserver::update(){
/*
 * update code here
 * !!!implement update of active player and round number in RESET FUNCTION!!!
 */
 cout << "Reset observer updated... notify game state observer"
}

/*
 * Score number colonist
 * Have to modify it to calculate score in the round loop at each iteration of the loop
 */ 
ComputeScoreObserver::ComputeScoreObserver(Subject *subject){
  this->subject = subject;
}

@Override
virtual void ComputeScoreObserver::update(){
/*
 * update code here
 */
 cout << "Computer score observer updated... notify game state observer"
}
