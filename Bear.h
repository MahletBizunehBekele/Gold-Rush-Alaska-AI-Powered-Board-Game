/* Mahlet Bekele – 2643146
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */
#ifndef _3_BEAR_H
#define _3_BEAR_H
#include "WildAnimal.h"
#include "Player.h"


class Bear: public WildAnimal{
public:
    Bear(int);
    void applyEffect(class Player&) override;    // Method that applies the effect of encountering a bear to the player

};

#endif //_3_BEAR_H
