#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXNUM = 1e12;

ll n;

bool valid(ll m)
{
    //cout << "CHECKPOINT1" << endl;
    ll numLessThan = 0;
    for(ll i=1; i<=n; i++){
        numLessThan += min(m/i, n);
    }
    //cout << "CHECKPOINT2" << endl;
    if(numLessThan >= (n*n + 1)/2) return true;
    return false;
}

ll binarySearch(ll lo, ll hi)
{
    //cout << "CHECKPOINT" << endl;
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
    //freopen("table.in" , "r" , stdin);

    cin >> n;
    
    ll ans = binarySearch(1, n*n);
    cout << ans << endl;
}

//IDEAS
//binary search on min value of median m such that
//# of elements in table <= m is atleast >= (n^2 + 1)/2