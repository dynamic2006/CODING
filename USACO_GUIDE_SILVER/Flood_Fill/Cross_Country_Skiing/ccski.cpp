#include <bits/stdc++.h>
using namespace std;

const int MAX = 500;
int n , m;
int grid[MAX][MAX];
vector<pair<int , int>> waypoints;
bool visited[MAX][MAX];

void floodfill(int row, int col , int d){
    if(row < 0 || row >= n || col < 0 || col >= m || visited[row][col]) return;
    visited[row][col] = true;
    
    int curVal = grid[row][col];
    if(abs(curVal - grid[row+1][col]) <= d) floodfill(row+1 , col , d);
    if(abs(curVal - grid[row-1][col]) <= d) floodfill(row-1 , col , d);
    if(abs(curVal - grid[row][col+1]) <= d) floodfill(row , col+1 , d);
    if(abs(curVal - grid[row][col-1]) <= d) floodfill(row , col-1 , d);
}

bool valid(int dVal){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            visited[i][j] = false;
        }
    }
    floodfill(waypoints[0].first , waypoints[0].second , dVal);
    for(auto x : waypoints){
        if(!visited[x.first][x.second]) return false;
    }
    return true;
}

int binarySearch(int lo , int hi){
    while(lo < hi){
        int mid = lo + (hi - lo)/2;
        if(valid(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main(){
    freopen("ccski.in" , "r" , stdin);
    freopen("ccski.out" , "w" , stdout);

    cin >> n >> m;
    int maxHeight = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
            maxHeight = max(maxHeight , grid[i][j]);
        }
    }
    int num;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> num;
            if(num == 1){
                waypoints.push_back(make_pair(i , j));
            }
        }
    }

    cout << binarySearch(0 , maxHeight) << endl;

}

/*
 * PLAN
 * binary search for min value of D
 * for a given value of D
 * floodfill from one waypoint
 * if it can reach all other waypoints, then D works
 */