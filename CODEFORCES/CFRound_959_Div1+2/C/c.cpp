#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXNUM = 1e9 + 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("c.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        ll n, x; cin >> n >> x;
        vector<ll> a(n+1);
        for(int i=0; i<n; i++) cin >> a[i];
        a[n] = MAXNUM;
        
        vector<ll> resets(n);
        //two ptrs
        int l=0, r=-1;
        ll curTotal = 0;
        while(l<n){
            while(r<=n && curTotal <= x){
                curTotal += a[++r];
            }
            resets[l] = r;
            curTotal -= a[l];
            l++;
        }
        // for(auto r : resets) cout << r << " ";
        // cout << endl;

        vector<ll> dp(n+2, 0);
        for(int i=n-1; i>=0; i--){
            dp[i] = resets[i] - i + dp[resets[i]+1];
        }
        // for(auto d : dp) cout << d << " ";
        // cout << endl;

        ll ans = 0;
        for(auto& num : dp) ans += num;
        cout << ans << endl;

    }
}