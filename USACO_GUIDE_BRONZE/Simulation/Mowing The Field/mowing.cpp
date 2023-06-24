#include <iostream>
using namespace std;

int grid[2001][2001];

void move(char dir, int* time, int* ix, int* iy, int* mintime)
{
    if(dir == 'N'){++*iy;}
    if(dir == 'E'){++*ix;}
    if(dir == 'S'){--*iy;}
    if(dir == 'W'){--*ix;}

    if(grid[*ix][*iy] != 0){*mintime = min(*time - grid[*ix][*iy] , *mintime);}

    grid[*ix][*iy] = *time;
}

int main()
{

    freopen("mowing.in" , "r" , stdin);
    freopen("mowing.out" , "w" , stdout);

    int ix = 1000, iy = 1000;
    int time = 1, mintime = 1000;

    int N, steps; char d; cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> d >> steps;
        for(int j=0; j<steps; j++)
        {
            move(d, &time, &ix, &iy, &mintime);
            time++;
        }
    }

    if(mintime != 1000){cout << mintime;}
    else{cout << -1;}
}

