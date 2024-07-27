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
        int n; cin >> n;
        vector<ll> a(n), b(n+1);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<=n; i++) cin >> b[i];

        ll closestNum = a[0];
        ll ans = 0;
        for(int i=0; i<n; i++){
            ans += abs(a[i] - b[i]);
            if(b[n] <= max(a[i], b[i]) && b[n] >= min(a[i], b[i])){
                closestNum = b[n];
            }
            else if(b[n] > max(a[i], b[i]) && abs(closestNum - b[n]) > b[n] - max(a[i], b[i])){
                closestNum = max(a[i], b[i]);
            }
            else if(b[n] < min(a[i], b[i]) && abs(closestNum - b[n]) > min(a[i], b[i]) - b[n]){
                closestNum = min(a[i], b[i]);
            }
        }

        ans += abs(b[n] - closestNum) + 1;
        cout << ans << endl;
    }
}