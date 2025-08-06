/* Mahlet Bekele – 2643146
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */
#ifndef _3_GRID_H
#define _3_GRID_H
#include <vector>
#include <random>
#include <algorithm>
#include <time.h>
#include <cstdlib>

#include "Food.h"
#include "Wolf.h"
#include "Wood.h"
#include "Bear.h"
#include "MedicalSupplies.h"
#include "Gold.h"
using namespace std;


class Grid {
private:
    int size;
    vector<vector<Element*>>cells;
    vector<Element*>Unveiledcells;

public:
    Grid(int);
    void initializeGrid();
    void display();
    void handlemove(int,int,Player&);
    bool checkCoord(int,int);
    bool allCellsAreNull();
    void processEndOfRoundBonuses(Player&);
    void placeElement(Element*);

    bool isElementUnveiled(Element*);
    Element* createElement(Element*);
    void processBonusesWood(Player &p);
    void processBonusesGold(Player &p);
    Element* getcells(int ,int)const;
    bool checkGold();
    ~Grid();
};
#endif //_3_GRID_H
