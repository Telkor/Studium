#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "Item.h"

Item::Item(){
    
}

int Arming_Sword::modifyStamina(int stamina){
    return 0;
}

int Arming_Sword::modifyStrength(int strength){
    return strength + 3;
    return 3;
}

int Greatsword::modifyStamina(int stamina){
    
    return -1;
}

int Greatsword::modifyStrength(int strength){
    return 5;
}

int Club::modifyStamina(int stamina){
    return 0;
}

int Club::modifyStrength(int strength){
    return strength/2;
}

int RapierAndDagger::modifyStamina(int stamina){
    return 1;
}

int RapierAndDagger::modifyStrength(int strength){
    return 2;
}

int Gambeson::modifyStamina(int stamina){
    return 1;
}

int Gambeson::modifyStrength(int strength){
    return 0;
}

int Mail_Armour::modifyStamina(int stamina){
    return 3;
}

int Mail_Armour::modifyStrength(int strength){
    return 0;
}

int Shield::modifyStamina(int stamina){
    return stamina;
}

int Shield::modifyStrength(int strength){
    return -1;
}

int Full_Plate_Armour::modifyStamina(int stamina){
    return 6;
}

int Full_Plate_Armour::modifyStrength(int strength){
    return -2;
}