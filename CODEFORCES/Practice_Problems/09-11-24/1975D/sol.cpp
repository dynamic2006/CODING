#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> adj;
vector<int> parents;

int dfs(int cur, int prev, int target, int height)
{
    parents[cur] = prev;
    if(cur == target) return (height+1)/2;

    int ans = -1;
    for(auto &next : adj[cur]){
        if(next != prev) ans = max(ans, dfs(next, cur, target, height+1));
    }
    return ans;
}

int dfsHeight(int cur, int prev, int height)
{
    int ans = height;
    for(auto &next : adj[cur]){
        if(next != prev) ans = max(ans, dfsHeight(next, cur, height+1));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a, b; cin >> a >> b;
        adj = vector<vector<int>>(n+1, vector<int>());
        parents = vector<int>(n+1, -1);
        for(int i=0; i<n-1; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        // for(auto &x : adj){
        //     for(auto &y : x){
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        int steps = dfs(a, 0, b, 0);
        // cout << "STEPS " << steps << endl;
        int midpoint = b;
        for(int i=0; i<steps; i++){
            midpoint = parents[midpoint];
        }

        int maxDepth = dfsHeight(midpoint, 0, 0);
        // cout << maxDepth << endl;
        int ans = 2*(n-1) - maxDepth + steps;
        cout << ans << endl;
    }
}