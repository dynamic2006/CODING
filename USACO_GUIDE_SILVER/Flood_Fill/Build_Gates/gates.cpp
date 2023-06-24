#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int deg = 0, n; string moves;
map<char , pair<int , int>> coordChange;
bool visited[4*(MAXN+1)][4*(MAXN+1)];

int main(){

    coordChange['E'] = {1,0}; coordChange['W'] = {-1,0}; coordChange['N'] = {0,1}; coordChange['S'] = {0,-1};

    freopen("gates.in" , "r" , stdin);
    freopen("gates.out" , "w" , stdout);

    cin >> n >> moves;

    int x=2*MAXN, y=2*MAXN, ans = 0; visited[x][y] = true;
    for(int i=0; i<n; i++){
        int xchange = coordChange[moves[i]].first,  ychange = coordChange[moves[i]].second;
        if(visited[x][y] && visited[x+2*xchange][y+2*ychange] && !visited[x+xchange][y+ychange]) ans++;
        visited[x+xchange][y+ychange] = true;
        x += 2*xchange; y += 2*ychange;
        visited[x][y] = true;
    }

    cout << ans << endl;
    return 0;

}