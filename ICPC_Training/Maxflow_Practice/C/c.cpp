#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    vector<ll> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    vector<double> prefix(n, 0), suffix(n, 0);

    double ans = 0;
    prefix[0] = (double) nums[0];
    ans = max(ans, prefix[0]);
    for(int i=1; i<n; i++){
        prefix[i] = (i*(prefix[i-1]) + nums[i])/(i+1);
        ans = max(ans, prefix[i]);
    }
    suffix[n-1] = (double) nums[n-1];
    ans = max(ans, suffix[n-1]);
    for(int i=n-2; i>=0; i--){
        suffix[i] = ((n-i-1)*(suffix[i+1]) + nums[i])/(n-i);
        ans = max(ans, suffix[i]);
    }

    cout << fixed << setprecision(10) << ans << endl;
    
}