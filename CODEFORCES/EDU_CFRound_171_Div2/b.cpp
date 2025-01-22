#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXNUM = 1e18;

bool valid(ll k, vector<ll>& pos)
{
    int counter = 0;
    int i=1;
    while(i<pos.size()){
        if(pos[i] - pos[i-1] <= k){
            counter++;
            i++;
        }
        i++;
    }
    if(counter >= pos.size()/2) return true;
    return false;
}

ll binarySearch(ll lo, ll hi, vector<ll>& pos)
{
    hi++;
    while(lo<hi){
        ll mid = lo + (hi-lo)/2;
        if(valid(mid, pos)) hi = mid;
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
        int n; cin >> n;
        vector<ll> pos(n);
        for(int i=0; i<n; i++) cin >> pos[i];

        ll ans = binarySearch(1, MAXNUM, pos);
        cout << ans << endl;
    }
}