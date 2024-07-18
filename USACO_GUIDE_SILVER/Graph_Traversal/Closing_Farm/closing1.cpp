#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> closed, visited;

void dfs(int node)
{
    visited[node] = true;
    for(auto& next : adj[node]){
        if(!visited[next]) dfs(next);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("closing.in" , "r" , stdin);
    freopen("closing.out" , "w" , stdout);

    cin >> n >> m;
    adj = vector<vector<int>>(n+1, vector<int>());
    closed = vector<bool>(n+1, true);
    visited = vector<bool>(n+1, true);
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> closingOrder(n);
    for(int i=0; i<n; i++) cin >> closingOrder[i];

    vector<string> ans(n, "YES");
    for(int i=n-1; i>=0; i--){
        closed[closingOrder[i]] = false;
        visited = closed;
        dfs(closingOrder[i]);
        for(auto x : visited){
            if(!x){
                ans[i] = "NO";
                break;
            }
        }
    }

    for(auto a : ans) cout << a << endl;
}