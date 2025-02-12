#include <iostream>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    if(sr == er && sc == ec) return true;
    maze[sr][sc] = 'X';

    bool found = false;
    if(sr-1 >= 0 && maze[sr-1][sc] != 'X') found |= pathExists(maze, nRows, nCols, sr-1, sc, er, ec);
    if(sc+1 < nCols && maze[sr][sc+1] != 'X') found |= pathExists(maze, nRows, nCols, sr, sc+1, er, ec);
    if(sr+1 < nRows && maze[sr+1][sc] != 'X') found |= pathExists(maze, nRows, nCols, sr+1, sc, er, ec);
    if(sc-1 >= 0 && maze[sr][sc-1] != 'X') found |= pathExists(maze, nRows, nCols, sr, sc-1, er, ec);

    return found;
}

int main()
{
    string maze[10] = {
        "XXXXXXXXXX",
        "X........X",
        "XX.X.XXXXX",
        "X..X.X...X",
        "X..X...X.X",
        "XXXX.XXX.X",
        "X.X....XXX",
        "X..XX.XX.X",
        "X...X....X",
        "XXXXXXXXXX"
    };

    if (pathExists(maze, 10,10, 6,4, 1,1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}