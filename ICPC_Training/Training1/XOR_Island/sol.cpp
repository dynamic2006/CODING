#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<int> nums;
vector<bool> dp;
vector<vector<int>> ord;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    cin >> n;
    nums = vector<int>(n);
    dp = vector<bool>((1<<n), false);

    for(int i=0; i<n; i++) cin >> nums[i];

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if((nums[i] ^ nums[j]) == nums[k]){
                    //these three form a XOR triple
                    //cout << ((1<<i) | (1<<j) | (1<<k))  << endl;
                    int triple = (1<<i) | (1<<j) | (1<<k);
                    // cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;
                    dp[triple] = true;
                }
            }
        }
    }

    //group bitmasks by number of on bits
    ord = vector<vector<int>>(n+1, vector<int>());
    for(int i=0; i<(1<<n); i++){
        // cout << i << " " << __popcount(i) << endl;
        ord[__popcount(i)].push_back(i);
    }

    //propagate XOR triples up thru masks
    for(int i=4; i<=n; i++){
        for(auto &j : ord[i]){
            for(int k=0; k<n; k++){
                // cout << "IN LOOP" << endl;
                if(j & (1<<k)){
                    // cout << "TRUE COND" << endl;
                    if(dp[j ^ (1<<k)]){
                        // cout << "1" << endl;
                        dp[j] = true;
                        // cout << j << endl;
                    }
                }
            }
        }
    }

    //calculate answer
    for(int i=n; i>=0; i--){
        for(auto &j : ord[i]){
            // cout << j << ":" << dp[j] << " ";
            if(!dp[j]){
                // cout << "FALSE at " << j << endl;
                cout << (n - i) << endl;
                return 0;
            }
        }
        // cout << endl;
    }

}

//ideas
//dp for each subset of islanders if they have triple among them or not
//dp[i] = true if triple in subset i, else false
//find largest size subset with no triples (dp[i] = 0)
//then let the size of this subset be k
//then answer is just n-k since you have one rep from each triple