#include <bits/stdc++.h>
using namespace std;

struct Cow{
    int id , xPos , yPos , radius;
};

int n , maxReach = 0 , nodes = 0;
vector<bool> visited;
vector<Cow> cows;
//value is a vector of all cows that key cow can transmit to
map<int , vector<Cow>> adj;

void connect(Cow& a , Cow& b){
    double xDist = (a.xPos - b.xPos)*(a.xPos - b.xPos);
    double yDist = (a.yPos - b.yPos)*(a.yPos - b.yPos);
    //if cow a can transmit to cow b
    if(a.radius*a.radius >= xDist + yDist) adj[a.id].push_back(b);
    //if cow b can transmit to cow a
    if(b.radius*b.radius >= xDist + yDist) adj[b.id].push_back(a);
}

void dfs(Cow& c){
    if(visited[c.id]) return;
    visited[c.id] = true; nodes++;
    for(auto k : adj[c.id]) dfs(k);
}

int main(){
    freopen("moocast.in" , "r" , stdin);
    freopen("moocast.out" , "w" , stdout);

    cin >> n;
    cows.resize(n+1); visited.resize(n+1);
    for(int i=1; i<=n; i++){
        //fill cows vector
        cows[i].id = i;
        cin >> cows[i].xPos >> cows[i].yPos >> cows[i].radius;
        //fill adj list
        for(int j=i-1; j>0; j--)
            connect(cows[i] , cows[j]);
    }

    //dfs over all cows and keep updating maxReach
    for(Cow& cow : cows){
        fill(visited.begin() , visited.end() , false);
        nodes = 0;
        dfs(cow);
        maxReach = max(maxReach , nodes);
    }

    cout << maxReach << endl;

}