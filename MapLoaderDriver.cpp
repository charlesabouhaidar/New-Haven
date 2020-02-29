//
// Created by Charles Abou Haidar on 2020-01-22.
//
#include <iostream>
#include "GBMapLoader.h"
#include "VGMapLoader.h"
using namespace std;

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
        }
        default:{
            break;
        }
    }
}
