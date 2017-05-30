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

Character::~Character(){
    delete[] controller;
    for(int i = 0; i < items.size(); i++){
        delete items.at(i);
    }
}

Character::Character(char zeichenart, int m_strength, int m_stamina, bool m_isKI){
    zeichen = zeichenart;
    strength = m_strength;
    stamina = m_stamina;
    hitpoints = getMaxHP();
    controller = new ConsoleController(this);
    stat = new StationaryController(this);
    cons = new ConsoleController(this);
    isKI = m_isKI;
    
}  
    
char Character::move(){
    if (isKI == true)
        return stat->move();
    else 
        return cons->move();
   
    //controller->move();
 
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
    return 20 + (getStamina() * 5);
}

void Character::showInfo(){
    cout << "Staerke: " << strength << "\n";
    cout << "Ausdauer: " << stamina << "\n"; 
    cout << "HP: " << hitpoints << "\n";
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