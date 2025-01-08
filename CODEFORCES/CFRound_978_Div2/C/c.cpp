#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool countUp(vector<string>& grid, int lastFullColIdx)
{
    int count = 0;
    if(grid[0][lastFullColIdx] == 'A') count++;
    if(grid[1][lastFullColIdx] == 'A') count++;
    if(grid[0][lastFullColIdx+1] == 'A') count++;

    return (count >= 2);
}

bool countDown(vector<string>& grid, int lastFullColIdx)
{
    int count = 0;
    if(grid[0][lastFullColIdx] == 'A') count++;
    if(grid[1][lastFullColIdx] == 'A') count++;
    if(grid[1][lastFullColIdx+1] == 'A') count++;

    return (count >= 2);
}

bool countFull(vector<string>& grid, int lastFullColIdx)
{
    int count = 0;
    for(int i=0; i<3; i++){
        if(grid[0][lastFullColIdx-i] == 'A') count++;
        if(grid[1][lastFullColIdx-i] == 'A') count++;
    }

    return (count >= 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> grid(2);
        cin >> grid[0] >> grid[1];

        ll up=0, down=0, full=0;
        if(countUp(grid, 0)) up++;
        if(countDown(grid, 0))
    }

}

//ideas
//looks like a dp problem
//three possible shapes/transitions
//xx   x  xxx
// x  xx  xxx
//store three diff dps for these
//index by number of "full cols"
//1. take off two straights or last unit->state3
//2. same deal as 1
//3. take off either unit OR take off both straights