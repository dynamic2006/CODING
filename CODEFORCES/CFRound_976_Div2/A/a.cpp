#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        ll largestPow = 1;
        while(largestPow < n && k > 1) largestPow*=k;
        if(largestPow > n) largestPow/=k;

        ll ans = 0;
        while(n>0){
            ll num = n/largestPow;
            ans += num;
            n -= num*largestPow;
            largestPow/=k;
        }
        cout << ans << endl;
    }
}