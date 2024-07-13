#include <bits/stdc++.h>
using namespace std;

const int MAXNUM = 1e9;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("d.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> nums(n);
        for(int i=0; i<n; i++) nums[i] = s[i] - '0';

        int ans = MAXNUM;
        bool foundZero = false;
        vector<int> temp;
        for(int i=1; i<n; i++){
            temp.clear();
            foundZero = false;
            for(int j=0; j<n; j++){
                if(j == i) temp[i-1] = 10*temp[i-1] + nums[j];
                else temp.push_back(nums[j]);
            }
            for(auto x : temp) if(x == 0) foundZero = true;
            // cout << endl;
            // for(auto x : temp) cout << x << " ";
            // cout << endl;
            //cout << "TEMP SIZE " << temp.size() << endl;
            if(foundZero){
                ans = 0;
                break;
            }

            int curAns = temp[0];
            for(int i=0; i<temp.size()-1; i++){
                if(curAns == 1) curAns = temp[i+1];
                else if(temp[i+1] != 1) curAns += temp[i+1];
            }
            ans = min(ans, curAns);
        }
        cout << ans << endl;
        //cout << "END" << endl;
    }
}