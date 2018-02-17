#include "masterMind.h"
#include <stdlib.h>

masterMind::masterMind()
{
    bool choiceMade;    //Initialize Variables

    cout << "Welcome To MasterMind!" << endl;   //Introduction
    cout << "CodeBreaker vs. CodeMaker" << endl;

    while (choiceMade == false)
    {
        cout << "What difficulty would you like to play?" << endl;
        cout << "(E)asy (12 guesses) | (N)ormal (10 guesses) | (H)ard (8 guesses) | (Q)uit: " << endl;
        cin >> choice;

        //Difficulty choice

        if (choice == 'E')
        {
            guess = new guessGrid(12);
            check = new checkGrid(12);
            guess->makeCode();
            guesses = 12;
            choiceMade = true;
        }

        else if (choice == 'N')
        {
            guess = new guessGrid(10);
            check = new checkGrid(10);
            guess->makeCode();
            guesses = 10;
            choiceMade = true;
        }

        else if (choice == 'H')
        {
            guess = new guessGrid(8);
            check = new checkGrid(8);
            guess->makeCode();
            guesses = 8;
            choiceMade = true;
        }

        else if (choice == 'Q')
        {
            exit(0);
        }

        else
        {
            choice = NULL;
            cout << "I'm sorry. That is not an option. Please try again" << endl;
        }

    }

    while (play == true)
    {
        char a, b, c, d, e;
        string f, g, h, k;
        guess->display(check);
        cout << "\n" << "\n" << "(M)ake a guess | (H)elp | (Q)uit: " << endl;
        cout << "colors: (r)ed, (b)lue, (g)reen, (y)ellow, (o)range, (p)urple)" << endl;
        cin >> a;
        if (a == 'M')
        {
            cin >> b;
            cin >> c;
            cin >> d;
            cin >> e;
            string f = getColor(b); //Converts the character entered into a string
            string g = getColor(c);
            string h = getColor(d);
            string k = getColor(e);
            if (f == "undefined" || g == "undefined" || h == "undefined" || k == "undefined") //If any color is undefined, throw an error
            {
                cout << "Error: Undefined color";
            }

            else //Else set each grids row
            {
                guess->setRow(f, g, h, k);
                check->setRow(guess);
                check->incrementGuess(); //And increment guess
            }

            if (check->determineWin() == true) //Determine if the user is a winner
            {
                guess->getPeg(0, 0)->uncover();
                guess->getPeg(0, 1)->uncover();
                guess->getPeg(0, 2)->uncover();
                guess->getPeg(0, 3)->uncover();
                guess->display(check);
                cout << "\n\n" << "Congratulations! You broke the code!" << endl;
                play = false;
            }

            if (check->getGuessNumber() == guesses) //Determine if the user lost
            {
                guess->getPeg(0, 0)->uncover();
                guess->getPeg(0, 1)->uncover();
                guess->getPeg(0, 2)->uncover();
                guess->getPeg(0, 3)->uncover();
                guess->display(check);
                cout << "\n\n" << "I'm sorry! You didn't break the code" << endl;
                play = false;
            }
        }

        else if (a == 'H') //If they enter H, go to help
        {
            help();
        }

        else if (a == 'Q') //If they enter Q, exit
        {
            cout << "Thanks for playing!";
            exit(0);
        }

        else //Invalid input
        {
            cout << "Sorry. Not a valid input.";
        }
    }



}

string masterMind::getColor(char c)
{
    if (c == 'r')
    {
        return "red";
    }

    else if (c == 'b')
    {
        return "blue";
    }

    else if (c == 'g')
    {
        return "green";
    }

    else if (c == 'y')
    {
        return "yellow";
    }

    else if (c == 'p')
    {
        return "purple";
    }

    else if (c == 'o')
    {
        return "orange";
    }

    else
    {
        return "undefined";
    }
}

void masterMind::help()
{

    cout << "\n";
    cout << "MasterMind Rules: " << endl;
    cout << "Depending on the difficulty, you will have a certain amount of guesses to figure out the CodeMaker's code" << endl;
    cout << "The code will be four pegs long, and may consist of six colors ((r)ed, (b)lue, (g)reen, (y)ellow, (o)range, or (p)urple)" << endl;
    cout << "To make a guess, when prompted, type 'M c c c c' where c is any of the available colors" << endl;
    cout << "After every guess, the codemaker will tell you on the bottom grid how many are right or wrong" << endl;
    cout << "If the codemaker puts a black peg in the grid, it means you have one color right and in the right location" << endl;
    cout << "If the codemaker puts a white peg in the grid, it means you have one color right but in the wrong location" << endl;
    cout << "\n" << "Note: Doubles are allowed in the codemakers code, but if you guess only one of the doubled color, the codemaker will only tell you that you have one color right" << endl;

}


