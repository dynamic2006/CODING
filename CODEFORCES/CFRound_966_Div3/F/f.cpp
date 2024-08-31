#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("f.in", "r", stdin);

    ll t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        vector<pair<ll, ll>> rects(n);
        for(ll i=0; i<n; i++){
            ll a, b; cin >> a >> b;
            rects[i].first = min(a,b) * max(a,b);
            rects[i].second = min(a,b);
        }
        sort(rects.begin(), rects.end());

        ll ops = 0;
        ll unusedRect = -1;
        for(ll i=0; i<n; i++){
            ll minSide = rects[i].second;
            ll maxSide = rects[i].first/rects[i].second;
            if(k >= minSide + maxSide){
                k -= (minSide + maxSide);
                ops += rects[i].first;
            }
            else if(unusedRect == -1 || rects[unusedRect].second > rects[i].second){
                unusedRect = i;
            }
        }
        if(k > 0 && unusedRect == -1){
            cout << -1 << endl;
            continue;
        }

        while(k > 0){
            ll minSide = rects[unusedRect].second;
            ll maxSide = rects[unusedRect].first / rects[unusedRect].second;

            k--; ops += minSide;
            maxSide--;
            rects[unusedRect].first = minSide*maxSide;
            rects[unusedRect].second = min(minSide, maxSide);
        }
        cout << ops << endl;
    }
}