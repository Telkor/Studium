#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Tile.h"
#include "Passive.h"
#include "Active.h"

using namespace std;

void Active::setPassive(Passive* ppointer_){
    ppointer = ppointer_;
}