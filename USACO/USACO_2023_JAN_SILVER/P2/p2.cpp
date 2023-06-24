#include <bits/stdc++.h>
using namespace std;

const int MAXLEN = 1505;
vector<string> directions;
int cows[MAXLEN][MAXLEN];
int n, curCost = 0;

void floodfill(int row, int col, int cost, int goodDir){
    if(row < 0 || col < 0) return;
    if(directions[row][col] != goodDir) return;

    curCost += cost - cows[row][col];
    cows[row][col] = cost;

    floodfill(row-1, col, cost, 'D');
    floodfill(row, col-1, cost, 'R');
}

int main(){
    //freopen("p2.in" , "r" , stdin);

    cin >> n;
    directions.resize(n);
    for(int i=0; i<n; i++){
        cin >> directions[i];
        cin >> cows[i][n]; // note vats are NOT counted towards total cost
    }
    for(int i=0; i<n; i++){
        cin >> cows[n][i];
        floodfill(n-1, i, cows[n][i], 'D');
    }
    for(int i=0; i<n; i++){
        floodfill(i, n-1, cows[i][n], 'R');
    }

    cout << curCost << endl;

    //now we floodfill for each change

    int q; cin >> q;
    while(q--){
        int r, c, newCost; cin >> r >> c; //these are 1-indexed!
        r--; c--;
        if(directions[r][c] == 'D'){
            newCost = cows[r][c+1];
            directions[r][c] = 'R';
        }
        else{
            newCost = cows[r+1][c];
            directions[r][c] = 'D';
        }
        curCost += newCost - cows[r][c];
        cows[r][c] = newCost;

        floodfill(r-1, c, newCost, 'D');
        floodfill(r, c-1, newCost, 'R');

        cout << curCost << endl;
    }

}

/*
 * Ideas
 * make a 2D vector of the directions
 * make a 2D vector, and fill, with the initial costs per cow (floodfill this)
 * then for each query
 * if dir is switched R -> D
 * then cow at pos changes to cost of cow below it
 * else if dir is switched D -> R
 * then cow at pos changes to cost of cow to right of it
 * 
 * then starting at changed cow, floodfill using directions arr
 * continue up if up is D, continue left if left is R
 * stop once out of bounds
 * cout change in cost
 */