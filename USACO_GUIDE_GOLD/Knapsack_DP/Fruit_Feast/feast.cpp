#include <bits/stdc++.h>
using namespace std;

const int MAXFULL = 5*1e6;
int t, orange, lemon;
//dp[0][i] is for when you have NOT previously consumed water
//dp[1][i] is for when you have already consumed water (or are consuming water in the state)
bool dp[2][MAXFULL+1];

int main() {

    freopen("feast.in" , "r" , stdin);
    freopen("feast.out" , "w" , stdout);

    cin >> t >> orange >> lemon;

    dp[0][0] = true; //very start, water NOT previously consumed
    dp[1][0] = true; //very start, drink water

    for(int i=0; i<=t; i++){
        if(i >= orange && dp[0][i-orange]) dp[0][i] = true; //can eat an orange
        else if(i >= lemon && dp[0][i-lemon]) dp[0][i] = true; //can eat a lemon
        
        if(dp[0][i]) dp[1][i/2] = true; //we can drink water, so fullness gets divided by 2
        //also note that this is in state (1), since we are consuming water
    }

    //now just need to mark (1) states that DON'T end with drinking water (covered above)
    //to get those states, we just see if an orange or lemon could be consumed
    //from a previous (1) state, since drinking water is no longer an option
    for(int i=0; i<=t; i++){
        if(i>=orange){
            if(dp[1][i-orange]){
                dp[1][i] = true;
                continue;
            }
        }
        if(i>=lemon){
            if(dp[1][i-lemon]){
                dp[1][i] = true;
            }
        }
    }

    for(int i=t; i>=0; i--){
        if(dp[0][i] || dp[1][i]){
            cout << i << endl;
            return 0;
        }
    }

}