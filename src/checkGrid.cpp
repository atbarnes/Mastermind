#include "checkGrid.h"

checkGrid::checkGrid(int guess)
{
    guesses = guess;
    g = new peg**[guesses];
    for(int i = 0; i < guesses; i++)
    {
        g[i] = new peg*[pegSlots];
    }

    for(int i = 0; i < guesses; i++)
    {
        for (int j = 0; j < pegSlots; j++)
        {
            g[i][j] = new peg();
        }
    }
}

void checkGrid::display()
{
    for (int i = 0; i < guesses; i++) //Displays the pegs
    {

        for (int j = 0; j < pegSlots; j++)
        {

            cout << g[i][j]->getColor();

            if (j == 3)
            {
                cout << "|";
            }
        }
    }

    for (int i = 0; i < guesses; i++) //Displays the numbers under the rows
    {
        if (i == 0)
        {
            cout << "\n" << i + 1;
        }

        else
        {
            cout << "    " << i + 1;
        }
    }
}

int checkGrid::getGuessNumber()
{
    return guessNumber;
}

void checkGrid::incrementGuess()
{
    guessNumber++;
}

bool checkGrid::determineWin()
{
    for(int i = 0; i < pegSlots; i++)
    {
        if (g[guessNumber-1][i]->getUncoveredColor() == "b") //If all pegs are black pegs, there is a winner
        {
            win++;
            if (win == pegSlots)
            {
                return true;
            }
        }

    }
    win = 0;
    return false;
}

void checkGrid::setRow(guessGrid * a)
{
    if (a->getPeg(a->getRow()+1, 0)->getUncoveredColor() == a->getPeg(0, 0)->getUncoveredColor()) //Have to check for exact matches first
    {
            correct++;
            a->getPeg(0, 0)->check();
            a->getPeg(a->getRow()+1, 0)->check();
    }

    if (a->getPeg(a->getRow()+1, 1)->getUncoveredColor() == a->getPeg(0, 1)->getUncoveredColor())
    {
            correct++;
            a->getPeg(0, 1)->check();
            a->getPeg(a->getRow()+1, 1)->check();
    }

    if (a->getPeg(a->getRow()+1, 2)->getUncoveredColor() == a->getPeg(0, 2)->getUncoveredColor())
    {
            correct++;
            a->getPeg(0, 2)->check();
            a->getPeg(a->getRow()+1, 2)->check();
    }

    if (a->getPeg(a->getRow()+1, 3)->getUncoveredColor() == a->getPeg(0, 3)->getUncoveredColor())
    {
            correct++;
            a->getPeg(0, 3)->check();
            a->getPeg(a->getRow()+1, 3)->check();
    }

    for (int i = 0; i < pegSlots; i++) //After finding exact matches, if any, determine just color matches
    {

        for (int j = 0; j < pegSlots; j++)
        {
            if (a->getPeg(a->getRow()+1, j)->getUncoveredColor() == a->getPeg(0, i)->getUncoveredColor())
            {

                if (a->getPeg(0, i)->isChecked() == false && a->getPeg(a->getRow()+1, j)->isChecked() == false)
                {
                    colorCorrect++;
                    a->getPeg(0, i)->check();
                    a->getPeg(a->getRow()+1, j)->check();
                }

            }

        }
    }
    //Add pegs to the grid
    for (int i = correct; i > 0; i--)
    {
        g[guessNumber][checkSlot]->setColor("black");
        g[guessNumber][checkSlot]->uncover();
        checkSlot++;
    }

    for (int i = colorCorrect; i > 0; i--)
    {
        g[guessNumber][checkSlot]->setColor("white");
        g[guessNumber][checkSlot]->uncover();
        checkSlot++;
    }

    //uncheck codemakers code for next time
    a->getPeg(0, 0)->uncheck();
    a->getPeg(0, 1)->uncheck();
    a->getPeg(0, 2)->uncheck();
    a->getPeg(0, 3)->uncheck();

    //Reset increments
    checkSlot = 0;
    correct = 0;
    colorCorrect = 0;
}
