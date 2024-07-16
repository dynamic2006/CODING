#include <bits/stdc++.h>
using namespace std;

const int MAXCOST = 1250000000;

struct Cow{
    int id, x , y;
};

int n , reachedNodes = 0;
vector<Cow> cows;
vector<bool> visited;
map<int , vector<int>> adj;

//distance^2 has to be r at most
void dfs(int node , int r){
    if(visited[node]) return;
    visited[node] = true; reachedNodes++;
    for(int i=1; i<=n; i++){
        //only process this cow in the next dfs if reachable by the radius r
        double squareDist = (cows[i].x - cows[node].x)*(cows[i].x - cows[node].x) + (cows[i].y - cows[node].y)*(cows[i].y - cows[node].y);
        if(squareDist <= r) dfs(cows[i].id , r);
    }
}

bool valid(int cost){
    reachedNodes = 0;
    fill(visited.begin() , visited.end() , false);
    dfs(1 , cost);
    if(reachedNodes == n) return true;
    return false;
}

int binarySearch(int lo , int hi){
    hi++;
    while(lo < hi){
        int mid = lo + (hi - lo)/2;
        if(valid(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main(){
    freopen("moocast.in" , "r" , stdin);
    freopen("moocast.out" , "w" , stdout);

    //binary search over the possible costs
    //for a given possible cost, dfs to see if all the cows are reachable
    //note that the graph is bidirectional since all cows have same radius of transmission in the problem

    cin >> n;
    cows.resize(n+1);
    visited.resize(n+1);

    for(int i=1; i<=n; i++){
        cows[i].id = i; cin >> cows[i].x >> cows[i].y;
    }

    cout << binarySearch(0 , MAXCOST) << endl;

}