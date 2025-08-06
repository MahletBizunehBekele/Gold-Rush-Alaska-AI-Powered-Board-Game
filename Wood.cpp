/* Mahlet Bekele – 2643146
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */
#include "Wood.h"

Wood::Wood(int n):Element(2,'I',floor(n/8)){}
void Wood::applyEffect(Player& player) {
    player.updateHealth(effect);
}
