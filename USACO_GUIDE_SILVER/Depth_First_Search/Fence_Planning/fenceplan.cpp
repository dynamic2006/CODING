#include <bits/stdc++.h>
using namespace std;

struct Cow{
    int id , xPos , yPos;
};

int n , m , ans = 10e9;
vector<Cow> cows;
vector<bool> visited;
set<int> cowsToAssign , xCoords , yCoords;
map<int , vector<int>> adj;

void dfs(int c){
    if(visited[c]) return;
    visited[c] = true; 
    cowsToAssign.erase(c);
    //we also want to keep track of the perimeter
    xCoords.insert(cows[c].xPos);
    yCoords.insert(cows[c].yPos);
    for(auto k : adj[c]) dfs(k);
}

int main(){
    freopen("fenceplan.in" , "r" , stdin);
    freopen("fenceplan.out" , "w" , stdout);

    //dfs until all cows have been visited
    //for each dfs this maps out a connects component
    //so over each dfs make a rectangle (struct?)
    //which represents the fence around this connected components
    //keep running minimum perimeter required over all dfs searches

    cin >> n >> m;
    cows.resize(n+1);
    visited.resize(n+1);

    //set up the cows
    for(int i=1; i<=n; i++){
        cowsToAssign.insert(i);
        cows[i].id = i;
        cin >> cows[i].xPos >> cows[i].yPos;
    }

    //set up the adj list
    int a , b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    while(!cowsToAssign.empty()){
        xCoords.clear(); yCoords.clear();
        dfs(*cowsToAssign.begin());
        int perimeter = 2*((*xCoords.rbegin() - *xCoords.begin()) + (*yCoords.rbegin() - *yCoords.begin()));
        ans = min(ans , perimeter);
    }

    cout << ans << endl;

}