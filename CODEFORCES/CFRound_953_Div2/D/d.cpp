#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("d.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        vector<ll> candidates(n);
        for(int i=0; i<n; i++) cin >> candidates[i];
        candidates[0] += k;

        vector<ll> ans(n);

        int maxNumIdx = max_element(candidates.begin() , candidates.end()) - candidates.begin();
        vector<ll> prefix(n); prefix[0] = candidates[0];
        for(int i=1; i<n; i++) prefix[i] = prefix[i-1] + candidates[i];

        for(int i=0; i<n; i++){
            if(i == maxNumIdx){
                ans[i] = 0; continue;
            }

            if(prefix[i] >= candidates[maxNumIdx]) ans[i] = i;
            else ans[i] = i+1;
        }

        for(auto a : ans) cout << a << " ";
        cout << endl;

    }
}