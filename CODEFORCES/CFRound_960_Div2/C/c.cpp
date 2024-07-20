#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("c.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll ans = 0;
        vector<ll> nums(n);
        for(int i=0; i<n; i++){
            cin >> nums[i];
            ans += nums[i];
        }

        vector<ll> result(n);
        map<ll,ll> occs;
        ll maxMAD = 0;
        for(int i=0; i<n; i++){
            if(occs[nums[i]]++ == 0) result[i] = maxMAD;
            else{
                maxMAD = max(maxMAD, nums[i]);
                result[i] = maxMAD;
            }
        }
        for(auto &x : result) ans += x;

        // for(auto &x : result) cout << x << " ";
        // cout << endl;

        vector<ll> result2(n);
        occs.clear();
        maxMAD = 0;
        for(int i=0; i<n; i++){
            if(occs[result[i]]++ == 0) result2[i] = maxMAD;
            else{
                maxMAD = max(maxMAD, result[i]);
                result2[i] = maxMAD;
            }
        }

        // for(auto &x : result2) cout << x << " ";
        // cout << endl;

        vector<ll> prefix(n); prefix[0] = 0;
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + result2[i];
        }
        for(int i=n-1; i>=0; i--){
            ans += prefix[i];
        }
        cout << ans << endl;
    }
}
//Ideas
//do operation once, then result array is sorted increasing order
//then for each unique x in result array, do x * (#appearances)(#appearances+1)/2