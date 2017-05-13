#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Switch.h"

using namespace std;

char Switch::printSwitch(){
    if(Active::getStatus() == true){
        return '!';
    }
    else{
        return '?';
    }
}
