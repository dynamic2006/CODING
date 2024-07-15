#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("c.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> nums; nums.clear();
        nums.push_back(n);
        for(int i=0; i<64; i++){
            //cout << (n & (1<<(64-i)));
            //continue;
            if(n < (1ll<<i)) break;
            if((n & (1ll<<i)) && ((n ^ (1ll<<i)) > 0)){
                //cout << i << " " << (n ^ (1ll<<i)) << endl;
                nums.push_back(n ^ (1ll<<i));
            }
        }
        //return 0;
        sort(nums.begin() , nums.end());
        cout << nums.size() << endl;
        for(auto num : nums) cout << num << " ";
        cout << endl;
    }
}