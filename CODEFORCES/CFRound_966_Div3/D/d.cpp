#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("d.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<ll, char>> a(n);
        vector<ll> prefixSum(n);
        for(int i=0; i<n; i++) cin >> a[i].first;
        string s; cin >> s;
        for(int i=0; i<n; i++) a[i].second = s[i];

        prefixSum[0] = a[0].first;
        for(int i=1; i<n; i++) prefixSum[i] = prefixSum[i-1] + a[i].first;

        ll ans = 0;
        int left=0, right=n-1;
        while(left<right){
            if(a[left].second == 'L' && a[right].second == 'R'){
                ll term = prefixSum[right] - prefixSum[left] + a[left].first;
                ans += term;
                left++;
                right--;
            }
            else if(a[left].second != 'L') left++;
            else if(a[right].second != 'R') right--;
        }
        cout << ans << endl;
    }
}