/* Mahlet Bekele – 2643146
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */
#ifndef FOOD_H
#define FOOD_H
#include "Element.h"
#include "Player.h"

class Food: public Element{
public:
    Food(int);
    void applyEffect(class Player&) override;
};


#endif
