#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    vector<int> nums(n);
    ll ans = 0;

    for(int i=0; i<n; i++) cin >> nums[i];

    for(int i=1; i<n; i++){
        int add = max(0, nums[i-1] - nums[i]);
        nums[i] += add;
        ans += add;
    }
    cout << ans << endl;
}