#include "Cpp-Graph-Library-master/Graph.h"
#include "GBMapLoader.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;

GBMapLoader::GBMapLoader() {
    ifstream myFile("../GBMapLoad.txt");
    string mystring, data, nodeNumber;
    int numOfPlayers = 0;
   // Graph *board = new Graph(false);
    if (!myFile.is_open()) {
        perror("Error opening");
        exit(EXIT_FAILURE);
    }
    else {
        if(myFile.peek() == std::ifstream::traits_type::eof()){ //if file is empty, create GBMap object without num of players
            GBMap *gbMap = new GBMap();
        }
        else{ //if file not empty, load data onto GBMap object
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
                char num = data.back(); //get last character of string to find playerID (1-4) !!!ASSUME THAT ALL PLAYERS HAVE PLAYED AT LEAST ONE MOVE!!!
                int number = num - '0';
                if(numOfPlayers > number ){
                    numOfPlayers = num;
                }
                GBMap *gbMap = new GBMap(numOfPlayers);
                //output(nodeNumber, data); check if values are taken in correctly
                gbMap->getBoard()->addNode(stod(data), nodeNumber);
            }
            myFile.close();
        }
    }
}

/*
void GBMapLoader::output(string nodeNumber, string data){
    cout << "\nNode number: " << nodeNumber << endl;
    cout << "Data: " << data << endl;
}
*/
