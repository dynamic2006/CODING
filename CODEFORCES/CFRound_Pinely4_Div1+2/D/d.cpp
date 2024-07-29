#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("d.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n <= 6){
            vector<int> nums = {1,2,2,3,3,4};
            cout << nums[n-1] << endl;
            for(int i=0; i<n; i++) cout << nums[i] << " ";
            cout << endl;
            continue;
        }

        //need at least 4 colors as seen from n=6
        //4 sufficient -> color all i and i+4k same color
        //since i+4k-i = 4k, i XOR i+4k is divisible by 4 (not prime!)
        //so coloring these vertices same color is fine
        cout << 4 << endl;
        for(int i=0; i<n; i++){
            cout << (i % 4) + 1 << " ";
        }
        cout << endl;
    }
}