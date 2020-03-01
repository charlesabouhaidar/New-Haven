#include "Cpp-Graph-Library-master/Graph.h"
#include "Cpp-Graph-Library-master/Node.h"
#include "VGMapLoader.h"
#include <iostream>

using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;


VGMapLoader::VGMapLoader() {
    ifstream myFile("../VGMapLoad.txt");
    string mystring, data, nodeNumber;
    Graph *board = new Graph(false);
    if(!myFile.is_open()){
        perror("Error opening");
        exit(EXIT_FAILURE);
    }
    else {
        while (getline(myFile, mystring)) {
            if(mystring.empty()){ //if empty line just skip
                continue;
            }
            else if(mystring.size() > 7){ //format is: nodeNumber data (total of 7 characters)
                perror("Incorrect format, map can't load");
                exit(EXIT_FAILURE);
            }
            istringstream var(mystring);
            var >> nodeNumber >> data; //first number is the node number, second number is the data inside of that node(topRight,topLeft,bottomRight,bottomLeft, playerID)
            output(nodeNumber, data);
            board->addNode(stod(data), nodeNumber);
        }
        myFile.close();
    }
}

void VGMapLoader::output(string nodeNumber, string data){
    cout << "\nNode number: " << nodeNumber << endl;
    cout << "Data: " << data << endl;
}
