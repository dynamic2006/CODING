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
        vector<ll> a(n);

        ll sum = 0;
        for(ll i=0; i<n; i++){
            cin >> a[i];
            sum += a[i];
        }

        ll maxSize = *max_element(a.begin() , a.end());

        for(ll i=n; i>=1; i--){
            //test this as the height
            ll hi = (sum+k)/i;

            if(maxSize <= hi && hi*i >= sum && hi*i <= sum+k){
                cout << i << endl;
                break;
            }
        }
    }

}