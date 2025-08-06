/* Mahlet Bekele – 2643146
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */
#include "Gold.h"

Gold::Gold(int n):Element(1,'G',100){}

void Gold::applyEffect(Player& player) {
    player.updateScore();
}