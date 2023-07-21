#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 1e5;
const ll MAXM = 100;
const ll MOD = 1e9 + 7;

ll n, m;
ll dp[MAXN+1][MAXM+1];
vector<ll> nums;

int main() {

    //freopen("description.in" , "r" , stdin);

    cin >> n >> m;
    nums.resize(n);

    for(ll i=0; i<n; i++) cin >> nums[i];

    //handling case for first number in array
    //if 0, then can choose any value -> 1 for all cells
    if(nums[0] == 0) {
        for(ll j=1; j<=m; j++) dp[0][j] = 1;
    }
    //otherwise there is only 1 array, the given nonzero value
    else dp[0][nums[0]] = 1;

    for(ll i=1; i<n; i++) {

        //in this case, add three closest cells from above row
        if(nums[i] != 0) {
            ll count = -1;
            while(nums[i] + count <= m && count <= 1) {
                dp[i][nums[i]] = (dp[i][nums[i]] + dp[i-1][nums[i] + count]) % MOD;
                count++;
            }
        }
        
        //do the above, but for all columns
        else {
            for(ll j=1; j<=m; j++){
                ll count = -1;
                while(j + count <= m && count <= 1) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j + count]) % MOD;
                    count++;
                }
            }
        }
    }

    if(nums[n-1] != 0) {
        cout << dp[n-1][nums[n-1]] % MOD << endl;
        return 0;
    }

    ll total = 0;
    for(ll j=1; j<=m; j++){
        total = (total + dp[n-1][j]) % MOD;
    }

    cout << total << endl;
    return 0;

}