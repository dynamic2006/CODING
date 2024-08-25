#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("a.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> nums(n), occs(n+1, 0);
        for(int i=0; i<n; i++){
            cin >> nums[i];
            occs[nums[i]]++;
        }
        sort(occs.begin(), occs.end(), greater<int>());
        cout << n - occs[0] << endl;
    }
}