#include "guessGrid.h"
#include <time.h>
#include <stdlib.h>

guessGrid::guessGrid(int guess)
{
    currentRow = guess;
    rows = guess + 1;
    g = new peg**[rows]; //Plus 1 because the added row is used for the codemakers slot
    for(int i = 0; i < rows; i++)
    {
        g[i] = new peg*[pegSlots];
    }

    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < pegSlots; j++)
        {
            g[i][j] = new peg();
        }
    }

}

void guessGrid::display(checkGrid * a)
{
    for(int i = 0; i < rows; i++)
    {
        cout << "\n";
        if (i == 0) //Initial number formatting
        {
            cout << "    ";
        }

        if (i != 0 && (rows - i) < 10)
        {
           cout << rows - i << "   ";
        }

        if (i != 0 && (rows - i) >= 10)
        {
           cout << rows - i << "  ";
        }
        for (int j = 0; j < pegSlots; j++) //Formatting and printing pegs
        {
            if (i == 1 && j == 3)
            {
                cout << g[i][j]->getColor() << " ";
            }
            else
            {
                cout << g[i][j]->getColor() << " ";
            }

        }

        if (i == 0)
        {
            cout << "\n" << "    - - - -";
        }
    }
    cout << "\n" << "\n";
    a->display();
}

void guessGrid::makeCode()
{
    srand( time(NULL) );
    int randNum;


    for (int i = 0; i < pegSlots; i++)
    {
        randNum = rand() % 6;
        if (randNum == 0)
        {
            g[0][i]->setColor("red");
        }

        else if (randNum == 1)
        {
            g[0][i]->setColor("blue");
        }

        else if (randNum == 2)
        {
            g[0][i]->setColor("green");
        }

        else if (randNum == 3)
        {
            g[0][i]->setColor("orange");
        }

        else if (randNum == 4)
        {
            g[0][i]->setColor("purple");

        }

        else
        {
            g[0][i]->setColor("yellow");

        }
    }
}

bool guessGrid::determineWin()
{
    for (int i = 0; i < pegSlots; i++)
    {
        if (g[currentRow][i]->getUncoveredColor() == g[0][i]->getUncoveredColor())
        {
            win++;
            if (i = 3)
            {
                return true;
            }
        }
    }

    win = 0;
    return false;
}


void guessGrid::setRow(string a, string b, string c, string d)
{
    g[currentRow][0]->setColor(a);
    g[currentRow][0]->uncover();
    g[currentRow][1]->setColor(b);
    g[currentRow][1]->uncover();
    g[currentRow][2]->setColor(c);
    g[currentRow][2]->uncover();
    g[currentRow][3]->setColor(d);
    g[currentRow][3]->uncover();
    currentRow--;
}
