#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Controller.h"
#include "ConsoleController.h"
#include "StationaryController.h"
#include "Item.h"

using namespace std;

class Character{

public:
    Character();
    ~Character();
    Character(char zeichenart, int m_strength, int m_stamina, bool m_isKI);
    char move();
    char getZeichen() const;
    void setZeichen(char q);
    int getMaxHP();
    void showInfo();
    void addItem(Item* items);
    int getStrength();
    int getStamina();
    
private:
    char zeichen = '8';
    Controller* controller;
    int strength;
    int stamina;
    int hitpoints;
    vector<Item*> items;
    bool isKI;
    StationaryController* stat;
    ConsoleController* cons;
};


