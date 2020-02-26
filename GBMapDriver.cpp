//
// Created by Charles Abou Haidar on 2020-01-22.
//
#include "GBMap.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int players{0}, nodeNumber{0};
    vector<string> reachableNodes;
    cout << "***********************************" << endl;
    cout << "* Welcome to New Haven Board Game *" << endl;
    cout << "***********************************" << endl;
    cout << "\nEnter the number of players for this session: ";
    cin >> players;
    GBMap *game = new GBMap(players);
    Graph *board = game->getBoard();
    switch(players){
        case 2: {
            for (int i = 0; i < 25; i++) {
                cout << "Node " << i << " Value: " << board->getNodeValue(to_string(i)) << endl;
                cout << "East node: " << game->getEast(to_string(i)) << endl;
                cout << "West node: " << game->getWest(to_string(i)) << endl;
                cout << "North node: " << game->getNorth(to_string(i)) << endl;
                cout << "South node: " << game->getSouth(to_string(i)) << endl << endl;
            }
            cout << "Enter a node number to check it's value: " << endl;
            cin >> nodeNumber;
            try{
                cout << "Node number: " << nodeNumber << " Value: " << board->getNodeValue(to_string(nodeNumber));
            }
            catch(exception& e) {
                perror("Node out of bounds/doesn't exist!" );
                exit(EXIT_FAILURE);
            }
            break;
        }

        case 3:{
            for(int j = 0; j < 35; j++){
                cout << "Node " << j << " Value: " << board->getNodeValue(to_string(j)) << endl;
                cout << "East node: " << game->getEast(to_string(j)) << endl;
                cout << "West node: " << game->getWest(to_string(j)) << endl;
                cout << "North node: " << game->getNorth(to_string(j)) << endl;
                cout << "South node: " << game->getSouth(to_string(j)) << endl << endl;
            }
            cout << "Enter a node number to check it's value: " << endl;
            cin >> nodeNumber;
            try{
                cout << "Node number: " << nodeNumber << " Value: " << board->getNodeValue(to_string(nodeNumber));
            }
            catch(exception& e) {
                perror("Node out of bounds/doesn't exist!" );
                exit(EXIT_FAILURE);
            }
            break;
        }

        case 4:{
            for(int k = 0; k < 45; k++){
                cout << "Node " << k << " Value: " << board->getNodeValue(to_string(k)) << endl;
                cout << "East node: " << game->getEast(to_string(k)) << endl;
                cout << "West node: " << game->getWest(to_string(k)) << endl;
                cout << "North node: " << game->getNorth(to_string(k)) << endl;
                cout << "South node: " << game->getSouth(to_string(k)) << endl << endl;
            }
            cout << "Enter a node number to check it's value: " << endl;
            cin >> nodeNumber;
            try{
                cout << "Node number: " << nodeNumber << " Value: " << board->getNodeValue(to_string(nodeNumber));
                cout << "East node: " << game->getEast(to_string(nodeNumber)) << endl;
                cout << "West node: " << game->getWest(to_string(nodeNumber)) << endl;
                cout << "North node: " << game->getNorth(to_string(nodeNumber)) << endl;
                cout << "South node: " << game->getSouth(to_string(nodeNumber)) << endl << endl;
            }
            catch(exception& e) {
                perror("Node out of bounds/doesn't exist!" );
                exit(EXIT_FAILURE);
            }
            break;
        }

        default:
            break;
    }

    return 0;
}
