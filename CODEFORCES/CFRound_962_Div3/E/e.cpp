#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("e.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        map<ll, ll> diffOccs; diffOccs[0] = 1;
        ll curDiff = 0, ans = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1') curDiff++;
            else curDiff--;

            ll term = ((s.size()-i)*diffOccs[curDiff]) % MOD;
            ans += term;
            ans %= MOD;

            //cout << ans << " ";

            diffOccs[curDiff] += (i+2);
            diffOccs[curDiff] %= MOD;
        }

        // ll ans = 0;
        // for(auto &x : diffOccs){
        //     //cout << x.first << " " << x.second << endl;
        //     ll newTerm = ((x.second*(x.second-1))/2) % MOD;
        //     ans += newTerm;
        //     ans %= MOD;
        // }

        cout << ans << endl;
    }
}