#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
vector<ll> nums, prefix;

int main()
{
    //freopen("maxsum.in" , "r" , stdin);

    cin >> n;
    nums.resize(n);
    prefix.resize(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    prefix[0] = nums[0];
    ll minPrefix = min((ll)0, prefix[0]);
    ll ans = prefix[0];
    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] + nums[i];
        ans = max(ans, prefix[i] - minPrefix);
        minPrefix = min(minPrefix, prefix[i]);
    }
    cout << ans << endl;

}