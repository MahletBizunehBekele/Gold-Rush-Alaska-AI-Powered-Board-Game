/* Mahlet Bekele – 2643146
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */
#ifndef WOLF_H
#define WOLF_H
#include "WildAnimal.h"
#include "Player.h"


class Wolf:public WildAnimal {
public:
    Wolf(int);
    void applyEffect(class Player&) override;
};


#endif //WOLF_H
