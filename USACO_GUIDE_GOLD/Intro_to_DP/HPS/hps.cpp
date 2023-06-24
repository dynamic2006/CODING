#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int MAXK = 20;

map<char, int [MAXK+1][MAXN+1]> dp;

int main() {

    freopen("hps.in" , "r" , stdin);
    freopen("hps.out" , "w" , stdout);

    int n, k; cin >> n >> k;
    int ans = 0;
    vector<char> moves(n);

    for(int i=0; i<n; i++){
        char c; cin >> c;
        moves[i] = c;
        if(i > 0){
            dp['H'][0][i] = dp['H'][0][i-1];
            dp['P'][0][i] = dp['P'][0][i-1];
            dp['S'][0][i] = dp['S'][0][i-1];
        }
        dp[c][0][i]++;
        if(i == n-1){
            ans = max(ans, dp['H'][0][i]);
            ans = max(ans, dp['P'][0][i]);
            ans = max(ans, dp['S'][0][i]);
        }
    }
    for(int i=1; i<=k; i++){
        dp['H'][i][0] = dp['H'][i-1][0];
        dp['P'][i][0] = dp['P'][i-1][0];
        dp['S'][i][0] = dp['S'][i-1][0];
    }

    for(int changes=1; changes<=k; changes++){
        for(int game=1; game<n; game++){
            dp['H'][changes][game] = max(dp['P'][changes-1][game-1], dp['S'][changes-1][game-1]);
            dp['H'][changes][game] = max(dp['H'][changes][game], dp['H'][changes][game-1]);
            if(moves[game] == 'H') dp['H'][changes][game]++;
            if(game == n-1) ans = max(ans, dp['H'][changes][game]);
            
            dp['P'][changes][game] = max(dp['H'][changes-1][game-1], dp['S'][changes-1][game-1]);
            dp['P'][changes][game] = max(dp['P'][changes][game], dp['P'][changes][game-1]);
            if(moves[game] == 'P') dp['P'][changes][game]++;
            if(game == n-1) ans = max(ans, dp['P'][changes][game]);
            
            dp['S'][changes][game] = max(dp['P'][changes-1][game-1], dp['H'][changes-1][game-1]);
            dp['S'][changes][game] = max(dp['S'][changes][game], dp['S'][changes][game-1]);
            if(moves[game] == 'S') dp['S'][changes][game]++;
            if(game == n-1) ans = max(ans, dp['S'][changes][game]);
        }
    }

    // DEBUGGING
    // for(int i=0; i<=k; i++){
    //     for(int j=0; j<n; j++){
    //         cout << dp['H'][i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl;

    // for(int i=0; i<=k; i++){
    //     for(int j=0; j<n; j++){
    //         cout << dp['P'][i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl;

    // for(int i=0; i<=k; i++){
    //     for(int j=0; j<n; j++){
    //         cout << dp['S'][i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl;

    cout << ans << endl;
    return 0;

}