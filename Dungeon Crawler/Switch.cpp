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

void Switch::print(){
    if(Active::getStatus() == true){
        cout << "!";
    }
    else{
        cout << "?";
    }
}
