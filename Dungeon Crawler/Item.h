#ifndef ITEM_H
#define	ITEM_H

#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

class Item{
    
public:
   Item();
    
    virtual int modifyStrength(int strength) = 0;
    virtual int modifyStamina(int stamina) = 0;
   
    
private:
    
    
};

class Arming_Sword : public Item{

public:
    int modifyStrength(int strength);
    int modifyStamina(int stamina);
    
};

class Greatsword : public Item{
   
public:
    int modifyStrength(int strength);
    int modifyStamina(int stamina);
};

class Club : public Item{

public:
    int modifyStrength(int strength);
    int modifyStamina(int stamina);
};

class RapierAndDagger : public Item{

public:
    int modifyStrength(int strength);
    int modifyStamina(int stamina);
};

class Gambeson : public Item{

public:
    int modifyStrength(int strength);
    int modifyStamina(int stamina);
};

class Mail_Armour : public Item{

public:
    int modifyStrength(int strength);
    int modifyStamina(int stamina);    
};

class Shield : public Item{
 
public:
    int modifyStrength(int strength);
    int modifyStamina(int stamina);    
};

class Full_Plate_Armour : public Item{

public:
    int modifyStrength(int strength);
    int modifyStamina(int stamina);
};


#endif	/* ITEM_H */

