#include <bits/stdc++.h>
using namespace std;

int n;
map<int , vector<int>> adj;
vector<bool> visited;

void dfs(int cur){
    if(visited[cur]) return;
    visited[cur] = true;
    for (auto next : adj[cur]) dfs(next);
}

int main(){
    //freopen("forest.in" , "r" , stdin);

    cin >> n;
    visited.resize(n+1);
    int node;
    for(int i=1; i<=n; i++){
        cin >> node;
        adj[i].push_back(node);
        adj[node].push_back(i);
    }

    //find how many trees there are
    //keep a vector of visited nodes
    //loop thru adj and if not visited, start a dfs

    int trees = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
            trees++;
        }
    }

    cout << trees << endl;

}