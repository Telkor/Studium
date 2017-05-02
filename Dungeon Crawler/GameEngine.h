#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "DungeonMap.h"
#include "Character.h"

class GameEngine{

public:
    GameEngine(int height, int width, const vector<string>& data);
    ~GameEngine();
    bool finished();
    void turn();
    void run();
    
private:
    DungeonMap dm;
    vector<Character*> spielfiguren;
    int spielEnde = 10;
};


