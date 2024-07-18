#include <bits/stdc++.h>
using namespace std;

struct Cow
{
    int x, y;
};

const int MAXNUM = 1e9;
int n, m;
int minX, minY, maxX, maxY;
vector<Cow> cows;
vector<bool> visited;
vector<vector<int>> adj;

void dfs(int i){
    visited[i] = true;
    minX = min(minX, cows[i].x);
    maxX = max(maxX, cows[i].x);
    minY = min(minY, cows[i].y);
    maxY = max(maxY, cows[i].y);

    for(auto& next : adj[i]){
        if(!visited[next]) dfs(next);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("fenceplan.in" , "r" , stdin);
    freopen("fenceplan.out" , "w" , stdout);

    cin >> n >> m;
    cows.resize(n+1);
    visited.assign(n+1, false); visited[0] = true;
    adj = vector<vector<int>>(n+1, vector<int>());

    //cout << "CHECKPOINT" << endl;

    for(int i=1; i<=n; i++) cin >> cows[i].x >> cows[i].y;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //cout << "CHECKPOINT" << endl;

    //dfs to find connected components
    int minPeri = MAXNUM;
    for(int i=1; i<=n; i++){
        minX=MAXNUM, minY=MAXNUM, maxX=0, maxY=0;
        if(!visited[i]) dfs(i);
        else continue;
        if(minX == maxX) min(minPeri, (maxY - minY));
        else if(minY == maxY) min(minPeri, (maxX - minX));
        else minPeri = min(minPeri, 2*(maxX - minX) + 2*(maxY - minY));
    }

    cout << minPeri << endl;

}