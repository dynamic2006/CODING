#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("input.in", "r", stdin);
 
    int t; cin >> t;
    int testCase = 0;
    while(t--){
        testCase++;
        int n; ll k, l; cin >> n >> k >> l;
        // if(testCase == 196){
        //     cout << n << 00 << k << 00 << l << 00 << endl;
        //     continue;
        // }
        k*=2; l*=2;
        vector<ll> pos(n);
        for(int i=0; i<n; i++){
            cin >> pos[i];
            pos[i] *= 2;
        }
        // if(testCase == 196){
        //     cout << (pos[1])/2 << endl;
        //     continue;
        // }
        bool reached = false;
 
        ll time = pos[0]; //move first sc to crow
        ll crowPos = k;
        pos[0] = -time;
    
        // int counter = 0;
 
        auto it = upper_bound(pos.begin(), pos.end(), crowPos-k);
        while(it != pos.end()){
            if(*it > crowPos){
                ll targetDist = l - crowPos;
                ll x = (*it - crowPos - time)/2;
                if(targetDist < max(x, (ll)0)){
                    cout << time + max(targetDist, (ll)0) << endl;
                    reached = true;
                    break; //may need valid bool here
                }
                
                ll addTime = max(x, (ll)0);
                time += addTime;
                *it -= 2*addTime;
                crowPos += k + addTime;
            }
            else{
                ll getToPos = min(*it + time, crowPos);
                // *it -= (getToPos - *it);
                *it -= time;
                crowPos = getToPos + k;
            }
            it = upper_bound(pos.begin(), pos.end(), crowPos-k-time);
 
            // cout << crowPos << endl;
            // counter++;
            // if(counter > 100) break;
        }
        if(reached) continue;
 
        if(crowPos < l) cout << time + l-crowPos << endl;
        else cout << time << endl;
    }
}