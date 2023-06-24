#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
double val = 0;
vector<vector<int>> adj(MAXN+1);

void dfs(int cur, int prev, int len, double d){
    //cout << len << " " << d << endl;
    if(adj[cur].size() == 1){
        val += len*d; return;
    }
    for(auto next : adj[cur]){
        if(next != prev) dfs(next, cur, len+1, d/(adj[cur].size()-1));
    }
}

int main(){
    
    //freopen("journey.in" , "r" , stdin);
    //freopen("journey.out" , "w" , stdout);

    int n; cin >> n;
    for(int i=1; i<n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(auto node : adj[1]){
        dfs(node, 1, 1, (double)1/adj[1].size());
    }

    cout << setprecision(7) << val << endl;
    return 0;

}