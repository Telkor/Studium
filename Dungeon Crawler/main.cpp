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
    vector<string> info{"6 5 D 2 4 S"};
    vector<string> data{ 
        "##########", 
        "####.....#", 
        "###.S....#", 
        "##.......#", 
        "#........#", 
        "#........#", 
        "#....D...#", 
        "#........#", 
        "#........#", 
        "##########",}; 
        
       GameEngine ge(10,10,data, info); 
       ge.run();
    
    
    return 0;
}
