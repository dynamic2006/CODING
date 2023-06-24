#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1505;

int n , ans = 0;
vector<string> directions;
int cowCounts[MAXN][MAXN], rvats[MAXN], cvats[MAXN];

void floodfill(int r, int c, int newCows){
    cowCounts[r][c] += newCows;

    if(r == n){
        ans += newCows * cvats[c]; return;
        //cout << ans << endl;
    }
    if(c == n){
        ans += newCows * rvats[r]; return;
        //cout << ans << endl;
    }

    if(directions[r][c] == 'R') floodfill(r, c+1, newCows);
    else floodfill(r+1, c, newCows);
}

int main(){
    //freopen("p2.in" , "r" , stdin);

    cin >> n;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        directions.push_back(s);
        cin >> rvats[i];
    }
    for(int i=0; i<n; i++) cin >> cvats[i];

    //find initial cow distribution
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cowCounts[i][j]++;
            if(directions[i][j] == 'R') cowCounts[i][j+1] += cowCounts[i][j];
            else cowCounts[i+1][j] += cowCounts[i][j];
        }
    }

    //calculate initial cost
    for(int i=0; i<n; i++){
        ans += rvats[i]*cowCounts[i][n];
        ans += cvats[i]*cowCounts[n][i];
    }
    cout << ans << endl;

    int q; cin >> q;
    while(q--){
        int i, j; cin >> i >> j;
        i--; j--;
        if(directions[i][j] == 'R') directions[i][j] = 'D';
        else directions[i][j] = 'R';
        
        if(directions[i][j] == 'R'){
            //switches from pointing down to pointing right
            floodfill(i, j+1, cowCounts[i][j]);
            floodfill(i+1, j, -cowCounts[i][j]);
        }
        else{
            //switches from right to down
            floodfill(i+1, j, cowCounts[i][j]);
            floodfill(i, j+1, -cowCounts[i][j]);
        }
        cout << ans << endl;
    }
    return 0;

}