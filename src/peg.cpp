#include "peg.h"

peg::peg()
{

}

//Creates peg with user specified color. If color is undefined, defaults to red
peg::peg(string s)
{
    if (s == "blue")
    {
        color = "blue";
    }

    else if (s == "green")
    {
        color = "green";
    }

    else if (s == "orange")
    {
        color = "orange";
    }

    else if (s == "yellow")
    {
        color = "yellow";
    }

    else if (s == "purple")
    {
        color = "purple";
    }

    else if (s == "black") //Black and white used for the check guess grid
    {
        color = "b";
    }

    else if (s == "white")
    {
        color = "w";
    }

    else
    {
        color = "red";
    }
}

void peg::uncover()
{
    uncovered = true;
}

string peg::getColor()
{
    if (uncovered == false)
    {
        return "O";
    }

    return color;
}

string peg::getUncoveredColor()
{
    return color;
}

void peg::check()
{
    checked = true;
}

void peg::uncheck()
{
    checked = false;
}

bool peg::isChecked()
{
    if (checked == true)
    {
        return true;
    }

    else
    {
        return false;
    }
}

void peg::setColor(string s)
{
    if (s == "blue")
    {
        color = "blue";
    }

    else if (s == "green")
    {
        color = "green";
    }

    else if (s == "orange")
    {
        color = "orange";
    }

    else if (s == "yellow")
    {
        color = "yellow";
    }

    else if (s == "purple")
    {
        color = "purple";
    }

    else if (s == "black") //Black and white used for the check guess grid
    {
        color = "b";
    }

    else if (s == "white")
    {
        color = "w";
    }

    else
    {
        color = "red";
    }
}
