#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("g.in", "r", stdin);
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        vector<int> a(n);
        multiset<int> b;
        for(int i=0; i<n; i++){
            cin >> a[i];
            b.insert(a[i]);
        }
        
        vector<int> nums;
        for(int i=0; i<n; i++){
            // bool foundReplacement = false;
            for(int j = (a[i]/4)*4; j<=(a[i]/4 + 1)*4; j++){
                auto it = b.find(j);
                if(it != b.end()){
                    nums.push_back(j);
                    b.erase(it);
                    // foundReplacement = true;
                    break;
                }
            }
            // if(!foundReplacement){
            //     nums.push_back(a[i]);

        }

        for(auto &x : nums) cout << x << " ";
        cout << endl;


    }
}