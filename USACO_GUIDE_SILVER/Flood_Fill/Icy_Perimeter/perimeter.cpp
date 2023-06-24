#include <bits/stdc++.h>
using namespace std;

int n;
int curCompArea = 0 , curCompPeri = 0;
int maxCompArea = 0 , minCompPeri = 10e9;
vector<string> blobs;
bool visited[1000][1000];

void floodfill(int row , int col , char cream){
    if(row < 0 || row >= n || col < 0 || col >= n || blobs[row][col] != cream){
        curCompPeri++; return;
    }
    if(visited[row][col]) return;

    visited[row][col] = true;
    curCompArea++;

    floodfill(row+1 , col , cream);
    floodfill(row-1 , col , cream);
    floodfill(row , col+1 , cream);
    floodfill(row , col-1 , cream);

}

int main(){
    freopen("perimeter.in" , "r" , stdin);
    freopen("perimeter.out" , "w" , stdout);

    cin >> n;
    blobs.resize(n);

    for(int i=0; i<n; i++){
        cin >> blobs[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && blobs[i][j] == '#'){
                curCompArea = 0;
                curCompPeri = 0;
                floodfill(i , j , blobs[i][j]);
                if(curCompArea > maxCompArea){
                    maxCompArea = curCompArea;
                    minCompPeri = curCompPeri;
                }
                else if(curCompArea == maxCompArea){
                    minCompPeri = min(minCompPeri , curCompPeri);
                }
            }
        }
    }

    cout << maxCompArea << " " << minCompPeri << endl;

    return 0;

}