#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("a.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        vector<pair<ll, ll>> a(n);
        for(int i=0; i<n; i++) cin >> a[i].first;
        for(int i=0; i<n; i++) cin >> a[i].second;
        sort(a.begin(), a.end());

        vector<ll> singleFlowerResults(n);
        ll ans = min(a[0].first*a[0].second, (m/a[0].first)*a[0].first);
        singleFlowerResults[0] = ans;
        for(int i=1; i<n; i++){
            if(a[i].first == a[i-1].first + 1){
                //can try using two types of flowers
                ll prevFlowerUsed = singleFlowerResults[i-1]/a[i-1].first;
                ll curFlowerUsed = min((m-singleFlowerResults[i-1])/a[i].first, a[i].second);
                ll curAns = prevFlowerUsed*a[i-1].first + curFlowerUsed*a[i].first;
                ll change = min({m - curAns, prevFlowerUsed, a[i].second - curFlowerUsed});
                ans = max(ans, curAns + change);
            }
            //see max ans with just this type of flower
            singleFlowerResults[i] = min(a[i].first*a[i].second, (m/a[i].first)*a[i].first);
            ans = max(ans, singleFlowerResults[i]);
        }

        cout << ans << endl;

    }
}