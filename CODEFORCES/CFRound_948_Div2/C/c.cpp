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
        int n; cin >> n;
        vector<int> nums(n);
        for(int i=0; i<n; i++){
            cin >> nums[i];
        }

        ll lcm = 1;
        int maxNum = *max_element(nums.begin() , nums.end());
        for(int i=0; i<n; i++){
            lcm = (lcm /__gcd(lcm, (ll)nums[i])) * nums[i];
            if(lcm > maxNum){
                cout << n << endl;
                break;
            }
        }

        if(lcm > maxNum) continue;

        vector<int> divisors; divisors.clear();
        for(int i=1; i*i <= maxNum; i++){
            if(maxNum % i == 0){
                divisors.push_back(i);
                divisors.push_back(maxNum/i);
            }
        }

        int maxSubSeq = 0;
        for(auto d : divisors){
            int curSubSeq = 0;
            ll curLCM = 1;
            for(int i=0; i<n; i++){
                if(nums[i] == d){
                    curSubSeq = 0;
                    break;
                }
                else if(d % nums[i] == 0){
                    curSubSeq++;
                    curLCM = (curLCM*nums[i] /__gcd(curLCM, (ll)nums[i]));
                }
            }
            //cout << "CUR " << curSubSeq << " D " << d << endl;
            if(curLCM == d) maxSubSeq = max(maxSubSeq, curSubSeq);
        }

        cout << maxSubSeq << endl;

    }
}