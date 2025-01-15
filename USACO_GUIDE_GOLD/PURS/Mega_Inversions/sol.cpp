#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct SegTree
{
    ll unit = 0;
    ll f(ll a, ll b){return (a+b);}
    vector<ll> s; ll n;

    SegTree(ll n=0): s(2*n, unit), n(n){}

    void update(ll pos, ll val){
        for(s[pos+=n]+=val; pos/=2;){
            s[pos] = f(s[pos*2], s[pos*2+1]);
        }
    }

    ll query(ll b, ll e){
        ll ra = unit, rb=  unit;
        for(b+=n, e+=n; b<e; b/=2, e/=2){
            if(b%2) ra = f(ra, s[b++]);
            if(e%2) rb =  f(s[--e], rb);
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
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin >> a[i];

    ll ans = 0;
    SegTree invTree(n+1);
    SegTree ansTree(n+1);
    for(ll i=0; i<n; i++){
        ll curInvs = invTree.query(a[i]+1, n+1);
        invTree.update(a[i], 1);
        
        ans += ansTree.query(a[i]+1, n+1);
        ansTree.update(a[i], curInvs);
    }
    cout << ans << endl;
}