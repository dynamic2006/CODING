#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXNUM = 1e9;

ll n, k;
vector<ll> nums;
vector<ll> prefix, suffix;

bool validMin(ll minValue, ll changesLeft){
    ll lastNumIndex = prev(upper_bound(nums.begin(), nums.end(), minValue)) - nums.begin();
    ll changesNeeded = prefix[lastNumIndex] + (minValue - nums[lastNumIndex])*(lastNumIndex+1);
    if(changesNeeded > changesLeft) return false;
    return true;
}

bool validMax(ll maxValue, ll changesLeft){
    ll nextNumIndex = lower_bound(nums.begin() , nums.end() , maxValue) - nums.begin();
    ll changesNeeded = suffix[nextNumIndex] + (nums[nextNumIndex] - maxValue)*(n-nextNumIndex);
    if(changesNeeded > changesLeft) return false;
    return true;
}

//finds max min value
ll binarySearchMin(ll lo, ll hi, ll changesLeft){
    lo--;
    while(lo<hi){
        ll mid = lo + (hi-lo+1)/2;
        if(validMin(mid, changesLeft)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

//finds min max value
ll binarySearchMax(ll lo, ll hi, ll changesLeft){
    hi++;
    while(lo<hi){
        ll mid = lo + (hi-lo)/2;
        if(validMax(mid, changesLeft)) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

int main()
{
    //freopen("mindiff.in" , "r" , stdin);

    cin >> n >> k;
    nums.resize(n);
    for(ll i=0; i<n; i++) cin >> nums[i];
    sort(nums.begin() , nums.end());

    //fill prefix and suffix
    prefix.resize(n); suffix.resize(n);
    prefix[0] = 0;
    for(ll i=1; i<n; i++){
        prefix[i] = prefix[i-1] + (nums[i] - nums[i-1])*i;
    }
    suffix[n-1] = 0;
    for(ll i=n-2; i>=0; i--){
        suffix[i] = suffix[i+1] + (nums[i+1] - nums[i])*(n-i-1);
    }

    //DEBUG
    // for(auto x : prefix) cout << x << " ";
    // cout << endl;
    // for(auto x : suffix) cout << x << " ";
    // cout << endl;

    ll ans = MAXNUM+1;

    //try each element as min value
    for(ll i=0; i<n; i++){
        if(prefix[i] > k) break;

        ll minValue = nums[i];
        ll maxValue = binarySearchMax(minValue, nums[n-1], k-prefix[i]);

        if(maxValue <= nums[n-1]) ans = min(ans, maxValue - minValue);
        //cout << minValue << " " << maxValue << endl;
    }
    //cout << endl;

    //try each element as max value
    for(ll i=n-1; i>=0; i--){
        if(suffix[i] > k) break;

        ll maxValue = nums[i];
        ll minValue = binarySearchMin(nums[0], maxValue, k-suffix[i]);

        if(minValue >= nums[0]) ans = min(ans, maxValue - minValue);
        //cout << minValue << " " << maxValue << endl;
    }

    cout << ans << endl;
}
//IDEAS
//either R or L is in og array -- proof by contradiction in notes
//iterate thru each element x as either min or max
//for min x, bin search for min element y >=x check if valid max value
//for max x, bin search for max element y <=x check if valid min value
