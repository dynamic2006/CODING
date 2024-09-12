#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXNUM = 1e12;
ll h, n;
vector<pair<ll, ll>> attacks;

bool valid(ll turns)
{
    ll damage = 0;
    for(auto &attack : attacks){
        ll uses = 1 + (turns-1)/attack.second;
        damage += attack.first * uses;
        if(damage >= h) return true;
    }
    return false;
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        cin >> h >> n;
        attacks = vector<pair<ll, ll>>(n);
        for(ll i=0; i<n; i++) cin >> attacks[i].first;
        for(ll i=0; i<n; i++) cin >> attacks[i].second;

        ll ans = binarySearch(1, MAXNUM);
        cout << ans << endl;
    }
}