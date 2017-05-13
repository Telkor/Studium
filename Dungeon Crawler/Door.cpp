#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Door.h"

using namespace std;

char Door::printDoor(){
    if(Passive::getStatus() == true){
        return 'X';
    }
    else{
        return '/';
    }
}
