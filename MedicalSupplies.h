/* Mahlet Bekele – 2643146
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */
#ifndef _3_MEDICALSUPPLIES_H
#define _3_MEDICALSUPPLIES_H
#include "Element.h"

class MedicalSupplies:public Element {
public:
    MedicalSupplies(int);
    void applyEffect(class Player&) override;
};

#endif //_3_MEDICALSUPPLIES_H
