#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("sum3.in" , "r" , stdin);

    int n, x; cin >> n >> x;
    vector<pair<int, int>> nums(n);
    for(int i=0; i<n; i++){
        int a; cin >> a;
        nums[i] = {a, i+1};
    }
    sort(nums.begin(), nums.end());

    //3 pointers
    int l=0;
    int a=0, b=0;
    while(l < n){
        a = l+1; b = n-1;
        int p = nums[l].first;
        while(a<n && b<n && a<b){
            int y = nums[a].first;
            int z = nums[b].first;
            int sum = p + y + z;
            if(sum == x){
                cout << nums[l].second << " " << nums[a].second << " " << nums[b].second << endl;
                return 0;
            }
            else if(sum < x) a++;
            else b--;
        }
        l++;
    }

    cout << "IMPOSSIBLE" << endl;
}