#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Controller.h"
#include "ConsoleController.h"


class Character{

public:
    Character();
    Character(char zeichenart);
    char move();
    char getZeichen() const;
    void setZeichen(char q);
    
private:
    char zeichen = '8';
    Controller* controller;
    
};


