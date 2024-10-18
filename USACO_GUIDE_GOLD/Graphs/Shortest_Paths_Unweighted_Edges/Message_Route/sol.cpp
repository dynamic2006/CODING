#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> parents;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    cin >> n >> m;
    adj = vector<vector<int>>(n+1, vector<int>());
    vis = vector<bool>(n+1, false);
    parents = vector<int>(n+1, -1);
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //bfs and track path length
    //keep track of first encountered parent
    //then backtrack thru parents to get shortest path

    queue<int> q; q.push(1);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        vis[cur] = true;
        for(auto &next : adj[cur]){
            if(vis[next]) continue;
            parents[next] = cur;
            q.push(next);
            vis[next] = true;
        }
    }

    // for(int i=0; i<=n; i++){
    //     cout << i << " " << parents[i] << endl;
    // }

    if(parents[n] == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> path = {n};
    int curNum = n;
    while(parents[curNum] > 0){
        curNum = parents[curNum];
        path.push_back(curNum);
    }
    cout << path.size() << endl;;
    for(int i=path.size()-1; i>=0; i--){
        cout << path[i] << " ";
    }
    cout << endl;
    
}