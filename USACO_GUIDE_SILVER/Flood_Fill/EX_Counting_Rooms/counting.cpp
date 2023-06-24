#include <bits/stdc++.h>
using namespace std;

int n , m;
vector<string> floorPlan;
bool visited[1000][1000];

void floodfill(int row , int col , char floor){
    if(row < 0 || row >= n || col < 0 || col >= m) return;
    if(floorPlan[row][col] != floor || visited[row][col]) return;

    visited[row][col] = true;

    floodfill(row+1 , col , floor);
    floodfill(row-1 , col , floor);
    floodfill(row , col+1 , floor);
    floodfill(row , col-1 , floor);

}

int main(){
    //freopen("counting.in" , "r" , stdin);

    cin >> n >> m;
    floorPlan.resize(n);

    for(int i=0; i<n; i++){
        cin >> floorPlan[i];
    }

    int totalRooms = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && floorPlan[i][j] == '.'){
                floodfill(i , j , floorPlan[i][j]);
                totalRooms++;
            }
        }
    }

    cout << totalRooms << endl;
    return 0;

}