#include <bits/stdc++.h>
using namespace std;

int n , m; bool works = true;
map<int , vector<int>> adj;
vector<bool> visited;
//let false mean team1, and true mean team2
vector<bool> color;

void dfs(int node , bool team){
    if(visited[node] && color[node] != team){
        works = false; return;
    }
    if(visited[node]) return;
    visited[node] = true;
    color[node] = team;
    for(auto next : adj[node]) dfs(next , !team);

}

int main(){
    //freopen("teams.in" , "r" , stdin);

    cin >> n >> m;
    visited.resize(n+1);
    color.resize(n+1);

    int a , b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //if each connected component of the graph is bipartite
    //we can line up all the components and connect them together
    //link one node of color a of each graph together
    //link one node of color b of each graph together
    //this creates two teams, colored a and b that satisfy the constraints
    for(int i=1; i<=n && works; i++)
        if(!visited[i]) dfs(i , false);
    
    if(works){
        for(int i=1; i<=n; i++){
            cout << color[i] + 1 << " ";
        }
        cout << endl; return 0;
    }

    cout << "IMPOSSIBLE" << endl;
}