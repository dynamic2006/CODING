#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    ll n, k; cin >> n >> k;
    
    if(n > k*k){
        cout << -1 << endl;
        return 0;
    }

    ll x = n/k;
    for(ll i=k; i<=n; i+=k){
        for(ll j=i; j>i-k; j--) cout << j << " ";
    }

    if(x*k == n){
        cout << endl;
        return 0;
    }
    for(ll i=n; i>=x*k+1; i--) cout << i << " ";
    cout << endl;
    

}