#ifndef SWITCH_H
#define	SWITCH_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Active.h"

using namespace std;

class Switch : public Active{
    
public:
    //Switch();
    void setPassive(Passive* m_pPointer);
    bool getStatus();
    void print() override;
    
private:
    
};

#endif	/* SWITCH_H */

