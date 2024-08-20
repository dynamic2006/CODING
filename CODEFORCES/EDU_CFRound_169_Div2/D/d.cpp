#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXNUM = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("d.in", "r", stdin);

    ll t; cin >> t;
    while(t--){
        ll n, q; cin >> n >> q;
        vector<string> cityPortals(n+1);
        map<string, vector<ll>> portalCities;
        for(ll i=1; i<=n; i++){
            cin >> cityPortals[i];
            portalCities[cityPortals[i]].push_back(i);
        }

        // return 0;

        for(ll qry=0; qry<q; qry++){
            ll x, y; cin >> x >> y;
            char c1 = cityPortals[x][0], c2 = cityPortals[x][1];
            if(cityPortals[y][0] == c1 || cityPortals[y][0] == c2 || cityPortals[y][1] == c1 || cityPortals[y][1] == c2){
                cout << abs(x-y) << endl;
                continue;
            }

            // cout << "CHECK" << endl;

            ll ans = MAXNUM;
            ll a = min(x,y), b = max(x,y);
            for(auto p : portalCities){
                if(p.first == cityPortals[a] || p.first == cityPortals[b] || p.second.empty()) continue;
                auto ptr = lower_bound(p.second.begin(), p.second.end(), a);
                if(ptr != p.second.end()){
                    ans = min(ans, abs(*ptr - a) + abs(*ptr - b));
                    if(*ptr > b && ptr != p.second.begin()){
                        ans = min(ans, abs(*prev(ptr) - a) + abs(*prev(ptr) - b));
                    }
                }
                else{
                    ans = min(ans, abs(*prev(p.second.end()) - a) + abs(*prev(p.second.end()) - b));
                }
            }

            if(ans == MAXNUM){
                cout << -1 << endl;
                continue;
            }
            cout << ans << endl;
        }
    }
}