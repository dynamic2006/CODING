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
    vector<bool> vis(n+1, false); vis[0] = true;
    vector<vector<int>> adj(n+1, vector<int>());
    for(int i=1; i<=n; i++){
        int a; cin >> a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i, adj, vis);
            ans++;
        }
    }

    cout << ans << endl;
}