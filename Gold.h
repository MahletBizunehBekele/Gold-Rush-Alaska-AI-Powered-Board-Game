/* Mahlet Bekele – 2643146
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */
#ifndef GOLD_H
#define GOLD_H
#include "Element.h"
#include "Player.h"

class Gold:public Element {
public:
    Gold(int);
    void applyEffect(class Player&) override;
};


#endif //GOLD_H
