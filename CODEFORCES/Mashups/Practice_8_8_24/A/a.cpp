#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("a.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        if(k%2 == 1){
            cout << "NO" << endl;
            continue;
        }

        ll maxAns = 0;
        for(ll i=1; i<=n; i++){
            maxAns += abs(i - (n+1-i));
        }

        if(k > maxAns){
            cout << "NO" << endl;
            continue;
        }

        vector<ll> nums(n+1,0);
        bool valid = false;
        for(ll i=1; i<=n/2; i++){
            ll term = 2*abs(i - (n+1-i));
            if(k >= term){
                k -= term;
                nums[i] = n+1-i;
                nums[n+1-i] = i;
            }
            else if(k >= term-2){
                k -= (term-2);
                nums[i] = n-i;
                nums[n-i] = i;
            }
            if(k == 0){
                valid = true;
                break;
            }
        }
        if(!valid && k > 0) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            for(ll i=1; i<=n; i++) if(nums[i] == 0) nums[i] = i;
            for(ll i=1; i<=n; i++) cout << nums[i] << " ";
            cout << endl;
        }
    }
}