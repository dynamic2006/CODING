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
        vector<int> nums(n);
        for(int i=1; i<n; i++) cin >> nums[i];
        cin >> nums[0];
        for(int i=0; i<n; i++) cout << nums[i] << " ";
        cout << endl;
    }
}