/* Mahlet Bekele – 2643146
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */
#include <iostream>
#include "Grid.h"
using namespace std;

int main() {
    cout << "Welcome to GoldRush Alaska!" << endl;
    int size;
    cout<<"Enter the grid size: ";
    cin>>size;

    string name1, name2;
    cout << "Enter Player 1 name: ";
    cin>>name1;
    cout << "Enter Player 2 name: ";
    cin>>name2;

    // Ensure the grid size is at least 5
    while(size < 5){
        cout<<"Size must be greater than or equal to 5!! Enter grid size again: ";
        cin>>size;
    }

    cout << "# represents hidden resources, beware of WildAnimals." << endl;

    Grid grid(size);
    Player player1(size, name1);
    Player player2(size, name2);

    int Totalturns = (rand()%(size*size - 20 + 1) + 20);
    int playerturn= 0;


    // Main game loop
    while(playerturn<= Totalturns && (player1.getHealth()!=0 || player2.getHealth()!=0) && !(grid.allCellsAreNull())){
        // Determine the current player based on turn number
        Player& currentPlayer = (playerturn%2 == 0)? player1: player2;

        grid.display();

        int x,y;
        cout<<"Player "<<(playerturn%2+1)<<" Enter coordinates(x,y):";
        cin>>x>>y;

        // Check if the coordinates are within the grid range
        if(grid.checkCoord(x,y)){
            // Check if the selected cell is empty..nothing happens..turn goes to the next player
            if(grid.getcells(x,y) == nullptr){
                ++playerturn;

                cout<<player1.getName()<<":: Health: "<<player1.getHealth()<<" Score: "<<player1.getScore()<<endl;
                cout<<player2.getName()<<":: Health: "<<player2.getHealth()<<" Score: "<<player2.getScore()<<endl;
                continue;
            }
            // Check if the element in the selected cell has already been unveiled
            else if(grid.isElementUnveiled(grid.getcells(x,y))){
                cout<<"Element has been unveiled"<<endl;
                continue;
            }

            // Handle the player's move
            grid.handlemove(x,y,currentPlayer);
            ++playerturn;

            cout<<player1.getName()<<":: Health: "<<player1.getHealth()<<" Score: "<<player1.getScore()<<endl;
            cout<<player2.getName()<<":: Health: "<<player2.getHealth()<<" Score: "<<player2.getScore()<<endl;
        }
        else{
            cout<<"Coordinates are not within the range!! Try again."<<endl;
        }
        // Check if all gold has been taken
        if(grid.checkGold()){
            cout<<"All Gold has been taken."<<endl;
            break;
        }
    }

    // Determine and announce the winner based on scores
    if(player1.getScore() > player2.getScore()){
        cout<<player1.getName()<<" wins!!!"<<endl;
    }
    else if(player2.getScore() > player1.getScore()){
        cout<<player2.getName()<<" wins!!!"<<endl;
    }
    else if(player2.getScore() == player1.getScore()){
        cout<<"It's a tie"<<endl;
    }

    return 0;
}
