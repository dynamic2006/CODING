#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<vector<int>> adj;
vector<int> colors;
bool valid;

void dfs(int cur, int color)
{
    colors[cur] = color;
    // cout << "processing " << cur << " with color " << color << endl;
    // cout << cur << " has neighbors ";
    // for(auto &next : adj[cur]) cout << next << " ";
    // cout << endl << endl;
    for(auto &next : adj[cur]){
        if(colors[next] == color){
            valid = false;
        }
        else if(colors[next] != -1) continue;
        else{
            // cout << next << " will be colored." << endl;
            if(color == 1) dfs(next, 2);
            else dfs(next, 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("teams.in", "r", stdin);

    cin >> n >> m;
    adj = vector<vector<int>>(n+1, vector<int>());
    colors = vector<int>(n+1, -1);

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //dfs because graph can be disjoint
    valid = true;
    for(int i=1; i<=n; i++){
        if(colors[i] == -1) dfs(i, 1);
        if(!valid) break;
    }

    // cout << "CHECKPOINT" << endl;

    if(!valid) cout << "IMPOSSIBLE" << endl;
    else{
        for(int i=1; i<=n; i++) cout << max(1, colors[i]) << " ";
        cout << endl;
    }

}