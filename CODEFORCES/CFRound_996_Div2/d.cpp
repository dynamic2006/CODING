#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; ll k, l; cin >> n >> k >> l;
        k*=2; l*=2;
        vector<ll> pos(n);
        for(int i=0; i<n; i++){
            cin >> pos[i];
            pos[i] *= 2;
        }
        bool reached = false;

        ll time = pos[0]; //move first sc to crow
        ll crowPos = k;
        pos[0] = 0;
        for(int i=1; i<n; i++){
            // cout << crowPos << " ";
            //make crow jump over each sc
            auto ix = lower_bound(pos.begin(), pos.end(), crowPos);
            if(ix == pos.end()) break;
            else i = (ix - pos.begin());

            ll targetDist = l - crowPos;
            ll x = (pos[i] - crowPos - time)/2;
            if(targetDist < max(x, (ll)0)){
                cout << time + max(targetDist, (ll)0) << endl;
                reached = true;
                break; //may need valid bool here
            }
            
            time += max(x, (ll)0);
            pos[i] = crowPos;
            crowPos += k;
        }
        if(reached) continue;

        if(crowPos < l) cout << time + l-crowPos << endl;
        else cout << time << endl;
    }
}