#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int total = 0 , n , m;
bool rooms[MAXN+2][MAXN+2] , visited[MAXN+2][MAXN+2];
map<pair<int , int> , set<pair<int , int>>> adj;

void floodfill(int startX, int startY){

    if(startX < 1 || startX > n || startY < 1 || startY > n) return;

    visited[startX][startY] = true;

    for(auto next : adj[make_pair(startX , startY)]){
        if(!rooms[next.first][next.second]){
            rooms[next.first][next.second] = true; total++;
            //cout << next.first << " " << next.second << " " << total << endl;
        }
    }
    
    if(rooms[startX-1][startY] && !visited[startX-1][startY]) floodfill(startX-1 , startY);
    if(rooms[startX+1][startY] && !visited[startX+1][startY]) floodfill(startX+1 , startY);
    if(rooms[startX][startY-1] && !visited[startX][startY-1]) floodfill(startX , startY-1);
    if(rooms[startX][startY+1] && !visited[startX][startY+1]) floodfill(startX , startY+1);

    //cout << endl;

    for(auto cur : adj[make_pair(startX , startY)]){
        if(visited[cur.first-1][cur.second] || visited[cur.first+1][cur.second] ||
        visited[cur.first][cur.second-1] || visited[cur.first][cur.second+1]){
            if(!visited[cur.first][cur.second]){
                //cout << "FLOODING FROM: " << cur.first << " " << cur.second << endl;
                floodfill(cur.first , cur.second);
            }
        }
        //else cout << "REJECTING FLOOD FROM: " << cur.first << " " << cur.second << endl;
    }

}

int main(){

    freopen("lightson.in" , "r" , stdin);
    freopen("lightson.out" , "w" , stdout);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y, a, b; cin >> x >> y >> a >> b;
        adj[make_pair(x,y)].insert(make_pair(a,b));
    }

    rooms[1][1] = true; total++;
    //cout << "CHECKPOINT" << endl;
    floodfill(1,1);

    cout << total << endl; return 0;

}