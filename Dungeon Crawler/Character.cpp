#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Character.h"

Character::Character(){
    
}

Character::Character(char zeichenart){
    zeichen = zeichenart;
}  
    
int Character::move(){
    
}

char Character::getZeichen(){
    return zeichen;
}