#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Tile.h"
#include "GameEngine.h"

using namespace std;

/*
 * 
 */
int main() {
    vector<string> specialTiles{"Character @ 5 5 ConsoleController 6 6", "Character % 5 5 StationaryController 3 4", "Door 6 2 Switch 2 4", "Greatsword 1 4"};
    vector<string> info{"6 2 D 2 4 S"};
    vector<string> data{ 
        "##########", 
        "####.....#", 
        "###.S....#", 
        "##.......#", 
        "#........#", 
        "#........#", 
        "#.D......#", 
        "#........#", 
        "#........#", 
        "##########",}; 
        
       GameEngine ge(10,10,data, info, specialTiles); 
       ge.run();
    
    
    return 0;
}
