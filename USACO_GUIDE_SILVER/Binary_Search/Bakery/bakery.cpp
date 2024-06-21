#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXNUM = 2 * 1e18;

struct Order
{
    ll cookies, muffins, wait;
};

ll t, n, t_c, t_m;
vector<Order> orders;

bool valid(ll cost)
{
    ll hiBound = min(t_c, t_c + t_m - cost - 1), loBound = max((ll)1, t_c - cost);
    for(auto order : orders){
        ll rhs = order.wait - order.muffins*(t_c + t_m - cost);
        ll den = order.cookies - order.muffins;
        if(den == 0){
            if(rhs < 0) return false;
        }
        else if(den > 0){
            hiBound = min(hiBound, rhs/den);
        }
        else{
            //we want loBound to be integral and rounded up due to max value taken
            //so we need to add den+1 to rhs so it always rounds up
            //note, use den+1 instead of den-1 because den<0, so |den+1| < |den|
            loBound = max(loBound, (rhs+den+1)/den);
        }
        if(loBound > hiBound) return false;
    }
    return true;
}

ll binarySearch(ll lo, ll hi)
{
    hi++;
    while(lo<hi){
        ll mid = lo + (hi-lo)/2;
        if(valid(mid)) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

void solve()
{
    cin >> n >> t_c >> t_m;
    orders.clear();
    orders.resize(n);
    for(ll i=0; i<n; i++){
        cin >> orders[i].cookies >> orders[i].muffins >> orders[i].wait;
    }

    //binary search on min moonies to spend
    ll ans = binarySearch(0, t_c + t_m - 2);
    cout << ans << endl;

}

int main()
{
    //freopen("bakery.in" , "r" , stdin);

    cin >> t;
    for(ll i=0; i<t; i++) solve();
}