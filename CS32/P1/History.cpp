#include "History.h"
#include "globals.h"
#include <iostream>
using namespace std;

History::History(int nRows, int nCols)
{
    m_rows = nRows;
    m_cols = nCols;
    for(int i=0; i<MAXROWS; i++){
        for(int j=0; j<MAXCOLS; j++){
            recordGrid[i][j] = 0;
        }
    }
}

bool History::record(int r, int c)
{
    if(r < 1 || r > m_rows || c < 1 || c > m_cols) return false; //invalid r,c
    recordGrid[r-1][c-1]++; //record this knockback
    return true;
}

void History::display() const
{
    char grid[MAXROWS][MAXCOLS];

    for (int r = 0; r < m_rows; r++){
        for (int c = 0; c < m_cols; c++){
            grid[r][c] = '.';
            //if there is atleast one bee, draw corresponding character in grid
            if(recordGrid[r][c] >= 26) grid[r][c] = 'Z'; //for >= 26 bees
            else if(recordGrid[r][c] > 0) grid[r][c] = ('A' + (recordGrid[r][c] - 1));
        }
    }

    // Draw the grid
    clearScreen();
    for (int r = 0; r < m_rows; r++)
    {
        for (int c = 0; c < m_cols; c++)
            cout << grid[r][c];
        cout << endl;
    }
    cout << endl;
}
