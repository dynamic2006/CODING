#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> nums;

        int largestPow2 = -1;
        for(int i=0; i<=20; i++){
            int num = 1<<i;
            if(num <= k && num*2 > k){
                nums.push_back(k - num);
                nums.push_back(k+1);
                nums.push_back(k + num + 1);
            }
            else nums.push_back(num);
        }

        cout << nums.size() << endl;
        for(auto &x : nums){
            cout << x << " ";
        }
        cout << endl;
    }
}