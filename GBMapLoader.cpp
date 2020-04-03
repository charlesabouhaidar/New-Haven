#include "Cpp-Graph-Library-master/Graph.h"
#include "GBMapLoader.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;

GBMapLoader::GBMapLoader(int numberOfPlayers) {
    ifstream myFile("../GBMapLoad.txt");
    string mystring, data, nodeNumber;
    GBMap *gbMap = new GBMap(numberOfPlayers);
    //int numOfPlayers = 0;
   // Graph *board = new Graph(false);
    if (!myFile.is_open()) {
        perror("Error opening");
        exit(EXIT_FAILURE);
    }
    else {
            while (getline(myFile, mystring)) {
                if(mystring.empty()){ //if empty line just skip
                    continue;
                }
                else if(mystring.size() > 7){
                    perror("Incorrect format, map can't load");
                    exit(EXIT_FAILURE);
                }
                istringstream var(mystring);
                var >> nodeNumber >> data; //first number is the node number, second number is the data inside of that node(topRight,topLeft,bottomRight,bottomLeft, playerID)
                /*char num = data.back(); //get last character of string to find playerID (1-4) !!!ASSUME THAT ALL PLAYERS HAVE PLAYED AT LEAST ONE MOVE!!!
                int number = num - '0';
                if(numOfPlayers > number ){
                    numOfPlayers = num;
                }
                 */
                //output(nodeNumber, data); check if values are taken in correctly
                gbMap->getBoard()->addNode(stod(data), nodeNumber);
            }
            myFile.close();
        
    }
}

/*
void GBMapLoader::output(string nodeNumber, string data){
    cout << "\nNode number: " << nodeNumber << endl;
    cout << "Data: " << data << endl;
}
*/
