#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<vector<int>> adj;
vector<int> colors;

bool dfs(int cur, int color)
{
    colors[cur] = color;
    for(auto &next : adj[cur]){
        if(colors[next] != -1){
            if(colors[next] == color) return false;
        }
        else{
            if(color == 1) colors[next] = 2;
            else colors[next] = 1;
            dfs(next, colors[next]);
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("teams.in", "r", stdin);

    cin >> n >> m;
    adj = vector<vector<int>>(n+1, vector<int>());
    colors = vector<int>(n+1, -1);

    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //dfs because graph can be disjoint
    bool valid = true;
    for(int i=1; i<=n; i++){
        if(colors[i] == -1) valid = dfs(i, 1);
        if(!valid) break;
    }

    // cout << "CHECKPOINT" << endl;

    if(!valid) cout << "IMPOSSIBLE" << endl;
    else{
        for(int i=1; i<=n; i++) cout << max(1, colors[i]) << " ";
        cout << endl;
    }

}