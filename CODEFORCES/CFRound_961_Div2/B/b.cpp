#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("b.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        vector<ll> petals(n);
        for(int i=0; i<n; i++) cin >> petals[i];
        sort(petals.begin() , petals.end());

        //two pointers
        // ll l=0, r=0;
        // ll ans = 0, curAns = 0;
        // while(r<n){
        //     while(r<n && m>=0 && petals[r] <= petals[l]+1){
        //         curAns += petals[r];
        //         m -= petals[r];
        //         r++;
        //     }
        // }

        ll l=0, r=-1;
        ll ans = 0, curAns = 0;
        while(r<n){
            if(r>=0){
                curAns += petals[r];
                m -= petals[r];
            }
            while(l<=r && (petals[r] > petals[l] + 1 || m < 0)){
                curAns -= petals[l];
                m += petals[l];
                l++;
            }
            ans = max(ans, curAns);
            if(l == n) break;
            //cout << "l " << l << " r " << r << endl;
            while(r<n-1 && m - petals[r+1] >= 0 && petals[r+1] <= petals[l] + 1){
                r++;
                curAns += petals[r];
                m -= petals[r];
            }
            //cout << "l " << l << " r " << r << endl;
            ans = max(ans, curAns);
            r++;
        }

        cout << ans << endl;
    }
}