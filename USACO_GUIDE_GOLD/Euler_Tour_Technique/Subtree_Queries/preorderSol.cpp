#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Segtree
{
    static constexpr int unit = 0;
    int f(int a, int b){return a+b;}

    vector<int> s; int n;
    Segtree(int n=0, int def=unit):s(2*n, def), n(n){}

    void update(int pos, int val){
        for(s[pos+=n]=val; pos/=2;){
            s[pos] = f(s[pos*2], s[pos*2+1]);
        }
    }

    int query(int b, int e){
        int ra = unit, rb = unit;
        for(b+=n, e+=n; b<e; b/=2, e/=2){
            if(b%2) ra = f(ra, s[b++]);
            if(e%2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void dfs(int cur, int prev, vector<vector<int>>& adj, vector<pair<int, int>>& times, vector<int>& preorder)
{
    times[cur].first = preorder.size();
    preorder.push_back(cur);
    for(auto& next : adj[cur]){
        if(next == prev) continue;
        dfs(next, cur, adj, times, preorder);
    }
    times[cur].second = preorder.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    int n, q; cin >> n >> q;
    vector<int> values(n);
    for(int i=0; i<n; i++) cin >> values[i];

    vector<vector<int>> adj(n, vector<int>());
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //preorder trav
    Segtree seg(n);
    vector<pair<int, int>> times(n);
    vector<int> preorder;
    dfs(0, -1, adj, times, preorder);

    //DEBUGGING
    // for(int i=0; i<n; i++){
    //     cout << i <<  " " << times[i].first << " " << times[i].second << endl;
    // }

    //times array is filled
    //now init segtree
    for(int i=0; i<n; i++){
        seg.update(i, values[preorder[i]]);
    }

    map<int, int> comp;
    for(int i=0; i<n; i++) comp[preorder[i]] = i;

    //answer queries
    for(int i=0; i<q; i++){
        int op; cin >> op;
        int s, x;
        switch(op){
            case 1:
                cin >> s >> x; s--;
                seg.update(comp[s], x);
                break;
            case 2:
                cin >> s; s--;
                cout << seg.query(comp[s], times[s].second) << endl;
                break;
        }
    }
}
//will use preorder traversal for this solution
//only difference really is using the size of the preorder array
//instead of a timer to determine start and end