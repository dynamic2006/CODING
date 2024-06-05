#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[6];

int main()
{
    //dp using states
    string s; cin >> s;

    ll ans = 0;
    ll total = 0;

    for(int i=0; i<s.size(); i++){
        dp[0]++;

        if(s[i] == 'b'){
            dp[1] += dp[0];
            dp[0] = 0;
        }
        else if(s[i] == 'e'){
            dp[0] += dp[5];
            ans += dp[5];
            dp[5] = 0;

            dp[2] += dp[1];
            dp[1] = 0;
        }
        else if(s[i] == 's'){
            dp[4] += dp[3];
            dp[3] = dp[2];
            dp[2] = 0;
        }
        else if(s[i] == 'i'){
            dp[5] += dp[4];
            dp[4] = 0;
        }

        total += ans;
    }

    cout << total << endl;
}

// 0 1 2 3 4 5
// b e s s i e