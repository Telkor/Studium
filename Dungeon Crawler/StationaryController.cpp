#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "StationaryController.h"

using namespace std;

StationaryController::StationaryController() : Controller(){
    
}

StationaryController::StationaryController(Character* c) : Controller(c){
    
    
}

char StationaryController::move(){

    return 'r';
}