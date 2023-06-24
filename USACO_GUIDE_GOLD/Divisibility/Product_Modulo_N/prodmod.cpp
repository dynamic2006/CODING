#include <bits/stdc++.h>
using namespace std;

int main(){

    //freopen("prodmod.in" , "r" , stdin);

    long long n; cin >> n;
    long long mod = 1;
    vector<int> nums;

    for(long long i=1; i<n; i++){
        if(__gcd(n,i) == 1){
            mod *= i;
            nums.push_back(i);
        }
        if(mod > n) mod %= n;
    }

    if(mod != 1){
        cout << nums.size() - 1 << endl;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != mod) cout << nums[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << nums.size() << endl;
        for(int i=0; i<nums.size(); i++){
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    return 0;

}

//ideas
//def exclude numbers that share a common divisor
//multiply the rest of the numbers together
//let the current modulo of the product be k
//note that k < n, so just exclude k from our list
//small note: if k = 1, don't exclude it