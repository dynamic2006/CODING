#include <bits/stdc++.h>
using namespace std;

int n , m; bool works = true;
map<int , vector<pair<int , string>>> adj;
vector<bool> visited , state;

void dfs(int node , bool type){
    if(visited[node] && state[node] != type){
        works = false; return;
    }
    if(visited[node]) return;

    visited[node] = true;
    state[node] = type;

    for(auto next : adj[node]){
        if(next.second == "S") dfs(next.first , type);
        else dfs(next.first , !type);
    }
}

int main(){
    freopen("revegetate.in" , "r" , stdin);
    freopen("revegetate.out" , "w" , stdout);

    cin >> n >> m;
    visited.resize(n+1);
    state.resize(n+1);

    int a , b; string type;
    for(int i=0; i<m; i++){
        cin >> type >> a >> b;
        adj[a].push_back(make_pair(b , type));
        adj[b].push_back(make_pair(a , type));
    }

    int totalComponents = 0;
    for(int i=1; i<=n && works; i++){
        if(!visited[i]){
            dfs(i , true);
            totalComponents++;
        }
    }

    if(works){
        cout << "1";
        for(int i=0; i<totalComponents; i++) cout << "0";
        cout << endl;
    }
    else cout << "0" << endl;

    return 0;

}