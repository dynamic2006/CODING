#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXNUM = 1e18;

ll n, k;
vector<ll> nums;

bool valid(ll maxsum)
{
    ll cursum = 0;
    ll sections = 1;
    for(int i=0; i<n; i++){
        if(nums[i] > maxsum) return false;
        if(cursum + nums[i] <= maxsum){
            cursum += nums[i];
        }
        else{
            sections++;
            cursum = nums[i];
        }
    }

    if(sections > k) return false;
    else return true;
}

//binary search for minimum max sum in a subarray
ll binarySearch(ll lo, ll hi)
{
    hi++;
    while(lo < hi){
        ll mid = lo + (hi-lo)/2;
        if(valid(mid)) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

int main()
{
    //freopen("arrdiv.in" , "r" , stdin);

    cin >> n >> k;
    nums.resize(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    ll ans = binarySearch(1, MAXNUM);
    cout << ans << endl;
}