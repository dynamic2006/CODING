#include <bits/stdc++.h>
using namespace std;

struct Number{
    int num, index;
};

bool cmp (Number& a, Number& b){
    return a.num < b.num;
}

int main(){
    //freopen("sum3.in" , "r" , stdin);

    int n, target; cin >> n >> target;
    vector<Number> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i].num;
        nums[i].index = i+1;
    }
    sort(nums.begin() , nums.end() , cmp);

    long long sum = 0;
    int left = 0, mid = 1, right = n-1;
    while(left < mid && mid < n-1){
        while(mid < right){
            sum = nums[left].num + nums[mid].num + nums[right].num;

            if(sum == target){
                cout << nums[left].index  << " " << nums[mid].index << " " << nums[right].index << endl;
                return 0;
            }
            if(sum < target) mid++;
            if(sum > target) right--;
        }
        left++; mid = left+1; right = n-1;
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;

}