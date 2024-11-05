#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    string s; cin >> s;
    vector<map<int, double>> dp(8);

    // cout << "CHeck" << endl;

    for(int i=0; i<(1<<7); i++){
        dp[__popcount(i)][i] = (double)0;
    }

    // cout << "ECHEL" << endl;

    vector<int> masks(7);
    for(int i=0; i<7; i++){
        set<int> seen;
        int x = i;
        do{
            // cout << x << endl;
            seen.insert(x);
            char c = s[x];
            // cout << "c " << c << endl;
            if(c == 'A') x = 0;
            else if(c - '0' >= 2 && c - '0' <= 7){
                // cout << "HERE" << endl;
                x = (c - '0')-1;
            }
            else break;
        }while(!seen.count(x));

        int mask = 0;
        for(auto x : seen){
            mask += (1 << x);
        }
        // cout << mask << endl;
        masks[i] = mask;
    }

    for(int i=1; i<=7; i++){
        for(auto &j : dp[i]){
            for(int k=0; k<7; k++){
                j.second += dp[i][j.first & masks[k]] + 1;
                // cout << j.second << endl;
            }
            j.second += 6;
            j.second /= 7;
            cout << j.second << endl;
        }
    }

    cout << dp[7][127] << endl;
}