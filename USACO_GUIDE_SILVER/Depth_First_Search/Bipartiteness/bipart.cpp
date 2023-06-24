#include <bits/stdc++.h>
using namespace std;

int n; long long state[2] = {0 , 0};
map<int , vector<int>> adj;
vector<bool> visited;

void dfs(int node , bool colored){
    if(visited[node]) return;
    visited[node] = true;
    state[colored]++;
    for(auto next : adj[node]) dfs(next , !colored);
}

int main(){
    //freopen("bipart.in" , "r" , stdin);

    cin >> n;
    visited.resize(n+1);

    int a , b;
    for(int i=1; i<=n; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1 , false);

    cout << state[0] * state[1] - (n-1) << endl;

}