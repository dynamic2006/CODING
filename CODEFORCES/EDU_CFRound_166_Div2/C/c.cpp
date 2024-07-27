#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("c.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        ll total = n+m+1;
        vector<pair<ll, ll>> ppl(total);
        vector<int> prefs(total);
        vector<ll> programmers, testers;


        for(ll i=0; i<total; i++){
            cin >> ppl[i].first;
        }
        for(ll i=0; i<total; i++){
            cin >> ppl[i].second;
            if(ppl[i].first > ppl[i].second){
                prefs[i] = 1;
                programmers.push_back(i);
            }
            else{
                prefs[i] = 2;
                testers.push_back(i);
            }
        }

        vector<ll> dp(total);
        vector<ll> prefix(total+1, 0);
        ll curTesters = 0, curProgs = 0;
        for(ll i=1; i<=total; i++){
            prefix[i] = prefix[i-1];
            if(prefs[i-1] == 1){
                if(curProgs < n){
                    prefix[i] += ppl[i-1].first;
                    curProgs++;
                }
                else{
                    prefix[i] += ppl[i-1].second;
                    curTesters++;
                }
            }
            else{
                if(curTesters < m){
                    prefix[i] += ppl[i-1].second;
                    curTesters++;
                }
                else{
                    prefix[i] += ppl[i-1].first;
                    curProgs++;
                }
            }
            //cout << "PREFIX " << prefix[i] << endl;
        }
        //cout << "PREFIX " << prefix[total-1] << endl;
        dp[total-1] = prefix[total-1];

        for(ll i=total-2; i>=0; i--){
            //remove ith person
            if(prefix[i+1] - prefix[i] == ppl[i].first){
                //programmer
                auto it = upper_bound(programmers.begin(), programmers.end(), i);
                if(it != programmers.end()){
                    dp[i] = dp[*it] - ppl[i].first + ppl[*it].first;
                }
                else{
                    //assign last person to programmer
                    dp[i] = dp[total-1] - ppl[i].first + ppl[total-1].first;
                }
            }
            else{
                //tester
                auto it = upper_bound(testers.begin(), testers.end(), i);
                if(it != testers.end()){
                    dp[i] = dp[*it] - ppl[i].second + ppl[*it].second;
                }
                else{
                    //assign last person to tester
                    dp[i] = dp[total-1] - ppl[i].second + ppl[total-1].second;
                }
            }
        }

        for(int i=0; i<total; i++) cout << dp[i] << " ";
        cout << endl;
    }
}