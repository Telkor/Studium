#ifndef TRAP_H
#define	TRAP_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Floor.h"

using namespace std;

class Trap : public Floor{
    
    public:
        Trap();
        bool setTriggered(bool m_triggered);
        void print() override;
        
    private:
        bool triggered;
};


#endif	/* TRAP_H */

