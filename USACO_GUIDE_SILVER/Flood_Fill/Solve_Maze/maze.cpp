#include <bits/stdc++.h>
using namespace std;

int n , m;
vector<string> grid;
bool works = true , visited[50][50];

//ideas
//block off the bads from the goods -- dfs
//if a bad can reach a good initial -- then no ans
//dfs for the good people -- include empty spaces 
//if only one good person component that includes exit
//then cout YES else cout NO

void blockOffBads(int row , int col){
    //cout << "Blocking" << endl;
    if(row < 0 || row >= n || col < 0 || col >= m || visited[row][col]) return;
    if(grid[row][col] == 'G'){ works = false; return; }

    visited[row][col] = true;

    if(grid[row][col] == 'B'){
        blockOffBads(row+1 , col);
        blockOffBads(row-1 , col);
        blockOffBads(row , col+1);
        blockOffBads(row , col-1);
    }
    else{
        grid[row][col] = '#';
    }

}

void floodfill(int row , int col){
    if(row < 0 || row >= n || col < 0 || col >= m || visited[row][col] || grid[row][col] == '#') return;
    visited[row][col] = true;

    floodfill(row+1 , col);
    floodfill(row-1 , col);
    floodfill(row , col-1);
    floodfill(row , col+1);
}

void solve(){

    cin >> n >> m;
    works = true;
    grid.clear(); grid.resize(n);
    for(int i=0; i<n; i++){
        cin >> grid[i];
    }
    for(int i=0 ; i<50; i++){
        for(int j=0; j<50; j++){
            visited[i][j] = false;
        }
    }

    //go through all the squares in the grid for bads
    //make a fence around each bad component
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && grid[i][j] == 'B'){
                blockOffBads(i , j);
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }

    //floodfill over the good / empty space people
    //if only one component cout YES, else cout FALSE
    if(works){
        floodfill(n-1 , m-1);
    }
    else{
        cout << "NO" << endl; return;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && grid[i][j] == 'G'){
                cout << "NO" << endl; return;
            }
        }
    }

    cout << "YES" << endl; return;

}

int main(){
    //freopen("maze.in" , "r" , stdin);

    int t; cin >> t;
    //int i=1;
    while(t--){
        //cout << i++ << endl;
        solve();
    }

}