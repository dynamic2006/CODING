#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge
{
    Edge(){
        dest = -1;
        weight = -1;
    }
    Edge(int x, int y){
        dest = x;
        weight = y;
    }
    int dest;
    int weight;
};

int dfs(int cur, int prev, vector<vector<Edge>>& adj, int minWeight)
{
    int tot = 0;
    for(auto& next : adj[cur]){
        if(next.dest == prev || next.weight < minWeight) continue;
        tot++;
        tot += dfs(next.dest, cur, adj, min(minWeight, next.weight));
    }
    return tot;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in" , "r" , stdin);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out" , "w" , stdout);

    int n, q; cin >> n >> q;
    vector<vector<Edge>> adj(n+1, vector<Edge>());

    for(int i=0; i<n-1; i++){
        int p, q, r; cin >> p >> q >> r;
        adj[p].push_back(Edge(q, r));
        adj[q].push_back(Edge(p, r));
    }

    for(int i=0; i<q; i++){
        int k, v; cin >> k >> v;
        cout << dfs(v, 0, adj, k) << endl;
    }

}