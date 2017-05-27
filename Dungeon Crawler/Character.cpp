#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "Character.h"
#include "Controller.h"

using namespace std;

Character::Character(){
    
}

Character::Character(char zeichenart, int m_strength, int m_stamina, int m_hitpoints){
    zeichen = zeichenart;
    strength = m_strength;
    stamina = m_stamina;
    hitpoints = getMaxHP();
    controller = new ConsoleController(this);
}  
    
char Character::move(){
    return controller->move();
    
    /*
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
    }  */
}

char Character::getZeichen() const{
    return zeichen;
}

void Character::setZeichen(char q){
    zeichen = q;
}

int Character::getMaxHP(){
    20 + (stamina * 5);
}

void Character::showInfo(){
    cout << "Staerke: " << strength;
    cout << "Ausdauer: " << stamina;
    cout << "HP: " << hitpoints;
}

void Character::addItem(Item* m_items){
    items.push_back(m_items);
}

int Character::getStrength(){
   
    for(int i = 0; i < items.size(); i++){
       strength += items.at(i)->modifyStrength(strength); 
       
    }
    
    return strength;
}

int Character::getStamina(){
    for(int i = 0; i < items.size(); i++){
        stamina += items.at(i)->modifyStamina(stamina);
    }
    
    return stamina;
}