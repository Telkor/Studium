#ifndef CHARACTER_H
#define	CHARACTER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

class Character{

public:

    Character();
    Character(char zeichenart);
    int move();
    char getZeichen();
    
private:
    char zeichen;
    
};

#endif	/* CHARACTER_H */

