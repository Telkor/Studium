#include "Active.h"

using namespace std;

Active::Active(){
    pPointer = nullptr;
}

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





