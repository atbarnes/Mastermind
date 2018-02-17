#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <guessGrid.h>
#include <checkGrid.h>
#include <peg.h>


class masterMind
{
    public:
        masterMind();
        void help(); //Mastermind instructions
        string getColor(char c); //Converts the character color into a string color

        guessGrid * guess;
        checkGrid * check;
    protected:

    private:
        bool play = true; //If play = false, game is over
        int guesses;
        char choice;

};

#endif // MASTERMIND_H
