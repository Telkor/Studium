#ifndef CONSOLECONTROLLER_H
#define	CONSOLECONTROLLER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Controller.h"

class ConsoleController : public Controller{

public:
    //ConsoleController();
    char move() override;
    
        
private:
};


#endif	/* CONSOLECONTROLLER_H */

