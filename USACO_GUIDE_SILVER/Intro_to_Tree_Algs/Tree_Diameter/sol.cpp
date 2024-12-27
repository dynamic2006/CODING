#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dfs(int cur, int prev, vector<vector<int>>& adj, vector<int>& maxToLeaf, vector<int>& ans)
{
    if(adj.size() == 1 && prev != 0) return 1;
    
    int max1 = -1, max2 = -1;
    for(auto &next : adj[cur]){
        if(next != prev){
            int nextMaxToLeaf = dfs(next, cur, adj, maxToLeaf, ans);
            maxToLeaf[cur] = max(maxToLeaf[cur], 1 + nextMaxToLeaf);

            if(max1 == -1) max1 = nextMaxToLeaf;
            else if(max2 == -1) max2 = nextMaxToLeaf;
            else{
                if(max1 < max2) swap(max1, max2);
                if(nextMaxToLeaf > max2){
                    max2 = max1;
                    if(nextMaxToLeaf > max1) max1 = nextMaxToLeaf;
                    else max2 = nextMaxToLeaf;
                }
            }
        }
    }
    if(max2 == -1) ans[cur] = maxToLeaf[cur];
    else ans[cur] = 2 + max1 + max2;

    return maxToLeaf[cur];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;

    vector<vector<int>> adj(n+1, vector<int>());
    vector<int> maxToLeaf(n+1, 0);
    vector<int> ans(n+1, 0);

    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, adj, maxToLeaf, ans);

    int maxAns = 0;
    for(int i=1; i<=n; i++){
        maxAns = max(maxAns, ans[i]);
    }
    cout << maxAns << endl;
}