#ifndef PEG_H
#define PEG_H
#include <string>

using namespace std;

class peg
{
    public:
        peg();
        peg(string c);
        void uncover(); //Uncovers peg
        string getColor(); //Get's peg color
        string getUncoveredColor(); //Get's the color regardless if it is uncovered
        void setColor(string s);
        void check();  //Peg has been checked for a match
        void uncheck(); //If unchecked, let's let's user know peg has not been checked for matches
        bool isChecked(); //Determines if peg has been checked

    protected:

    private:
        bool uncovered = false;
        bool checked = false;
        string color;

};

#endif // PEG_H
