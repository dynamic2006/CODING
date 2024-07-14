#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXNUM = 1e11;

ll n;
vector<ll> k;
vector<ll> bets;

bool valid(ll coins)
{
    ll total = 0;
    for(ll i=0; i<n; i++){
        total += coins/k[i] + 1;
        if(total >= coins) return false;
    }
    for(ll i=0; i<n; i++){
        bets[i] = coins/k[i] + 1;
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
    cin >> n;
    k.resize(n);
    bets.clear();
    bets.resize(n,0);
    for(ll i=0; i<n; i++) cin >> k[i];

    binarySearch(0, MAXNUM);

    if(bets[0] == 0){
        cout << "-1" << endl;
    }
    else{
        for(auto bet : bets) cout << bet << " ";
        cout << endl;
    }
}

int main()
{
    //freopen("c.in" , "r" , stdin);

    int t; cin >> t;
    while(t--) solve();
}