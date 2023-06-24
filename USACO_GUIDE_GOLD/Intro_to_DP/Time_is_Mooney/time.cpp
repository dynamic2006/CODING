#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, c, ans = 0;
const ll MAXCITIES = 1000;
const ll MAXDAYS = 1000; //best case: c=1, each m=1000

map<int, vector<int>> adj; //holds all roads that lead to [key]
vector<int> profits;
ll dp[MAXDAYS+1][MAXCITIES+1];

//NOTE DFS WOULD TAKE WAYYY TOO LONG!!!
//instead we use dp to take around 5*10^6 operations, much faster =D

int main() {

    freopen("time.in" , "r" , stdin);
    freopen("time.out" , "w" , stdout);

    cin >> n >> m >> c;
    profits.resize(n+1); profits[0] = 0;
    for(ll i=1; i<=n; i++) cin >> profits[i];

    for(ll i=0; i<m; i++){
        ll a, b; cin >> a >> b;
        adj[b].push_back(a);
    }

    for(ll i=0; i<=MAXCITIES; i++){
        for(ll j=0; j<=MAXDAYS; j++){
            dp[i][j] = -1;
        }
    }

    //iterate over each cell -> 10^6
    //for each day, up to 2000 roads to check
    //so overall ~ 10^6 + 2000*1000 = 3*(10^6)
    dp[0][1] = 0;
    for(ll i=1; i<=MAXDAYS; i++){
        for(ll j=1; j<=MAXCITIES; j++){
            for(auto prevCity : adj[j]){
                //only process if previous city was able to be visited
                //so its current max profit is atleast 0 (not -1)
                if(dp[i-1][prevCity] >= 0){
                    dp[i][j] = max(dp[i][j], dp[i-1][prevCity] + profits[j]);
                }
            }
        }
    }

    //go over dp for ending with city 1, get max ans
    for(ll d=0; d<=MAXDAYS; d++){
        ans = max(ans, dp[d][1] - c*d*d);
    }
    cout << ans << endl;
    return 0;
}