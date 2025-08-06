/* Mahlet Bekele – 2643146
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */
#ifndef _3_PLAYER_H
#define _3_PLAYER_H
#include <vector>
using namespace std;
#include "Element.h"
#include "Grid.h"

class Player{
private:
    string name;
    int health;
    int score;
    vector<Element*>gatheredElements;
public:
    Player(int, string);
    void updateHealth(int);
    void updateScore();
    void takeDamage(int);
    int getHealth();
    int getScore();
    void addElement(Element* resource);
    string getName();

    vector<Element*>& getGatheredElements() ;

};
#endif //_3_PLAYER_H

