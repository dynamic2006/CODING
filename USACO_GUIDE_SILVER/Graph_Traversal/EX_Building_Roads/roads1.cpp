#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
    visited[node] = true;
    for(auto next : adj[node]){
        if(!visited[next]) dfs(next, adj, visited);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("roads.in" , "r" , stdin);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>());

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n+1, false); visited[0] = true;
    vector<int> starts;
    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        starts.push_back(i);
        dfs(i, adj, visited);
    }

    cout << starts.size() - 1 << endl;
    for(int i=1; i<starts.size(); i++){
        cout << starts[i-1] << " " << starts[i] << endl;
    }

}