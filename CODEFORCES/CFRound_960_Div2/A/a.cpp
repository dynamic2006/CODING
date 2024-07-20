#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];

        map<int, int> occs;
        for(int i=0; i<n; i++){
            occs[nums[i]]++;
        }

        bool aliceWins = false;
        for(auto& p : occs){
            if(p.second % 2 == 1){
                aliceWins = true;
                break;
            }
        }
        if(aliceWins) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
