/* Mahlet Bekele – 2643146
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */
#include "Grid.h"
#include <cmath>
// ANSI color codes for terminal output
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

using namespace std;


Grid::Grid(int n) : size(n), cells(n, vector<Element*>(n, nullptr)){
    initializeGrid();
}

// Method to initialize the grid with elements
void Grid::initializeGrid() {
    srand(time(0)); // Initialize random seed
    int elementsPerType = 2 * floor(size * size / 25.0);
    int bearCount = elementsPerType / 2;

    vector<Element*> elements;

    // Generate elements based on the calculated count
    for (int i = 0; i < elementsPerType; ++i) {
        elements.push_back(new Food(size));
        elements.push_back(new Wolf(size));
        elements.push_back(new MedicalSupplies(size));
        elements.push_back(new Gold(size));
        elements.push_back(new Wood(size));
    }
    for (int i = 0; i < bearCount; ++i) {
        elements.push_back(new Bear(size));
    }

    // Place each element in the grid
    for (Element* element : elements) {
          placeElement(element);
    }
}

// Method to place an element in the grid at a random position
void Grid::placeElement(Element* element) {
    bool placed = false;
    while (!placed) {
        int x = rand() % size;
        int y = rand() % size;

        // Check if the starting position is empty
        if (cells[x][y] == nullptr) {
            vector<pair<int, int>> positions;
            positions.push_back({x, y});
            bool validPlacement = true;

            // Handle multi-cell elements
            if (element->getsize() > 1) {
                int direction = rand() % 3; // 0: horizontal, 1: vertical, 2: diagonal

                for (int i = 1; i < element->getsize(); ++i) {
                    int newX = x, newY = y;

                    if (direction == 0) {
                        newX += i;
                    } else if (direction == 1) {
                        newY += i;
                    } else if (direction == 2) {
                        newX += i;
                        newY += i;
                    }

                    // Check if the new position is within bounds and empty
                    if (newX < size && newY < size && cells[newX][newY] == nullptr) {
                        positions.push_back({newX, newY});
                    } else {
                        validPlacement = false;
                        break;
                    }
                }
            }


            if (validPlacement) {
                for (auto pos : positions) {
                    Element *newelement = createElement(element);
                    cells[pos.first][pos.second] = newelement;
                }
                placed = true;
            }
        }
    }
}
// Method to create a new element
Element* Grid::createElement(Element* element) {
    if (element->getsymbol() == 'B') {
        return (new Bear(size));
    } else if (element->getsymbol() == 'I') {
        return (new Wood(size));
    } else if (element->getsymbol() == 'F') {
        return new Food(size);
    } else if (element->getsymbol() == 'S') {
        return new MedicalSupplies(size);
    } else if (element->getsymbol() == 'G') {
        return new Gold(size);
    } else if (element->getsymbol() == 'W') {
        return new Wolf(size);
    } else {
        return nullptr; // Handle the case where the symbol does not match any known element type
    }
}
bool Grid:: isElementUnveiled( Element* element) {
    for (Element* unveiledElement : Unveiledcells) {
        if (unveiledElement == element) {
            return true;
        }
    }
    return false;
}

// void Grid::display() {
//     cout << endl;
//
//     // Print column headers
//     cout << "    "; // Offset for row labels
//     for (int y = 0; y < size; y++) {
//         if (y < 10) cout << y << "   ";
//         else cout << y << "  ";
//     }
//     cout << endl;
//
//     for (int x = 0; x < size; x++) {
//         // Print row header
//         if (x < 10) cout << x << "   ";
//         else cout << x << "  ";
//
//         for (int y = 0; y < size; y++) {
//             if (isElementUnveiled(cells[x][y])) {
//                 char symbol = cells[x][y]->getsymbol();
//                 string color;
//
//                 switch (symbol) {
//                     case 'G': color = YELLOW; break;        // Gold
//                     case 'I': color = CYAN; break;          // Wood
//                     case 'F': color = GREEN; break;         // Food
//                     case 'S': color = MAGENTA; break;       // Medical Supplies
//                     case 'B': color = RED; break;           // Bear
//                     case 'W': color = BLUE; break;          // Wolf
//                     default:  color = RESET; break;
//                 }
//
//                 cout << color << symbol << RESET << "   ";
//             }
//             else if (cells[x][y]) {
//                 cout << "#   ";
//             }
//             else {
//                 cout << ".   ";
//             }
//         }
//         cout << endl;
//     }
// }


// Method to check if coordinates are within the bounds of the grid
bool Grid::checkCoord(int x, int y) {
    return (x>=0 && x<=(size-1) && y>=0 && y<=(size -1));
}

// Method to handle the player's move
void Grid::handlemove(int x,int y ,Player& p){

    srand(time(0));
    int randomNumber;
    if(cells[x][y]->getsymbol() == 'W' || cells[x][y]->getsymbol() == 'B'){
        randomNumber = (rand()%6) + 1;

        int userguess;
        cout<<"I've generated a random number :) \nGuess the whether it's even or odd "<<endl;
        cout<< "[1] Even\n[2] Odd\nEnter a number: "<<endl;
        cin>>userguess;

        if((randomNumber%2 == 0 && userguess == 2) ||(randomNumber%2 != 0 && userguess == 1)){
            cells[x][y]->applyEffect(p);
        }
        Unveiledcells.push_back(cells[x][y]);

    }else{
        cells[x][y]->applyEffect(p);
        p.addElement(cells[x][y]);
        Unveiledcells.push_back(cells[x][y]);

        if(cells[x][y]->getsymbol() == 'I' ){
            processBonusesWood(p);
        }
        else if(cells[x][y]->getsymbol() == 'G'){
            processBonusesGold(p);
        }
    }
}
bool Grid::allCellsAreNull() {
    for(int i =0; i< size; i++){
        for(int j =0;j <size;j++){
            if(cells[i][j]!=nullptr){
                return false;
            }
        }
    }
    return true;
}
// Method to process cumulative bonuses related to wood elements
void Grid::processBonusesWood(Player &p) {
    int woodCount = 0;

    vector<Element *> &gatheredElements = p.getGatheredElements();

    for (Element* resource: gatheredElements) {
        if (resource == nullptr) continue;
        else if (resource->getsymbol() == 'I') {
            woodCount++;
        }
    }

    if(woodCount > 0 && woodCount %2 == 0){
        p.updateHealth(floor(size / 8));
    }
}
// Method to process cumulative bonuses related to gold elements
void Grid::processBonusesGold(Player &p) {
    int goldCount = 0;

    vector<Element *> &gatheredElements = p.getGatheredElements();

    for (Element* resource: gatheredElements) {
        if (resource == nullptr) continue;
        else if (resource->getsymbol() == 'G') {
            goldCount++;
        }
    }

    if(goldCount > 0 && goldCount % 3 == 0){
        p.updateHealth(floor(size / 4));
    }
}
Element* Grid:: getcells(int x, int y)const{
    return cells[x][y];
}
// Method to check if all the gold elements have been unveiled
bool Grid::checkGold() {
    int count = 0;
    for(Element* cell:Unveiledcells){
        if(cell->getsymbol() == 'G'){
            count++;
        }
    }
    if(count == 2 * floor(size * size / 25.0)){
        return true;
    }
    return false;
}
Grid:: ~Grid(){
    for(int i=0;i<size;i++){
        for(int j=0; j<size; j++){
            delete cells[i][j];
        }
    }
}


void Grid::display() {
    cout << endl;
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (isElementUnveiled(cells[x][y])) {
                char symbol = cells[x][y]->getsymbol();
                string color;

                switch (symbol) {
                    case 'G': color = YELLOW; break;        // Gold
                    case 'I': color = CYAN; break;          // Wood
                    case 'F': color = GREEN; break;         // Food
                    case 'S': color = MAGENTA; break;       // Medical Supplies
                    case 'B': color = RED; break;           // Bear
                    case 'W': color = BLUE; break;          // Wolf
                    default:  color = RESET; break;
                }

                cout << color << symbol << RESET << ' ';
            }
            else if (cells[x][y]) {
                cout << "# ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}