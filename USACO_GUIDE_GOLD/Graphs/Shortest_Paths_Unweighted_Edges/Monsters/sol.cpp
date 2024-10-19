#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int n, m;
vector<string> grid;
vector<vector<pair<bool, bool>>> vis;
vector<queue<pair<int, int>>> qs;
vector<vector<pair<pair<int, int>, char>>> parents;
vector<vector<bool>> inABFS;
 
void floodfill(char c, int previ, int prevj, int di, int dj, int qi, bool pathA)
{
    int i = previ + di, j = prevj + dj;
    if(i>=0 && i<n && j>=0 && j<m && !vis[i][j].first && grid[i][j] == '.'){
        parents[i][j] = {{previ, prevj}, c};
        qs[qi].push({i,j});
        vis[i][j].first = true;
        vis[i][j].second = pathA;
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("input.in", "r", stdin);
 
    //bfs from A to all exits
    //build full bfs tree first
    //note that you need to check if A->...->Exit->...M->...
    //so bfs for monsters as well -- track vis cells so only traversed once
    //at end, traverse bfs tree for A and find exit if possible
 
    // cout << "CHECKPOITN PLES DON BREAK =D" << endl;
 
    cin >> n >> m;
    grid = vector<string>(n);
    vis = vector<vector<pair<bool, bool>>>(n, vector<pair<bool, bool>>(m, {false, false}));
    parents = vector<vector<pair<pair<int, int>, char>>>(n, vector<pair<pair<int, int>, char>>(m, {{-1,-1}, 'X'}));
    for(int i=0; i<n; i++) cin >> grid[i];
 
    // cout << "CHECKPOITN PLES DON BREAK =D" << endl;
 
    //find each monster M
    qs = vector<queue<pair<int, int>>>();
 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 'M'){
                queue<pair<int, int>> q; q.push({i,j});
                qs.push_back(q);
            }
        }
    }
 
    //find A
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 'A'){
                queue<pair<int, int>> q; q.push({i,j});
                qs.push_back(q);
            }
        }
    }
 
    // for(int i=0; i<qs.size(); i++){
    //     cout << i << " " << qs[i].size() << endl;
    // }
 
    // cout << "CHECKPOITN PLES DON BREAK =D" << endl;
 
    //qs are ordered by all monsters first, then A at end
    //bfs for each q while not all are empty
    int emptyQs = 0;
    while(emptyQs != qs.size()){
        emptyQs = 0;
        for(int qi=0; qi<qs.size(); qi++){
            //floodfill in all four directions
            //no bfs tree can use cells visited previously by other bfs
            if(qs[qi].empty()){
                emptyQs++;
                continue;
            }
            int curQsize = qs[qi].size();
            for(int li = 0; li<curQsize; li++){
                pair<int, int> cur = qs[qi].front(); qs[qi].pop();
                int i = cur.first, j = cur.second;
                bool pathA = false;
                if(qi == qs.size() - 1) pathA = true;
                vis[i][j].first = true;
                // cout << "BEFORE FLOODFILL" << endl;
                floodfill('U', i, j, -1, 0, qi, pathA);
                floodfill('D', i, j, 1, 0, qi, pathA);
                floodfill('L', i, j, 0, -1, qi, pathA);
                floodfill('R', i, j, 0, 1, qi, pathA);
            }
            // cout << "AFTER FLOODFILL" << endl;
 
            // if(qs[qi].empty()) emptyQs++;
            // cout << qs[qi].size() << endl;
        }
        // cout << emptyQs << endl;
    }
 
    // cout << "CHECKPOITN PLES DON BREAK =D" << endl;
 
    //for each exit space (~4*1000) check if it is in A's bfs tree
    //if it is, backtrack and print out path
 
    int ei = -1, ej = -1;
    for(int i=0; i<n; i++){
        if(vis[i][0].second || grid[i][0] == 'A'){
            ei = i; ej = 0;
        }
        else if(vis[i][m-1].second || grid[i][m-1] == 'A'){
            ei = i; ej = m-1;
        }
    }
    for(int j=0; j<m; j++){
        if(vis[0][j].second || grid[0][j] == 'a'){
            ei = 0; ej = j;
        }
        else if(vis[n-1][j].second || grid[n-1][j] == 'A'){
            ei = n-1; ej = j;
        }
    }
 
    if(ei == -1) cout << "NO" << endl;
    else{
        //backtrack from ei, ej
        stack<char> path;
        while(parents[ei][ej].second != 'X'){
            path.push(parents[ei][ej].second);
            int tempi = parents[ei][ej].first.first;
            int tempj = parents[ei][ej].first.second;
            ei = tempi; ej = tempj;
        }
        cout << "YES" << endl;
        cout << path.size() << endl;
        while(!path.empty()){
            cout << path.top();
            path.pop();
        }
        cout << endl;
    }
}

//NOTE
//code breaks with "RUNTIME ERROR" on two test cases
//tested both on local machine -- works but takes a long time
//problem likely with processing 10^6 queues when number of monsters is large
//potential fix by immediately erasing queues when found that they are empty
