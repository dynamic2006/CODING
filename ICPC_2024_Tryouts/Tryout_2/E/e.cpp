#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<int> debts;
vector<vector<int>> adj;
vector<bool> vis;
bool valid;
int compSum;

void dfs(int i)
{
    if(vis[i]) return;
    vis[i] = true;

    compSum += debts[i];
    for(auto &next : adj[i]){
        if(!vis[next]) dfs(next);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    cin >> n >> m;
    debts = vector<int>(n);
    adj = vector<vector<int>>(n, vector<int>());
    vis = vector<bool>(n, false);
    valid = true;

    for(int i=0; i<n; i++) cin >> debts[i];

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // cout << "CHECK" << endl;

    //check if each connected component sums to zero
    for(int i=0; i<n; i++){
        // cout << "CHECK2" << endl;
        if(!vis[i]){
            compSum = 0;
            // cout << "CHECK3" << endl;
            dfs(i);
            // cout << "CHECK4" << endl;
            if(compSum != 0) valid = false;
        }
    }

    if(valid) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;


}