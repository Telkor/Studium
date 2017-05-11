#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "Character.h"

using namespace std;

Character::Character(){
    
}

Character::Character(char zeichenart){
    zeichen = zeichenart;
}  
    
char Character::move(){
    
    char c;
    bool exit = false;
    
    while (!exit){
     
    cin >> c;
        
    switch(c) {
        case 'w': return 'w';
        case 'a': return 'a';
        case 's': return 's';
        case 'd': return 'd';
        default : return 0;
    }    
    }
}

char Character::getZeichen() const{
    return zeichen;
}