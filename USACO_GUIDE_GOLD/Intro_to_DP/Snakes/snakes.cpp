#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400;
const int MAXCHANGES = 400;

int dp[MAXN+1][MAXCHANGES+1];

int main() {

    freopen("snakes.in" , "r" , stdin);
    freopen("snakes.out" , "w" , stdout);

    int n, maxChanges; cin >> n >> maxChanges;
    int totalSize = 0;

    vector<int> groupSizes(n+1);
    
    groupSizes[0] = 0;
    for (int i=1; i<=n; i++){
        cin >> groupSizes[i];
        totalSize += groupSizes[i];
    }

    int maxSize = 0;
    for (int i=1; i<=n; i++){
        maxSize = max(maxSize, groupSizes[i]);
        dp[i][0] = i * maxSize;
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=maxChanges; j++){
            dp[i][j] = -1;
            int maxGroupSize = groupSizes[i];
            for (int k=1; k<=i; k++){
                maxGroupSize = max(maxGroupSize, groupSizes[i-k+1]);
                if(dp[i][j] == -1) dp[i][j] = dp[i-k][j-1] + k * maxGroupSize;
                else dp[i][j] = min(dp[i][j], dp[i-k][j-1] + k * maxGroupSize);
            }
        }
    }


    int complement = dp[n][0];
    for (int j=1; j<=maxChanges; j++){
        complement = min(complement , dp[n][j]);
    }
    cout << complement - totalSize << endl;
    return 0;



}