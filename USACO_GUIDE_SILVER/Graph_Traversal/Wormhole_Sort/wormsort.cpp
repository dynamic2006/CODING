#include <bits/stdc++.h>
using namespace std;

const int MAXNUM = 10e5 + 5;

struct Wormhole{
    int start , end , w;
};

bool cmp(Wormhole& a , Wormhole& b){
    return a.w > b.w;
}

int n , m;
bool works = true , sorted = true , visited[MAXNUM];
int cows[MAXNUM];
array<Wormhole , MAXNUM> wormholes;
map<int , vector<pair<int , int>>> adj;

void dfs(int minW , int pos , set<int>& compCows , set<int>& compPos){
    if(visited[pos]) return;
    visited[pos] = true;
    compCows.insert(cows[pos]); compPos.insert(pos);
    for(auto nextPos : adj[pos]){
        if(nextPos.second >= minW) dfs(minW , nextPos.first , compCows , compPos);
    }

}

bool valid(int index){
    works = true;
    for(int i=0; i<=n; i++){
        visited[i] = false;
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            set<int> includedCows , includedPos;
            dfs(wormholes[index].w , i , includedCows , includedPos);
            if(includedCows != includedPos) return false;
        }
    }
    return true;

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
    freopen("wormsort.in" , "r" , stdin);
    freopen("wormsort.out" , "w" , stdout);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> cows[i];
        if(cows[i] != i) sorted = false;
    }
    if(sorted){
        cout << -1 << endl; return 0;
    }
    for(int i=0; i<m; i++){
        cin >> wormholes[i].start >> wormholes[i].end >> wormholes[i].w;
        adj[wormholes[i].start].push_back(make_pair(wormholes[i].end , wormholes[i].w));
        adj[wormholes[i].end].push_back(make_pair(wormholes[i].start , wormholes[i].w));
    }
    //sort wormholes from largest to smallest
    sort(wormholes.begin() , wormholes.end() , cmp);

    int maxiMinIndex = binarySearch(0 , m-1);

    cout << wormholes[maxiMinIndex].w << endl; return 0;

}

/*
 * IDEAS
 * main assumption : if a component is connected (edges are wormholes)
 * then cows in this component can be swapped to satisfy any ordering
 * so -- we need components to be large enough to have all cows for the points
 * 
 * for a connected component -- keep 2 running sets
 * one set has the cows contained, the other has the positions
 * in valid() check if these two sets are equal -- then good
 * else NOT valid
 */

/*
 * NOTE
 * this solution does NOT pass the final 3 test cases (TLE)
 * for my purposes I determined that it was alright
 * as in a real competition 7/10 test cases would be good enough
 * however if you ever find a good optimization to use be sure to fix this solution!!!
 */