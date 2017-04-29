/* 
 * File:   main.cpp
 * Author: fs
 *
 * Created on 28. April 2017, 13:59
 */

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

    vector<string> data{ 
        "##########", 
        "####.....#", 
        "###......#", 
        "##.......#", 
        "#........#", 
        "#........#", 
        "#........#", 
        "#........#", 
        "#........#", 
        "##########",}; 
        
        GameEngine ge(10,10,data); 
        ge.run();
    
    
    return 0;
}

