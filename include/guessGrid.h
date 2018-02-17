#ifndef GUESSGRID_H
#define GUESSGRID_H

#include <grid.h>
#include <checkGrid.h>
#include <iostream>

class checkGrid;

class guessGrid : public grid
{
    public:
        guessGrid(); //Creates the guess grid
        guessGrid(int guess);

        void display(checkGrid * a);
        void setRow(string a, string b, string c, string d); //After a turn, sets the row colors
        bool determineWin();
        int getRow(){return currentRow;}; //Returns the current row
        void makeCode(); //Makes the code makers code
    protected:

    private:
        int rows; //Number of rows
        int guesses; //Number of guesses the user has
        int currentRow = 0; //Keeps track of the current row in game
        int win = 0;
};

#endif // GUESSGRID_H
