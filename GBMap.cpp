//
// Created by Charles Abou Haidar on 2020-01-22.
//

#include <vector>
#include "GBMap.h"
#include "Cpp-Graph-Library-master/Graph.h"
#include "Cpp-Graph-Library-master/Node.h"

using namespace std;

void BoardGame::createBoardGame(int numOfPlayers) {
    Graph board = new Graph(false); //non directed graph
    vector<string> reachableNodes;
    int nodeName;
    switch(numOfPlayers){
        case 2:
            for(int i = 0; i < 25; i++){ //create a graph with 25 nodes
                board.addNode(to_string(i));
            }
            for(int i = 0; i < 25; i++){
                int fromNode = i;
                int toSouthNode = fromNode + 5;
                int toEastNode = fromNode + 1;
                int toWestNode = fromNode - 1;
                int toNorthNode = fromNode - 5;
                //the first 7 if/if else statements are special cases where nodes aren't connected to 4 nodes next to them
                if(fromNode == 0){ //node 0 doesn't have a north or west node since it's in the top left corner
                    board.addEdge(to_string(fromNode), to_string(toSouthNode));
                    board.addEdge(to_string(fromNode), to_string(toEastNode));
                }
                else if(fromNode == 4){ //node 4 doesn't have a north or east node since it's in the top left corner
                    board.addEdge(to_string(fromNode), to_string(toSouthNode));
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                }
                else if(fromNode == 20){ //node 20 doesn't have a south node or a west node since it's in the bottom left corner
                    board.addEdge(to_string(fromNode), to_string(toNorthNode));
                    board.addEdge(to_string(fromNode), to_string(toEastNode));
                }
                else if(fromNode == 24){ //node 24 doesn't have a south or east node since it's in the bottom right corner
                    board.addEdge(to_string(fromNode), to_string(toNorthNode));
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                }
                else if(fromNode == 1 || fromNode == 2 || fromNode == 3){ //no north node (top of board game)
                    board.addEdge(to_string(fromNode), to_string(toEastNode));
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                    board.addEdge(to_string(fromNode), to_string(toSouthNode));
                }
                else if(fromNode == 21 || fromNode == 22 || fromNode == 23){ //no south node (bottom of board game)
                    board.addEdge(to_string(fromNode), to_string(toEastNode));
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                    board.addEdge(to_string(fromNode), to_string(toNorthNode));
                }
               else if(fromNode % 5 == 0){ //no west node (right of board game)
                   board.addEdge(to_string(fromNode), to_string(toNorthNode));
                   board.addEdge(to_string(fromNode), to_string(toEastNode));
                   board.addEdge(to_string(fromNode), to_string(toSouthNode));
               }
                else if(fromNode % 5 == 4){ //no east node (left of board game)
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                    board.addEdge(to_string(fromNode), to_string(toNorthNode));
                    board.addEdge(to_string(fromNode), to_string(toSouthNode));
                }
               else{
                   board.addEdge(to_string(fromNode), to_string(toNorthNode));
                   board.addEdge(to_string(fromNode), to_string(toSouthNode));
                   board.addEdge(to_string(fromNode), to_string(toEastNode));
                   board.addEdge(to_string(fromNode), to_string(toWestNode));
               }
            }
            cout << "Enter a node to see its immediate neighbors: " << endl;
            cin >> nodeName;
            reachableNodes = board.neighborNames(to_string(nodeName));
            for(int i = 0; i < reachableNodes.size(); i++){
                cout << reachableNodes.at(i) << endl;
            }
            break;

        case 3:
            for(int i = 0; i < 35; i++){
                board.addNode(i, to_string(i));
            }
            for(int i = 0; i < 35; i++){
                int fromNode = i;
                int toSouthNode = fromNode + 5;
                int toEastNode = fromNode + 1;
                int toWestNode = fromNode - 1;
                int toNorthNode = fromNode - 5;
                if(fromNode == 0){
                    board.addEdge(to_string(fromNode), to_string(toSouthNode));
                    board.addEdge(to_string(fromNode), to_string(toEastNode));
                }
                else if(fromNode == 4){
                    board.addEdge(to_string(fromNode), to_string(toSouthNode));
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                }
                else if(fromNode == 30){
                    board.addEdge(to_string(fromNode), to_string(toNorthNode));
                    board.addEdge(to_string(fromNode), to_string(toEastNode));
                }
                else if(fromNode == 34){
                    board.addEdge(to_string(fromNode), to_string(toNorthNode));
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                }
                else if(fromNode == 1 || fromNode == 2 || fromNode == 3){
                    board.addEdge(to_string(fromNode), to_string(toEastNode));
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                    board.addEdge(to_string(fromNode), to_string(toSouthNode));
                }
                else if(fromNode == 31 || fromNode == 32 || fromNode == 33){
                    board.addEdge(to_string(fromNode), to_string(toEastNode));
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                    board.addEdge(to_string(fromNode), to_string(toNorthNode));
                }
                else if(fromNode % 5 == 0){
                    board.addEdge(to_string(fromNode), to_string(toNorthNode));
                    board.addEdge(to_string(fromNode), to_string(toEastNode));
                    board.addEdge(to_string(fromNode), to_string(toSouthNode));
                }
                else if(fromNode % 5 == 4){
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                    board.addEdge(to_string(fromNode), to_string(toNorthNode));
                    board.addEdge(to_string(fromNode), to_string(toSouthNode));
                }
                else{
                    board.addEdge(to_string(fromNode), to_string(toNorthNode));
                    board.addEdge(to_string(fromNode), to_string(toSouthNode));
                    board.addEdge(to_string(fromNode), to_string(toEastNode));
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                }
            }
            cout << "Enter a node to see its immediate neighbors: " << endl;
            cin >> nodeName;
            reachableNodes = board.neighborNames(to_string(nodeName));
            for(int i = 0; i < reachableNodes.size(); i++){
                cout << reachableNodes.at(i) << endl;
            }
            break;

        case 4:
            for(int i = 0; i < 45; i++){
                board.addNode(i, to_string(i));
            }
            for(int i = 0; i < 5; i++){
                int fromNode = i;
                int toEastNode = fromNode + 1;
                int toSouthNode = fromNode + 6;
                int toWestNode = fromNode - 1;
                board.addEdge(to_string(fromNode), to_string(toSouthNode)); //all nodes are connected to a south node
                if(fromNode == 4){
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                }
                else{
                    board.addEdge(to_string(fromNode), to_string(toEastNode)); //connected to east node
                }
            }
            for(int i = 5; i <= 32; i++){
                int fromNode = i;
                int toEastNode = fromNode + 1;
                int toSouthNode = fromNode + 7;
                int toWestNode = fromNode - 1;
                int toNorthNode = fromNode - 7;
                board.addEdge(to_string(fromNode), to_string(toSouthNode)); //all edges are connected to a south node
                if(fromNode == 5){
                    board.addEdge(to_string(fromNode), to_string(toEastNode));
                }
                else if(fromNode == 11){ //node 11 which doesn't have a north node
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                }

                else if(fromNode % 7 == 5){ //left side of the board that don't have a west node
                    board.addEdge(to_string(fromNode), to_string(toNorthNode));
                    board.addEdge(to_string(fromNode), to_string(toEastNode));
                }
                else if(fromNode % 7 == 4){ //right nodes of the board which are not connected to east nodes
                    board.addEdge(to_string(fromNode), to_string(toNorthNode));
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                }
                else { //nodes that are connected to 4 nodes (including south)
                    board.addEdge(to_string(fromNode), to_string(toNorthNode));
                    board.addEdge(to_string(fromNode), to_string(toEastNode));
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                }
            }
            for(int i = 33; i <= 39; i++){
                int fromNode = i;
                int toEastNode = fromNode + 1;
                int toSouthNode = fromNode + 6;
                int toNorthNode = fromNode - 7;
                int toWestNode = fromNode - 1;
                board.addEdge(to_string(fromNode), to_string(toNorthNode));
                if(fromNode == 33){
                    board.addEdge(to_string(fromNode), to_string(toEastNode));
                }
                else if(fromNode == 39){
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                }
                else{
                    board.addEdge(to_string(fromNode), to_string(toSouthNode));
                    board.addEdge(to_string(fromNode), to_string(toEastNode));
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                }
            }
            for(int i = 40; i <= 44; i++){
                int fromNode = i;
                int toEastNode = fromNode + 1;
                int toNorthNode = fromNode - 7;
                int toWestNode = fromNode - 1;
                board.addEdge(to_string(fromNode), to_string(toNorthNode));
                if(fromNode == 40){
                    board.addEdge(to_string(fromNode), to_string(toEastNode));
                }
                else if(fromNode == 44){
                    board.addEdge(to_string(fromNode), to_string(toWestNode));
                }
                else{
                    board.addEdge(to_string(fromNode), to_string(toEastNode));
                }
            }
            cout << "Enter a node to see its immediate neighbors: " << endl;
            cin >> nodeName;
            reachableNodes = board.neighborNames(to_string(nodeName));
            for(int i = 0; i < reachableNodes.size(); i++){
                cout << reachableNodes.at(i) << endl;
            }
            break;

        default: break;
        
    }
}

int main(){
    int numOfPlayers;
    cout << "***********************************" << endl;
    cout << "* Welcome to New Haven Board Game *" << endl;
    cout << "***********************************" << endl;

    cout << "\nEnter the number of players for this session: ";
    cin >> numOfPlayers;
    BoardGame::createBoardGame(numOfPlayers);
    return 0;
}
