#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("d.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        string s; cin >> s;
        string river = "L" + s + "L";

        vector<bool> states(n+2, false);
        states[n+1] = true; //at end bank
        
        vector<int> waterTraveled(n+2, -1);
        waterTraveled[n+1] = 0;

        for(int i=n; i>=0; i--){
            if(river[i] == 'L'){
                for(int j=i+1; j<=min(i+m, n+1); j++){
                    //cout << i << " LOG CHECK " << j << " INDEX" << endl;
                    if(states[j] && waterTraveled[j] <= k){
                        states[i] = true;
                        if(waterTraveled[i] == -1) waterTraveled[i] = waterTraveled[j];
                        else waterTraveled[i] = min(waterTraveled[i], waterTraveled[j]);
                    }
                }
            }
            else if(river[i] == 'W'){
                //cout << i << " WATER CHECK" << endl;
                if(states[i+1] && waterTraveled[i+1]<=k) states[i] = true;
                waterTraveled[i] = waterTraveled[i+1] + 1;
            }
            else states[i] == false;
        }

        // int x = 0;
        // for(auto w : waterTraveled){
        //     cout << x << ":" << w << " ";
        //     x++;
        // }
        // cout << endl;
        // x = 0;
        // for(auto state : states){
        //     cout << x << ":" << state << " ";
        //     x++;
        // }

        if(states[0]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}