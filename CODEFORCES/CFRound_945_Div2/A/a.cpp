#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        // cout << "SUM " << (a+b+c) % 2 << endl;
        if((a+b+c) % 2 == 1){
            cout << -1 << endl;
            continue;
        }

        int draws = 0;
        vector<int> players = {a, b, c};
        while(players[1] > 0){
            players[1]--;
            players[2]--;
            draws++;
            sort(players.begin(), players.end());
        }
        cout << draws << endl;
    }
}