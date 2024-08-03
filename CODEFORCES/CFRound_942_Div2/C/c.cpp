#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXNUM = 1e13;

ll n, k;
ll coinsLeft;
vector<ll> cards;

bool valid(ll lowestCard)
{
    ll coinsUsed = 0;
    for(int i=0; i<n; i++){
        if(cards[i] < lowestCard) coinsUsed += (lowestCard - cards[i]);
    }
    if(coinsUsed <= k){
        coinsLeft = k - coinsUsed;
        return true;
    }
    return false;
}

ll binarySearch(ll lo, ll hi)
{
    lo--;
    while(lo<hi){
        ll mid = lo + (hi-lo+1)/2;
        if(valid(mid)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("c.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        cards = vector<ll>(n);
        for(ll i=0; i<n; i++) cin >> cards[i];

        ll ans = 0; coinsLeft = 0;
        ll maxMinCard = binarySearch(1, MAXNUM);
        ans = maxMinCard*n - (n-1);
        // cout << "COINSLEFT " << coinsLeft << " ";
        for(ll i=0; i<n; i++){
            // cout << ans << " ";
            if(cards[i] - maxMinCard > 0) ans++;
            else if(coinsLeft > 0){
                coinsLeft--;
                ans++;
            }
        }
        // cout << " FINAL ANS ";
        cout << ans << endl;
    }
}