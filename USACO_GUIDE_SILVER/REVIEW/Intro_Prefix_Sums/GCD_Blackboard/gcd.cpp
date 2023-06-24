#include <bits/stdc++.h>
using namespace std;

int main(){

    //freopen("gcd.in" , "r" , stdin);

    //keep a prefix and suffix gcd array
    //loop over all possible choices for replacement
    //should be O(3n) time

    int n; cin >> n;
    vector<int> nums(n+1), preGcd(n+1), sufGcd(n+2);
    preGcd[0] = 0; sufGcd[n+1] = 0;

    for(int i=1; i<=n; i++){
        int num; cin >> num;
        //gcd of all nums before and including the ith one
        nums[i] = num;
        preGcd[i] = gcd(preGcd[i-1] , num);
    }

    for(int i=n; i>0; i--){
        //gcd of all nums after and including the ith one
        sufGcd[i] = gcd(sufGcd[i+1] , nums[i]);
    }

    //loop over all possibilities
    int ans = 0;
    for(int i=1; i<=n; i++){
        //cout << preGcd[i-1] << " " << sufGcd[i+1] << endl;
        ans = max(ans , gcd(preGcd[i-1] , sufGcd[i+1]));
    }

    cout << ans << endl;
    return 0;

}