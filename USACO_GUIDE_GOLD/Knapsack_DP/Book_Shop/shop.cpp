#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int MAXX = 1e5;

//dp[i][j] = max pages
//where we can choose any of the first ith books
//and the maximum cost we can have is j
int dp[MAXN+1][MAXX+1];

int main() {

    //freopen("shop.in" , "r" , stdin);

    int n, x; cin >> n >> x;
    vector<int> prices(n), pages(n);
    for(int i=0; i<n; i++) cin >> prices[i];
    for(int i=0; i<n; i++) cin >> pages[i];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=x; j++){
            //if able to, then choose to either
            //INCLUDE or EXCLUDE the ith book to maximize dp[i][j] (pages) 
            if(j>=prices[i-1]) dp[i][j] = max(dp[i-1][j-prices[i-1]] + pages[i-1] , dp[i-1][j]);
            //if max cost j too low, then instead take max of cell above and cell to left of dp[i][j]
            else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }

    cout << dp[n][x] << endl;
    return 0;

}