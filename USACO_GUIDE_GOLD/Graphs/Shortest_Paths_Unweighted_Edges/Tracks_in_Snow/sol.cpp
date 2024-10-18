#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int h, w;
vector<string> grid;
vector<vector<bool>> vis;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    cin >> h >> w;
    grid = vector<string>(h);
    vis = vector<vector<bool>>(h, vector<bool>(w, false));
    for(int i=0; i<h; i++){
        cin >> grid[i];
    }

    //bfs tree with connected components
    //ans is depth of the tree
    //can treat as edges with 0 weight to same component
    //1 weight to edge to diff component
    //use a kind of floodfill with bfs for the edges

    deque<pair<int, int>> dq; dq.push_front({0,0});
    char type = grid[0][0]; vis[0][0] = true;
    int ans = 1;
    while(!dq.empty()){
        //floodfill bfs
        pair<int, int> cur = dq.front(); dq.pop_front();
        if(grid[cur.first][cur.second] != type){
            ans++;
            type = grid[cur.first][cur.second];
        }
        // cout << "CHECK" << endl;
        for(int i=cur.first-1; i<=cur.first+1; i++){
            if(i<0 || i>=h) continue;
            // cout << "cHECKPINTS" << endl;
            for(int j=cur.second-1; j<=cur.second+1; j++){
                if(j<0 || j>=w) continue;
                // cout << "testing " << i << " " << j << " with type " << grid[i][j] << endl;
                if(vis[i][j] == true || grid[i][j] == '.' || abs((cur.first + cur.second) - (i+j)) != 1){
                    // cout << vis[i][j] << " " << grid[i][j] << " " << abs((cur.first+cur.second) - (i+j)) << endl;
                    continue;
                }
                else if(grid[i][j] != type){
                    dq.push_back({i, j});
                    // cout << "pushing to back" << endl;
                }
                else{
                    dq.push_front({i,j});
                    // cout << "pushing to front" << endl;
                }
                vis[i][j] = true;
            }
        }
    }
    cout << ans << endl;



    
}