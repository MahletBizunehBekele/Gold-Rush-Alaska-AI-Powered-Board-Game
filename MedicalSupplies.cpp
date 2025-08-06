/* Mahlet Bekele – 2643146
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */
#include "MedicalSupplies.h"
#include "Player.h"

MedicalSupplies::MedicalSupplies(int n):Element(1,'S',floor(n/4)) {}
void MedicalSupplies::applyEffect(Player& player) {
    player.updateHealth(effect);
}
