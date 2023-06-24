#include <bits/stdc++.h>
using namespace std;

struct Number{
    int num, index;
};

bool cmp (Number& a, Number& b){
    return a.num < b.num;
}

int main(){
    //freopen("sum2.in" , "r" , stdin);

    int n, target; cin >> n >> target;
    vector<Number> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i].num; nums[i].index = i+1;
    }
    sort(nums.begin() , nums.end() , cmp);

    int left_pointer = 0, right_pointer = n-1, sum;
    while(left_pointer < right_pointer){
        sum = nums[left_pointer].num + nums[right_pointer].num;
        if(sum < target) left_pointer++;
        else if(sum > target) right_pointer--;
        else if(sum == target){
            //cout << nums[left_pointer] << " + " << nums[right_pointer] << endl;
            cout << nums[left_pointer].index <<  " " << nums[right_pointer].index << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl; return 0;
}