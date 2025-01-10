#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct SegTree
{
    typedef ll T;
    static constexpr T unit = 0;
    T f(T a, T b){return (a+b);}

    vector<T> s; int n;
    SegTree(int n=0, T def = unit): s(2*n, def), n(n){}

    void update(int pos, T val){
        for(s[pos+=n] += val; pos/=2;){
            s[pos] = f(s[pos*2], s[pos*2 + 1]);
        }
    }

    T query(int b, int e){
        T ra = unit, rb = unit;
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

    int n, q; cin >> n >> q;
    SegTree segtree(n);

    vector<ll> nums(n, 0);
    for(int i=0; i<n; i++) cin >> nums[i];

    for(int i=0; i<q; i++){
        int op; cin >> op;
        if(op == 1){
            int a, b, u; cin >> a >> b >> u;
            segtree.update(a-1, u);
            if(b < n) segtree.update(b, -u);
        }
        else{
            int k; cin >> k;
            cout << nums[k-1] + segtree.query(0, k) << endl;
        }
    }
}