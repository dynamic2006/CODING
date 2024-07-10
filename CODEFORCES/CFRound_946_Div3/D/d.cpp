#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("d.in" , "r" , stdin);

    map<char, pair<int, int>> dir;
    dir['N'] = {0,1};
    dir['S'] = {0,-1};
    dir['E'] = {1,0};
    dir['W'] = {-1,0};

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        int overallx = 0, overally = 0;
        for(char c : s){
            overallx += dir[c].first;
            overally += dir[c].second;
        }
        if(overallx % 2 != 0 || overally % 2 != 0){
            cout << "NO" << endl;
            continue;
        }

        int destX = overallx/2, destY = overally/2;
        int rx = 0, ry = 0, hx = 0, hy = 0;

        //satisfy 1 move for rover
        //from now on, give all moves to helicopter unless needed for rover
        rx += dir[s[0]].first;
        ry += dir[s[0]].second;
        // hx += dir[s[1]].first;
        // hy += dir[s[1]].second;

        bool helicopterMoved = false;
        string moves = "R";

        for(int i=1; i<n; i++){
            if(s[i] == 'N'){
                if(hy <= ry){
                    hy++;
                    moves += 'H';
                    helicopterMoved = true;
                }
                else{
                    ry++;
                    moves += 'R';
                }
            }
            else if(s[i] == 'S'){
                if(hy >= ry){
                    hy--;
                    moves += 'H';
                    helicopterMoved = true;
                }
                else{
                    ry--;
                    moves += 'R';
                }
            }
            else if(s[i] == 'E'){
                if(hx <= rx){
                    hx++;
                    moves += 'H';
                    helicopterMoved = true;
                }
                else{
                    rx++;
                    moves += 'R';
                }
            }
            else{
                if(hx >= rx){
                    hx--;
                    moves += 'H';
                    helicopterMoved = true;
                }
                else{
                    rx--;
                    moves += 'R';
                }
            }
        }

        if(rx != hx || ry != hy || !helicopterMoved){
            cout << "NO" << endl;
            continue;
        }
        else cout << moves << endl;
    }
}