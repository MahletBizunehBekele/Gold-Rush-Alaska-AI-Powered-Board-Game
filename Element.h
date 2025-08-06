// Mahlet Bekele – 2643146
//e read and accept the submission rules and the extra rules specified in each question. This is
//our own work that is done by us only
#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
#include <cmath>
#include <random>
//#include "Player.h"

class Player;
class Element {
protected:
    int size;
    char symbol;
    int effect;
public:
    Element(int, char, int);    // Constructor to initialize an element with size, symbol, and effect
    char getsymbol();
    int getsize()const;
    virtual void applyEffect(class Player&)= 0;   // Pure virtual method to apply the element's effect on a player

};

#endif // ELEMENT_H
