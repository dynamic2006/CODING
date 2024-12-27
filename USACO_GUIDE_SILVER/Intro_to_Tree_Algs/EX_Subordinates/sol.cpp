#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void dfs(int cur, vector<vector<int>>& adj, vector<int>& ans)
{
    int tot = 0;
    for(auto& next : adj[cur]){
        dfs(next, adj, ans);
        tot += ans[next]+1;
    }
    ans[cur] = tot;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    vector<vector<int>> adj(n+1, vector<int>());
    for(int i=2; i<=n; i++){
        int a; cin >> a;
        adj[a].push_back(i);
    }

    vector<int> ans(n+1, 0);
    dfs(1, adj, ans);

    for(int i=1; i<=n; i++) cout << ans[i] << " ";
    cout << endl;
}