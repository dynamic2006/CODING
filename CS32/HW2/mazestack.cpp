#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Coord
{
    public:
        Coord(int r, int c) : m_row(r), m_col(c) {}
        int r() const { return m_row; }
        int c() const { return m_col; }
    private:
        int m_row;
        int m_col;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    stack<Coord> dfs;
    dfs.push(Coord(sr, sc)); maze[sr][sc] = 'X';
    while(!dfs.empty()){
        Coord cur = dfs.top(); dfs.pop();
        int r = cur.r(), c = cur.c();
        if(r == er && c == ec) return true; 

        if(r-1 >= 0 && maze[r-1][c] != 'X'){
            dfs.push(Coord(r-1, c)); maze[r-1][c] = 'X';
        }
        if(c+1 < nCols && maze[r][c+1] != 'X'){
            dfs.push(Coord(r, c+1)); maze[r][c+1] = 'X';
        }
        if(r+1 < nRows && maze[r+1][c] != 'X'){
            dfs.push(Coord(r+1, c)); maze[r+1][c] = 'X';
        }
        if(c-1 >= 0 && maze[r][c-1] != 'X'){
            dfs.push(Coord(r, c-1)); maze[r][c-1] = 'X';
        }
    }
    return false;
}