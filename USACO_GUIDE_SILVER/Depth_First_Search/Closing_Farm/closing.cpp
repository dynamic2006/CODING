#include <bits/stdc++.h>
using namespace std;

int n , m , reachableNodes = 0;

vector<int> closingOrder;
vector<bool> closed;
vector<bool> visited;
map<int , vector<int>> adj;

void dfs(int node){
    //if the barn is closed, end the dfs
    if(closed[node]) return;

    visited[node] = true;
    reachableNodes++;
    for(auto x : adj[node])
        if(!visited[x]) dfs(x);
}

int main(){
    freopen("closing.in" , "r" , stdin);
    freopen("closing.out" , "w" , stdout);

    cin >> n >> m;
    visited.resize(n+1);
    closed.resize(n+1);
    closingOrder.resize(n+1);

    int barnOne , barnTwo;
    for(int i=0; i<m; i++){
        cin >> barnOne >> barnTwo;
        adj[barnOne].push_back(barnTwo);
        adj[barnTwo].push_back(barnOne);
    }

    for(int i=1; i<=n; i++){
        closed[i] = false;
        cin >> closingOrder[i];
    }

    //determine intial state before any barns are closed
    dfs(1);
    if(reachableNodes == n) cout << "YES" << endl;
    else cout << "NO" << endl;

    //note we don't care about processing the very last closed barn
    for(int i=1; i<n; i++){
        reachableNodes = 0;
        closed[closingOrder[i]] = true;
        fill(visited.begin() , visited.end() , false);

        //start dfs with the final barn to close
        //if this barn can get to any other barn, the graph is connected
        dfs(closingOrder[n]);
        if(reachableNodes == n - i) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }

}