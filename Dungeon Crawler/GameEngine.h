#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "DungeonMap.h"
#include "Character.h"


class GameEngine{

public:
    GameEngine(int height, int width, const vector<string>& data, vector<string> &specialTiles);
    ~GameEngine();
    bool finished() const;
    void turn();
    void run();
    void linker(vector<string> &info);
    void link(vector<string> &specialTiles);
    //void loadFromFile(string filename);
    
private:
    DungeonMap dm;
    vector<Character*> spielfiguren;
    int spielEnde = 100;
};


