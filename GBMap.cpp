#include "GBMap.h"
#include <vector>

using std::vector;
using std::string;
using std::to_string;

GBMap::GBMap(int numOfPlayers) {
    int fromNode, toSouthNode, toNorthNode, toEastNode, toWestNode, i, j, k, l, m, n, o, p, q, r, s;
    board = new Graph(false);
    switch(numOfPlayers) {
        case 2:{
            for (i = 0; i < 25; i++) { //create a graph with 25 nodes
                board->addNode(0, to_string(i));
            }
            for (j = 0; j < 25; j++) {
                fromNode = j;
                toSouthNode = fromNode + 5;
                toEastNode = fromNode + 1;
                toWestNode = fromNode - 1;
                toNorthNode = fromNode - 5;
                //the first 7 if/if else statements are special cases where nodes aren't connected to 4 nodes next to them
                if (fromNode == 0) { //node 0 doesn't have a north or west node since it's in the top left corner
                    board->addEdge(to_string(fromNode), to_string(toSouthNode));
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                } else if (fromNode == 4) { //node 4 doesn't have a north or east node since it's in the top left corner
                    board->addEdge(to_string(fromNode), to_string(toSouthNode));
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                } else if (fromNode == 20) { //node 20 doesn't have a south node or a west node since it's in the bottom left corner
                    board->addEdge(to_string(fromNode), to_string(toNorthNode));
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                } else if (fromNode == 24) { //node 24 doesn't have a south or east node since it's in the bottom right corner
                    board->addEdge(to_string(fromNode), to_string(toNorthNode));
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                } else if (fromNode == 1 || fromNode == 2 || fromNode == 3) { //no north node (top of board game)
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                    board->addEdge(to_string(fromNode), to_string(toSouthNode));
                } else if (fromNode == 21 || fromNode == 22 || fromNode == 23) { //no south node (bottom of board game)
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                    board->addEdge(to_string(fromNode), to_string(toNorthNode));
                } else if (fromNode % 5 == 0) { //no west node (right of board game)
                    board->addEdge(to_string(fromNode), to_string(toNorthNode));
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                    board->addEdge(to_string(fromNode), to_string(toSouthNode));
                } else if (fromNode % 5 == 4) { //no east node (left of board game)
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                    board->addEdge(to_string(fromNode), to_string(toNorthNode));
                    board->addEdge(to_string(fromNode), to_string(toSouthNode));
                } else {
                    board->addEdge(to_string(fromNode), to_string(toNorthNode));
                    board->addEdge(to_string(fromNode), to_string(toSouthNode));
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                }
            }
            break;
        }
        case 3: {
            for (l = 0; l < 35; l++) {
                board->addNode(0, to_string(l));
            }
            for (m = 0; m < 35; m++) {
                fromNode = m;
                toSouthNode = fromNode + 5;
                toEastNode = fromNode + 1;
                toWestNode = fromNode - 1;
                toNorthNode = fromNode - 5;
                if (fromNode == 0) {
                    board->addEdge(to_string(fromNode), to_string(toSouthNode));
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                } else if (fromNode == 4) {
                    board->addEdge(to_string(fromNode), to_string(toSouthNode));
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                } else if (fromNode == 30) {
                    board->addEdge(to_string(fromNode), to_string(toNorthNode));
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                } else if (fromNode == 34) {
                    board->addEdge(to_string(fromNode), to_string(toNorthNode));
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                } else if (fromNode == 1 || fromNode == 2 || fromNode == 3) {
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                    board->addEdge(to_string(fromNode), to_string(toSouthNode));
                } else if (fromNode == 31 || fromNode == 32 || fromNode == 33) {
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                    board->addEdge(to_string(fromNode), to_string(toNorthNode));
                } else if (fromNode % 5 == 0) {
                    board->addEdge(to_string(fromNode), to_string(toNorthNode));
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                    board->addEdge(to_string(fromNode), to_string(toSouthNode));
                } else if (fromNode % 5 == 4) {
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                    board->addEdge(to_string(fromNode), to_string(toNorthNode));
                    board->addEdge(to_string(fromNode), to_string(toSouthNode));
                } else {
                    board->addEdge(to_string(fromNode), to_string(toNorthNode));
                    board->addEdge(to_string(fromNode), to_string(toSouthNode));
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                }
            }
            break;
        }
        case 4: {
            for (o = 0; o < 45; o++) {
                board->addNode(0, to_string(o));
            }
            for (p = 0; p < 5; p++) {
                fromNode = p;
                toEastNode = fromNode + 1;
                toSouthNode = fromNode + 6;
                toWestNode = fromNode - 1;
                board->addEdge(to_string(fromNode), to_string(toSouthNode)); //all nodes are connected to a south node
                if (fromNode == 4) {
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                }
                else if(fromNode == 0){
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                }
                else {
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                    board->addEdge(to_string(fromNode), to_string(toEastNode)); //connected to east node

                }
            }
            for (q = 5; q <= 32; q++) {
                fromNode = q;
                toEastNode = fromNode + 1;
                toSouthNode = fromNode + 7;
                toWestNode = fromNode - 1;
                toNorthNode = fromNode - 7;
                board->addEdge(to_string(fromNode), to_string(toSouthNode)); //all edges are connected to a south node
                if (fromNode == 5) {
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                } else if (fromNode == 11) { //node 11 which doesn't have a north node or east one
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                } else if (fromNode % 7 == 5) { //left side of the board that don't have a west node
                    board->addEdge(to_string(fromNode), to_string(toNorthNode));
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                } else if (fromNode % 7 == 4) { //right nodes of the board which are not connected to east nodes
                    board->addEdge(to_string(fromNode), to_string(toNorthNode));
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                } else { //nodes that are connected to 4 nodes (including south)
                    board->addEdge(to_string(fromNode), to_string(toNorthNode));
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                }
            }
            for (r = 33; r <= 39; r++) {
                fromNode = r;
                toEastNode = fromNode + 1;
                toSouthNode = fromNode + 6;
                toNorthNode = fromNode - 7;
                toWestNode = fromNode - 1;
                board->addEdge(to_string(fromNode), to_string(toNorthNode));
                if (fromNode == 33) {
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                } else if (fromNode == 39) {
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                } else {
                    board->addEdge(to_string(fromNode), to_string(toSouthNode));
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                }
            }
            for (s = 40; s <= 44; s++) {
                fromNode = s;
                toEastNode = fromNode + 1;
                toNorthNode = fromNode - 7;
                toWestNode = fromNode - 1;
                board->addEdge(to_string(fromNode), to_string(toNorthNode));
                if (fromNode == 40) {
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                }
                else if (fromNode == 44) {
                    board->addEdge(to_string(fromNode), to_string(toWestNode));
                }
                else {
                    board->addEdge(to_string(fromNode), to_string(toEastNode));
                }
            }
            break;
        }
        default:
            break;

    }
}

GBMap::GBMap(){
    numOfPlayers = 0;
}

Graph* GBMap::getBoard() {
    return board;
}

double GBMap::getTileData(string position) {
    return board->getNodeValue(position);
}

void GBMap::setTileData(string position, double data) {
    board->setNodeValue(position, data);
}
