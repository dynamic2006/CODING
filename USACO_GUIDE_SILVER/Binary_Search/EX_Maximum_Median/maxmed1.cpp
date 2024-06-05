#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;
vector<ll> nums;

ll lastHalfSum = 0;

bool valid(ll x){
    ll tempSum = 0;
    for(ll i=n/2; i<n; i++){
        tempSum += max(x, nums[i]);
    }
    return tempSum - lastHalfSum <= k;
}

ll binarySearch(ll lo, ll hi){
    lo--;
    while(lo < hi){
        ll mid = lo + (hi-lo+1)/2;
        if(valid(mid)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

int main(){
    //freopen("maxmed.in" , "r" , stdin);

    cin >> n >> k;
    nums.resize(n);
    for(ll i=0; i<n; i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    for(ll i = (n/2); i<n; i++){
        lastHalfSum += nums[i];
    }
    //cout << lastHalfSum << endl;

    //binary search
    ll ans = binarySearch(0, nums[n-1] + k);

    cout << ans << endl;
}

//IDEAS
//binary search on max possible median
//valid algo: for testing median x:
//if x*(n/2 + 1) - sum last n/2 + 1 terms <= k -> works
//max true binary search