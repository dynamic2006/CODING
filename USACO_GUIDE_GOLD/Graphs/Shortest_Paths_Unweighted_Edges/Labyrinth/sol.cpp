#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> vis;
vector<vector<pair<pair<int, int>, char>>> parents;

void floodfillBFS(char c, int i, int j, int di, int dj, queue<pair<int, int>>& q)
{
    int nexti = i+di, nextj = j+dj;
    if(nexti>=0 && nexti<n && nextj>=0 && nextj<m){
        if(vis[nexti][nextj] || grid[nexti][nextj] == '#') return;
        vis[nexti][nextj] = true;
        parents[nexti][nextj] = {{i, j}, c};
        q.push({nexti,nextj});
    }
        
}

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    cin >> n >> m;

    //similar to the parents algo
    //process each cell with bfs
    //keep track of where the next cell in bfs is visited from (parent)
    //track with the direction so you can backtrack print the path

    grid = vector<string>(n);
    vis = vector<vector<bool>>(n, vector<bool>(m, false));
    parents = vector<vector<pair<pair<int, int>, char>>>(n, vector<pair<pair<int, int>, char>>(m, {{-1, -1}, 'X'}));
    for(int i=0; i<n; i++) cin >> grid[i];

    //find A
    int ai = -1, aj = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 'A'){
                ai = i;
                aj = j;
                break;
            }
        }
        if(ai != -1) break;
    }

    // cout << "CHECK" << endl;

    //bfs
    queue<pair<int, int>> q; q.push({ai, aj}); vis[ai][aj] = true;
    while(!q.empty()){
        // cout << q.size() << endl;
        pair<int, int> cur = q.front(); q.pop();
        floodfillBFS('U', cur.first, cur.second, -1, 0, q);
        floodfillBFS('D', cur.first, cur.second, 1, 0, q);
        floodfillBFS('L', cur.first, cur.second, 0, -1, q);
        floodfillBFS('R', cur.first, cur.second, 0, 1, q);
    }
    // cout << "CHECK" << endl;

    //find B
    int bi=-1, bj=-1;
    bool foundB = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 'B'){
                bi = i; bj = j;
                foundB = true;
                // cout << "SEARCHING..." << endl;
                break;
            }
        }
        if(foundB) break;
    }

    // cout << "CHECKPOINT" << endl;
    // cout << bi << " " << bj << endl;

    stack<char> path;

    //backtrack to find path
    int i = bi, j = bj;
    while(parents[i][j].second != 'X'){
        // cout << "1" << endl;
        path.push(parents[i][j].second);
        // cout << "2" << endl;
        int tempi, tempj;
        tempi = parents[i][j].first.first;
        tempj = parents[i][j].first.second;
        i = tempi; j = tempj;
        // cout << "BACKTRACK CHECK" << endl;
    }
    if(grid[i][j] != 'A') cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        cout << path.size() << endl;
        while(!path.empty()){
            cout << path.top();
            path.pop();
        }
        cout << endl;
    }

}