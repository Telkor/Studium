#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "DungeonMap.h"
#include "Character.h"

class GameEngine{

public:
    GameEngine(int height, int width, const vector<string>& data, vector<string> info);
    ~GameEngine();
    bool finished() const;
    void turn();
    void run();
    void linker(vector<string> &info);
    
private:
    DungeonMap dm;
    vector<Character*> spielfiguren;
    int spielEnde = 10;
};


