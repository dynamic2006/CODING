#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

struct Segtree
{
    static constexpr ll unit = 0;

    ll f(ll a, ll b){return (a+b)%MOD;}

    vector<ll> s; ll n;
    Segtree(ll n=0, ll def=unit): s(2*n, def), n(n){}

    void update(ll pos, ll val){
        for(s[pos+=n]+=(val%MOD), s[pos]%=MOD ; pos/=2;){
            s[pos] = f(s[pos*2], s[pos*2+1]);
        }
    }

    ll query(ll b, ll e){
        ll ra = 0, rb = 0;
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

    ll n; cin >> n;
    map<int, int> comp;
    vector<int> vals(n);
    for(int i=0; i<n; i++) cin >> vals[i];

    vector<int> clean = vals;
    sort(clean.begin(), clean.end());
    clean.erase(unique(clean.begin(), clean.end()), clean.end());
    for(int i=0; i<clean.size(); i++) comp[clean[i]] = i;

    Segtree seg(clean.size());

    ll ans = 0;
    for(ll i=0; i<n; i++){
        ll a = vals[i];
        ll x = seg.query(0, comp[a]); //might be just a if strictly increasing
        //get modpow of 2 raised to x
        x++; x%=MOD;
        //ans += modpow result
        ans += x; ans %= MOD;
        seg.update(comp[a], x%MOD);
    }
    cout << ans << endl;
}