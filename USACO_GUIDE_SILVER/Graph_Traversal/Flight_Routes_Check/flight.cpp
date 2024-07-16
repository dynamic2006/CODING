#include <bits/stdc++.h>
using namespace std;

int n , m;

map<int , vector<int>> givenAdj; //og directed graph
map<int , vector<int>> inverseAdj; //graph with all direction reversed
vector<bool> visited;

void dfs(int node , map<int , vector<int>>& adj){
    if(visited[node]) return;
    visited[node] = true;
    for(auto x : adj[node]) dfs(x , adj);
}

int main(){
    //freopen("flight.in" , "r" , stdin);
    
    cin >> n >> m;
    visited.resize(n+1);
    
    int a , b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        givenAdj[a].push_back(b);
        inverseAdj[b].push_back(a);
    }

    fill(visited.begin() , visited.end() , false);
    dfs(1 , givenAdj);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cout << "NO" << endl << "1 " << i << endl;
            return 0;
        }
    }

    fill(visited.begin() , visited.end() , false);
    dfs(1 , inverseAdj);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cout << "NO" << endl << i << " 1" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;

}