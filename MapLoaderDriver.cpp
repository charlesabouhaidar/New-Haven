#include <iostream>
#include "GBMapLoader.h"
#include "VGMapLoader.h"
using std::cout;
using std::cin;
using std::endl;

int main(){
    int mapToLoad;
    cout << "Choose an option:\n1. Load GBMap\n2. Load VGMap" << endl;
    cin >> mapToLoad;
    switch(mapToLoad){
        case 1: {
            GBMapLoader *gbMap = new GBMapLoader();
            break;
        }
        case 2:{
            VGMapLoader *vgMap = new VGMapLoader();
            break;
        }
        default:{
            break;
        }
    }
    system("pause");
}
