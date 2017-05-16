#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Tile.h"
#include "Passive.h"
#include "Active.h"

using namespace std;

void Active::setPassive(Passive* m_pPointer){
    pPointer = m_pPointer;
}

/*void Active::setStatus(bool m_status){
    status = m_status;
}*/

bool Active::getStatus(){
    return status;
}

void Active::setStatus(bool m_status){
    status = m_status;
}

/* void Active::onLeave(Tile* toTile){
    
} */

void Active::onEnter(Character* c, Tile* fromTile){
    held = c;
    setStatus(true);
}