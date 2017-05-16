#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Switch.h"

using namespace std;

void Switch::setPassive(Passive* m_pPointer){
  
}

bool Switch::getStatus(){
    
}

char Switch::printSwitch(){
    if(Active::getStatus() == true){
        return '!';
    }
    else{
        return '?';
    }
}
