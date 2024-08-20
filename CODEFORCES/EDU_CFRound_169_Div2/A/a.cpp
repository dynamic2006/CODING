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
        vector<int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];

        if(n>2){
            cout << "NO" << endl;
        }
        else if(n==2){
            if(abs(nums[0]-nums[1]) > 1){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }
}