#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("c.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, a, b; cin >> n >> a >> b;
        vector<ll> c(n);
        for(int i=0; i<n; i++) cin >> c[i];
        sort(c.begin(), c.end());
        
        ll GCD = __gcd(a, b);
        set<ll> uniqueRems;
        for(int i=0; i<n; i++){
            uniqueRems.insert(c[i] % GCD);
        }
        ll ans = *prev(uniqueRems.end()) - *uniqueRems.begin();

        // cout << "GOOD" << endl;

        auto it = uniqueRems.begin();
        int counter = 0;
        while(next(it) != uniqueRems.end()){
            ans = min(ans, *it + GCD - *next(it));
            it++;
            // cout << "IN LOOP" << endl;
            // counter++;
            // if(counter > 100) break;
        }
        cout << ans << endl;
    }
}