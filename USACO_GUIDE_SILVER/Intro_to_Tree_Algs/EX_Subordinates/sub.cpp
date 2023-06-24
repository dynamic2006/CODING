#include <bits/stdc++.h>
using namespace std;

int n;
map<int, vector<int>> adj;
vector<int> subordinates;

void dfs(int cur){
    for(auto next : adj[cur]){
        subordinates[cur]++;
        dfs(next);
        subordinates[cur] += subordinates[next];
    }
}

int main(){
    //freopen("sub.in" , "r" , stdin);

    cin >> n;
    subordinates.resize(n+1);
    int parent;
    for(int i=2; i<=n; i++){
        cin >> parent;
        adj[parent].push_back(i); 
    }

    dfs(1);
    for(int i=1; i<=n; i++){
        cout << subordinates[i] << " ";
    }
    cout << endl; return 0;

}