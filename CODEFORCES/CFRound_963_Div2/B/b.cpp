#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("b.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        bool valid = true;
        for(int i=0; i<n; i++){
            if(a[i] % 2 != a[0] % 2){
                valid = false; break;
            }
        }
        if(valid){
            cout << 0 << endl;
            continue;
        }

        ll ans = 0;
        vector<int> evenIdxs;
        for(int i=0; i<n; i++){
            if(a[i]%2 == 0){
                evenIdxs.push_back(i);
                ans++;
            }
        }

        if(a[n-1]%2 == 1){
            cout << ans << endl;
            continue;
        }

        int maxOddIdx;
        for(int i=n-1; i>=0; i--){
            if(a[i]%2 == 1){
                maxOddIdx = i; break;
            }
        }

        ll curNum = a[maxOddIdx];
        for(int i=0; i<evenIdxs.size(); i++){
            if(curNum > a[evenIdxs[i]]){
                curNum += a[evenIdxs[i]];
            }
            else break;
        }

        if(curNum > a[n-1]){
            cout << ans << endl;
        }
        else cout << ans+1 << endl;

    }
}