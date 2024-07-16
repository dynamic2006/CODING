#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("c.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];

        //try odd indices
        int j=n;
        vector<int> result1(n+1);
        vector<int> localMaxes, others;
        for(int i=0; i<n; i++){
            if(i%2 == 1 && i != n-1) localMaxes.push_back(nums[i]);
            else others.push_back(nums[i]);
        }
        sort(localMaxes.begin(), localMaxes.end());
        sort(others.begin(), others.end());
        for(auto num: localMaxes){
            result1[num] = j;
            j--;
        }
        for(auto num : others){
            result1[num] = j;
            j--;
        }
        
        int ans1 = 0;
        vector<int> combo(n);
        for(int i=0; i<n; i++){
            combo[i] = nums[i] + result1[nums[i]];
        }
        for(int i=1; i<n-1; i++){
            if(combo[i] > combo[i-1] && combo[i] > combo[i+1]) ans1++;
        }


        //try even indices
        j=n;
        vector<int> result2(n+1);
        localMaxes.clear(); others.clear();
        for(int i=0; i<n; i++){
            if(i%2 == 0 && i != 0) localMaxes.push_back(nums[i]);
            else others.push_back(nums[i]);
        }
        sort(localMaxes.begin(), localMaxes.end());
        sort(others.begin(), others.end());
        for(auto num: localMaxes){
            result2[num] = j;
            j--;
        }
        for(auto num : others){
            result2[num] = j;
            j--;
        }

        int ans2 = 0;
        for(int i=0; i<n; i++){
            combo[i] = nums[i] + result2[nums[i]];
        }
        for(int i=1; i<n-1; i++){
            if(combo[i] > combo[i-1] && combo[i] > combo[i+1]) ans2++;
        }

        if(ans1 > ans2){
            for(int i=0; i<n; i++) cout << result1[nums[i]] << " ";
        }
        else for(int i=0; i<n; i++) cout << result2[nums[i]] << " ";
        cout << endl;
    }
}