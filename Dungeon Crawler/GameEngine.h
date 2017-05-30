#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "DungeonMap.h"
#include "Character.h"


class GameEngine{

public:
    GameEngine(int height, int width, const vector<string>& data, vector<string> info, vector<string> &specialTiles);
    ~GameEngine();
    bool finished() const;
    void turn();
    void run();
    void linker(vector<string> &info);
    void link(vector<string> &specialTiles);
    
private:
    DungeonMap dm;
    vector<Character*> spielfiguren;
    int spielEnde = 100;
};


