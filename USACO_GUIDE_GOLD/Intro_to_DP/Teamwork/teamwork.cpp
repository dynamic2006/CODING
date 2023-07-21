#include <bits/stdc++.h>
using namespace std;

vector<long long> dp;

int main() {
    
    freopen("teamwork.in" , "r" , stdin);
    freopen("teamwork.out" , "w" , stdout);

    int n, k; cin >> n >> k;
    vector<int> cowSkills(n);
    dp.resize(n+1); dp[0] = 0;

    for (int i=0; i<n; i++){
        cin >> cowSkills[i];
    }

    for (int i=1; i<=n; i++){
        int j = i-1;
        int maxSkill = -1;
        while(i - j <= k && j >= 0){
            maxSkill = max(maxSkill, cowSkills[j]);
            dp[i] = max(dp[i], dp[j] + (i-j) * maxSkill);
            j--;
        }
    }

    cout << dp[n] << endl;
    return 0;

}