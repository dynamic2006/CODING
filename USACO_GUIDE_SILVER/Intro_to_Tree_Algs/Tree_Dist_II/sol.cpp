#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<vector<int>> adj;
vector<int> depth, dp;
vector<ll> ans;

void dfs1(int cur, int prev)
{
    for(auto &next : adj[cur]){
        if(next == prev) continue;
        dfs1(next, cur);
        dp[cur] += dp[next];
    }
}

void dfs2(int cur, int prev)
{
    for(auto &next : adj[cur]){
        if(next == prev) continue;
        ans[next] = n + ans[cur] - 2*dp[next];
        dfs2(next, cur);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    cin >> n;
    adj = vector<vector<int>>(n+1, vector<int>());
    depth = vector<int>(n+1, 0);
    dp = vector<int>(n+1, 1);
    ans = vector<ll>(n+1, -1);

    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q; q.push(1);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto &next : adj[cur]){
            if(next == 1 || depth[next] != 0) continue;
            q.push(next);
            depth[next] = depth[cur] + 1;
        }
    }

    ll total = 0;
    for(int i=1; i<=n; i++) total += depth[i];
    ans[1] = total;
    
    dfs1(1, 0); //fills dp array
    dfs2(1, 0); //fills ans array

    for(int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}