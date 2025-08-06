/* Mahlet Bekele – 2643146
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */
#include "Player.h"


Player::Player(int n, string name):health(2*n),name(name),score(0){}

// Method to update the player's health by a specified amount
void Player:: updateHealth(int n){
    health += n;
}


// Method to update the player's score
// Increases the score by 100 points
void Player:: updateScore(){
    score += 100;
}


void Player:: takeDamage(int n){

    health = health - n;
    if(health<0){
        health = 0;
    }
}
// Method to get a reference to the vector of elements gathered by the player
vector<Element*>& Player::getGatheredElements()  {
    return gatheredElements;
}

int Player:: getHealth(){return health;}
int Player:: getScore(){return score;}
string Player::getName() { return name; }

// Method to add an element to the player's collection of gathered elements
void Player::addElement(Element *resource) {
    gatheredElements.push_back(resource);
}
