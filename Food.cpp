/* Mahlet Bekele – 2643146
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */
#include "Food.h"

Food::Food(int n):Element(1,'F',n/6){}

void Food::applyEffect(Player& player) {
    player.updateHealth(effect);
}
