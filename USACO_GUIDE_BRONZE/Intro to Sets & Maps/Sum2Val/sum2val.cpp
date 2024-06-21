#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("sum2val.in" , "r" , stdin);

    map<int, int> nums;
    int n, x; cin >> n >> x;

    for(int i=0; i<n; i++){
        int a; cin >> a;
        if(nums.count(a)){
            cout << nums[a] << " " << i+1 << endl;
            return 0;
        }
        else{
            nums[x-a] = i+1;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}