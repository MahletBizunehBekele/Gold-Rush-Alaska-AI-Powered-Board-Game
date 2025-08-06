/* Mahlet Bekele – 2643146
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */
#include "Bear.h"

Bear::Bear(int n):WildAnimal(3,'B',floor(n/2)){}
void Bear::applyEffect(Player& player) {
    player.takeDamage(effect);
}