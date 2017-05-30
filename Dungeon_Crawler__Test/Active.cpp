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
    pPointer->setStatus(m_status);
}

Passive* Active::getPassive(){
    return pPointer;
}
