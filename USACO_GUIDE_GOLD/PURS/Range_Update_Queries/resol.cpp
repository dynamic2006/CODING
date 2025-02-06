#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct SegTree
{
    static constexpr ll unit = 0;
    ll f(ll a, ll b){return a+b;}
    vector<ll> s; ll n;

    SegTree(ll n=0, ll def = unit): s(2*n, def), n(n){}

    void update(ll pos, ll val){
        for(s[pos+=n]+=val; pos/=2;){
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    ll n, q; cin >> n >> q;

    vector<ll> nums(n);
    for(ll i=0; i<n; i++) cin >> nums[i];
    
    SegTree segtree(n+1);
    for(ll i=0; i<q; i++){
        ll op; cin >> op;
        switch (op){
            case 1:
                ll a, b, u; cin >> a >> b >> u;
                a--; b--;
                segtree.update(a, u);
                segtree.update(b+1, -u);
                break;
            case 2:
                ll k; cin >> k;
                ll totDiff = segtree.query(0, k);
                cout << nums[k-1] + totDiff << endl;
                break;
        }
    }
}