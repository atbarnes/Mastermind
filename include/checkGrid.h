#ifndef CHECKGRID_H
#define CHECKGRID_H

#include <grid.h>
#include <guessGrid.h>
#include <iostream>

class guessGrid;

class checkGrid : public grid
{
    public:
        checkGrid(); //The grid that tells the user which colors are right
        checkGrid(int guess);

        void display();
        void setRow(guessGrid * a); //After a turn, sets the row colors
        int getGuessNumber(); //Returns number of guesses
        void incrementGuess(); //Increments the number of guesses made
        bool determineWin(); //Determines if the user has guessed the code

    protected:

    private:
        int rows; //How many total rows are in the checkGrid
        int correct = 0; //Used for setRow. Determines when color and position are correct
        int colorCorrect = 0; //USed for setRow. Setermines when color is correct
        int checkSlot = 0; //Used for setRow and determining which slots have been filled
        int guesses; //How many total guesses they get
        int guessNumber = 0; //The number of guesses they have made
        int win = 0;
};

#endif // CHECKGRID_H
