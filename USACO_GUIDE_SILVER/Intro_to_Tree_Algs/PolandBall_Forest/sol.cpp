#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void dfs(int cur, vector<vector<int>>& adj, vector<bool>& vis)
{
    vis[cur] = true;
    for(auto& next : adj[cur]){
        if(!vis[next]) dfs(next, adj, vis);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    vector<vector<int>> adj(n+1, vector<int>());
    vector<bool> vis(n+1, false);
    for(int i=1; i<=n; i++){
        int p; cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    int trees = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i, adj, vis);
            trees++;
        }
    }
    cout << trees << endl;

}