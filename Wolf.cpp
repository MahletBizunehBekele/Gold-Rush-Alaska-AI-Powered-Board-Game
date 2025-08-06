/* Mahlet Bekele – 2643146
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */
#include "Wolf.h"

Wolf::Wolf(int n):WildAnimal(1,'W',floor(n/4)){}
void Wolf::applyEffect(Player& player) {
    player.takeDamage(effect);
}