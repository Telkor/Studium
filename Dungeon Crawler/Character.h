#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Controller.h"


class Character{

public:
    Character();
    Character(char zeichenart);
    char move();
    char getZeichen() const;
    
private:
    char zeichen;
    Controller* controller;
    
};


