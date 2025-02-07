#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Segtree
{
    static constexpr ll unit = 0;
    ll f(ll a, ll b){return a+b;}

    vector<ll> s; ll n;
    Segtree(ll n=0, ll def = unit): s(2*n, def), n(n){}

    void update(ll pos, ll val){
        for(s[pos+=n]=val; pos/=2;){
            s[pos] = f(s[pos*2], s[pos*2 + 1]);
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

ll timer;
vector<pair<ll, ll>> times;

void dfs(ll cur, ll prev, vector<ll>& values, vector<vector<ll>>& adj, Segtree& seg)
{
    times[cur].first = timer++;
    seg.update(times[cur].first, values[cur]);
    for(auto& next : adj[cur]){
        if(next == prev) continue;
        dfs(next, cur, values, adj, seg);
    }
    times[cur].second = timer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    ll n, q; cin >> n >> q;
    vector<ll> values(n);
    vector<vector<ll>> adj(n, vector<ll>());
    for(ll i=0; i<n; i++) cin >> values[i];
    for(ll i=0; i<n-1; i++){
        ll a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    Segtree segtree(n);
    for(ll i=0; i<n; i++) segtree.update(i, values[i]);

    timer = 0;
    times.resize(n);
    dfs(0, -1, values, adj, segtree);

    for(ll i=0; i<q; i++){
        ll op; cin >> op;
        ll s, x;
        switch(op){
            case 1:
                cin >> s >> x; s--;
                segtree.update(times[s].first, x);
                break;
            case 2:
                cin >> s; s--;
                cout << segtree.query(times[s].first, times[s].second) << endl;
                break;
        }
    }
}
//ideas
//two methods
//first method -- preorder traversal + segtree
//second method -- euler tour + segtree
//for this problem both can basically be done the same way
//but this solution will use more of a euler tour method with time var tracker