#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Segtree
{
    static constexpr ll unit = 0;
    ll f(ll a, ll b){return a+b;}

    vector<ll> s; ll n;
    Segtree(ll n=0, ll def=unit):s(2*n, def), n(n){}

    void update(ll pos, ll val){
        for(s[pos+=n]=val; pos/=2;){
            s[pos] = f(s[pos*2], s[pos*2+1]);
        }
    }

    ll query(ll b, ll e){
        ll ra = unit, rb = unit;
        for(b+=n, e+=n; b<e; b/=2, e/=2){
            if(b%2) ra = f(ra, s[b++]);
            if(e%2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void dfs(ll cur, ll prev, vector<vector<ll>>& adj, vector<ll>& times, vector<ll>& preorder)
{
    preorder.push_back(cur);
    for(auto& next : adj[cur]){
        if(next == prev) continue;
        dfs(next, cur, adj, times, preorder);
    }
    times[cur] = preorder.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    ll n, q; cin >> n >> q;
    vector<ll> values(n);
    for(ll i=0; i<n; i++) cin >> values[i];

    vector<vector<ll>> adj(n, vector<ll>());
    for(ll i=0; i<n-1; i++){
        ll a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //preorder trav
    Segtree seg(n);
    vector<ll> times(n);
    vector<ll> preorder;
    dfs(0, -1, adj, times, preorder);

    //DEBUGGING
    // for(ll i=0; i<n; i++){
    //     cout << i <<  " " << times[i].first << " " << times[i].second << endl;
    // }

    //times array is filled
    //now init segtree
    for(ll i=0; i<n; i++){
        seg.update(i, values[preorder[i]]);
    }

    map<ll, ll> comp;
    for(ll i=0; i<n; i++) comp[preorder[i]] = i;

    //answer queries
    for(ll i=0; i<q; i++){
        ll op; cin >> op;
        ll s, x;
        switch(op){
            case 1:
                cin >> s >> x; s--;
                seg.update(comp[s], x);
                break;
            case 2:
                cin >> s; s--;
                cout << seg.query(comp[s], times[s]) << endl;
                break;
        }
    }
}
//will use preorder traversal for this solution
//only difference really is using the size of the preorder array
//instead of a timer to determine start and end