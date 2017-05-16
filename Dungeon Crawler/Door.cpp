#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Door.h"

using namespace std;

void Door::print(){
    if(Passive::getStatus() == true){
        cout << "X";
    }
    else{
        cout << "/";
    }
}
