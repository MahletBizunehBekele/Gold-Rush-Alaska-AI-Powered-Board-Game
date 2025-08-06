/* Mahlet Bekele – 2643146
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */
#include "Element.h"

Element::Element(int sz, char sym, int eff) : size(sz), symbol(sym), effect(eff) {}
char Element:: getsymbol() {return symbol;}
int Element:: getsize()const{return size;}
