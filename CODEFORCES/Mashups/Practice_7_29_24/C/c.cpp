#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXNUM = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("c.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        bool valid = true;
        vector<ll> diffs(n); diffs[0] = 0;
        for(int i=1; i<n; i++){
            if(a[i] == a[i-1]) diffs[i] = 0;
            else if(a[i] < a[i-1]){
                if(a[i] == 1){
                    valid = false;
                    cout << -1 << endl;
                    break;
                }
                ll temp = a[i], counter = 0;
                while(temp < a[i-1]){
                    counter++;
                    temp *= temp;
                    if(counter > 10){
                        //cout << "BROKE 1 " << temp << " " << a[i-1] << endl;
                        break;
                    }
                }
                diffs[i] = counter;
            }
            else{
                ll temp = a[i-1], counter = 0;
                if(a[i-1] == 1){
                    diffs[i] = -MAXNUM;
                    continue;
                }
                while(temp <= a[i]){
                    counter++;
                    temp *= temp;
                    if(counter > 10){
                        //cout << "BROKE 2 " << temp << " " << a[i] << endl;
                        break;
                    }
                }
                diffs[i] = -counter+1;
            }
        }

        if(!valid) continue;

        // for(auto &d : diffs) cout << d << " ";
        // cout << endl;
        
        ll ans = 0, cur = 0;
        for(int i=1; i<n; i++){
            if((cur + diffs[i]) <= 0) cur = 0;
            else{
                cur += diffs[i];
                ans += cur;
            }
        }
        cout << ans << endl;
    }
}