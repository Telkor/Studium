#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

class Character{

public:

    Character();
    Character(char zeichenart);
    char move();
    char getZeichen();
    
private:
    char zeichen;
    
};


