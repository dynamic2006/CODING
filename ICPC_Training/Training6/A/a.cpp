#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    for(int i=0; i<n; i++){
        int g; cin >> g;
        set<ll> nums;
        for(int j=0; j<g; j++){
            int a; cin >> a;
            if(nums.count(a)) nums.erase(a);
            else nums.insert(a);
        }
        cout << "Case #" << i+1 << ": " << *nums.begin() << endl;
    }
}