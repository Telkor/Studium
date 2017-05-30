#ifndef STATIONARYCONTROLLER_H
#define	STATIONARYCONTROLLER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Controller.h"

class StationaryController : public Controller{

public:
    StationaryController();
    StationaryController(Character* c);
    char move() override;
    
        
private:
};


#endif	/* STATIONARYCONTROLLER_H */

