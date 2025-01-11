#ifndef HISTORY_INCLUDED
#define HISTORY_INCLUDED

#include "globals.h"

class History
{
    public:
        History(int nRows, int nCols);
        bool record(int r, int c);
        void display() const;

    private:
        int m_rows;
        int m_cols;
        int recordGrid[MAXROWS][MAXCOLS];
};

#endif

//finish this part (new feature)
//also check project requirements -- esp the parts about not putting unnecessary #includes
//i think the #includes part only applies to headers but double check that anyways