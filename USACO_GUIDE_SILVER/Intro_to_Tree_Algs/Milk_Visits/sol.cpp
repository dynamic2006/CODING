#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void dfs(int cur, vector<vector<int>>& adj, vector<int>& comp, char type, int curComp, string& cows)
{
    comp[cur] = curComp;
    for(auto& next : adj[cur]){
        if(cows[next-1] != type || comp[next] != -1) continue;
        dfs(next, adj, comp, type, curComp, cows);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out" , "w" , stdout);
    //compress graph into alternating pattern conn. comps.
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<vector<int>> adj(n+1, vector<int>());
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //compress graph
    int curComp = 0;
    vector<int> comp(n+1, -1);
    for(int i=1; i<=n; i++){
        if(comp[i] == -1){
            curComp++;
            dfs(i, adj, comp, s[i-1], curComp, s);
        }
    }

    //queries
    
    for(int i=0; i<m; i++){
        int a, b; char space, type;
        cin >> a >> b;
        cin >> type;
        // cout << a << " " << b << " TYPE " << type << endl;
        if(comp[a] == comp[b] && s[a-1] != type) cout << '0';
        else cout << '1';
    }
    cout << endl;
}