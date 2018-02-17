#ifndef GRID_H
#define GRID_H
#include "peg.h"

class grid
{
    public:
        grid();

        peg* getPeg(int i, int j){return g[i][j];};
        virtual bool determineWin() = 0;

        peg ***g;
        int pegSlots = 4;

    protected:

    private:
};

#endif // GRID_H
