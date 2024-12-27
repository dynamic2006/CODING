#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double ans;

void dfs(int cur, int prev, vector<vector<int>>& adj, double prob, int pathLength)
{
    if(adj[cur].size() == 1 && cur != 1){
        //process path
        // cout << "PROCESSING" << prob << " " << pathLength << endl;
        ans += prob*pathLength;
        return;
    }
    // cout << "TRYING ALL PATHS" << endl;
    int groupSize = adj[cur].size();
    if(cur != 1) groupSize--;
    for(auto& next : adj[cur]){
        if(next != prev) dfs(next, cur, adj, prob/groupSize, pathLength+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("journey.in", "r", stdin);

    int n; cin >> n;
    vector<vector<int>> adj(n+1, vector<int>());
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // cout << "CHECK" << endl;

    ans = 0.0;
    dfs(1, 0, adj, 1.0, 0);
    cout << fixed << setprecision(7) << ans << endl;
}