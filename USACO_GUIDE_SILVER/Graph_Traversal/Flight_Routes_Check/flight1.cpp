#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
int lastVisited = 0;
vector<bool> visited;
vector<vector<int>> adj, adjInverse;

void dfs(int i, vector<vector<int>> &adj)
{
    lastVisited = i;
    visited[i] = true;
    for(auto &next : adj[i]){
        if(!visited[next]) dfs(next, adj);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("flight.in", "r", stdin);

    cin >> n >> m;
    visited = vector<bool>(n+1, false);
    adj = vector<vector<int>>(n+1, vector<int>());
    adjInverse = vector<vector<int>>(n+1, vector<int>());
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adjInverse[b].push_back(a);
    }

    dfs(1, adj);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return 0;
        }
    }

    visited.assign(n+1, false);
    dfs(1, adjInverse);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

}