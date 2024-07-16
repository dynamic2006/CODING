#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nums;

bool valid(int k){
    //calc bitwise OR target number
    vector<int> occs(20, 0);
    for(int i=0; i<k; i++){
        for(int b=0; b<20; b++){
            if(nums[i] & (1<<b)) occs[b]++;
        }
    }
    int targetNum = 0;
    for(int b=0; b<20; b++){
        if(occs[b]) targetNum |= (1<<b);
    }
    //for(auto occ : occs) cout << occ;
    //cout << endl;
    //if(k == 4) cout << "Target " << targetNum << endl;

    //sliding window search
    for(int i=k; i<n; i++){
        //remove i-k th number, add ith number in
        for(int b=0; b<20; b++){
            if(nums[i-k] & (1<<b)) occs[b]--;
            if(nums[i] & (1<<b)) occs[b]++;
            //cout << "REMOVED " << nums[i-k] << " ADDED IN " << nums[i] << endl;
            //cout << "OCCS " << b << " EQUALS " << occs[b] << endl;
        }
        int curNum = 0;
        for(int b=0; b<20; b++){
            if(occs[b]) curNum |= (1<<b);
        }
        if(curNum != targetNum){
            //cout << "FAILED AT " << i <<  " BECAUSE " << curNum << " NOT EQUAL TO " << targetNum << endl;
            return false;
        }
    }
    return true;
    //cout << endl;
}

int binarySearch(int lo, int hi)
{
    hi++;
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        //cout << "CHECKING " << mid << endl;
        if(valid(mid)) hi = mid;
        else lo = mid+1;
    }
    return lo;
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("b.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        cin >> n;
        nums.resize(n);
        for(int i=0; i<n; i++) cin >> nums[i];

        int ans = binarySearch(1, n);
        cout << ans << endl;
    }
}