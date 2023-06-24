#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000, MAXR = 1e9;

vector<vector<pair<int, int>>> adj(MAXN+1);
int ans = 0, k, v;

void dfs(int cur, int prev){
    ans++;
    for(auto next : adj[cur]){
        if(next.first != prev && next.second >= k) dfs(next.first, cur);
    }
}

int main(){

    freopen("mootube.in" , "r" , stdin);
    freopen("mootube.out" , "w" , stdout);

    int n, q; cin >> n >> q;
    for(int i=1; i<n; i++){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    for(int i=0; i<q; i++){
        cin >> k >> v;
        ans = 0;
        dfs(v, 0);
        cout << ans-1 << endl;
    }
    
}