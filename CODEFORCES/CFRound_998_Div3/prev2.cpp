#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int tot;

void eraseDFS(vector<set<int>>& proto, vector<set<int>>& ref, vector<bool>& vis, int cur)
{
    vis[cur] = true;
    for(auto &x : proto[cur]){
        if(!ref[cur].count(x)){
            proto[x].erase(cur);
            tot++;
        }
    }

    for(auto &next : ref[cur]){
        if(!vis[next]) eraseDFS(proto, ref, vis, next);
    }
}

void addDFS(vector<set<int>>& proto, vector<set<int>>& ref, vector<bool>& vis, int cur)
{
    vis[cur] = true;
    for(auto &x : ref[cur]){
        if(!proto[cur].count(x)){
            proto[x].insert(cur);
            tot++;
        }
    }

    for(auto &next : proto[cur]){
        if(!vis[next]) addDFS(proto, ref, vis, next);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

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

        vector<bool> vis1(n+1, false), vis2(n+1, false);


        for(int i=1; i<=n; i++) if(!vis1[i]) eraseDFS(g1, g2, vis1, i);
        for(int i=1; i<=n; i++) if(!vis2[i]) addDFS(g1, g2, vis2, i);
        cout << tot << endl;
    }
}