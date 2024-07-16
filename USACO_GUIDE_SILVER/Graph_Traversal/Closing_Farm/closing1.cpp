#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> closed;
vector<bool> visited;

void dfs(int node)
{
    visited[node] = true;
    for(auto next : adj[node]){
        if(!visited[next] && !closed[next]) dfs(next);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("closing.in" , "r" , stdin);

    cin >> n >> m;
    adj = vector<vector<int>>(n+1, vector<int>());
    closed = vector<bool>(n+1, false);
    visited = vector<bool>(n+1, false);

    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=0; i<m; i++){
        int closing; cin >> closing;
        for(int )
    }

}