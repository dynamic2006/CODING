#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int tot;

void ccDFS(vector<set<int>>& g, vector<int>& cc, vector<bool>& vis, int head, int cur)
{
    vis[cur] = true;
    cc[cur] = head;
    for(auto &next : g[cur]) if(!vis[next]) ccDFS(g, cc, vis, head, next);
    
}

void dfs(vector<set<int>>& g, vector<int>& cc, vector<bool>& vis, int cur)
{
    vis[cur] = true;
    vector<int> backtrack;
    for(auto &next : g[cur]){
        if(cc[next] != cc[cur]){
            g[next].erase(cur);
            backtrack.push_back(next);
        }
        if(!vis[next]) dfs(g, cc, vis, next);
    }
    for(auto &x : backtrack){
        g[cur].erase(x);
        tot++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        tot = 0;
        int n, m1, m2; cin >> n >> m1 >> m2;

        vector<set<int>> g1(n+1, set<int>()), g2(n+1, set<int>());

        for(int i=0; i<m1; i++){
            int a, b; cin >> a >> b;
            g1[a].insert(b);
            g1[b].insert(a);
        }
        for(int i=0; i<m2; i++){
            int a, b; cin >> a >> b;
            g2[a].insert(b);
            g2[b].insert(a);
        }

        vector<bool> vis(n+1, false), vis1(n+1, false), vis2(n+1, false);
        vector<int> cc1(n+1, 0), cc2(n+1, 0);

        for(int i=1; i<=n; i++) if(!vis2[i]) ccDFS(g2, cc2, vis2, i, i);

        for(int i=1; i<=n; i++) if(!vis[i]) dfs(g1, cc2, vis, i);

        for(int i=1; i<=n; i++) if(!vis1[i]) ccDFS(g1, cc1, vis1, i, i);

        for(int i=1; i<=n; i++){
            if(cc2[i] != cc1[i]) tot++;
        }
        cout << tot << endl;
    }
}