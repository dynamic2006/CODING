#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("c.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int, int>> endpts(3);
        vector<int> order = {0,1,2};
        vector<vector<ll>> vals(3, vector<ll>(n, 0));

        for(int i=0; i<3; i++){
            for(int j=0; j<n; j++) cin >> vals[i][j];
        }

        ll total = 0;
        for(int j=0; j<n; j++) total += vals[0][j];
        
        bool found = false;
        ll threshold = (total+2)/3;
        do{
            int ptr = 0, idx = 0;
            ll curSum = 0;
            endpts[order[idx]].first = ptr+1;
            while(curSum < threshold && ptr<n){
                curSum += vals[order[idx]][ptr];
                if(curSum >= threshold){
                    curSum = 0;
                    endpts[order[idx]].second = ptr + 1;
                    if(idx == 2){
                        endpts[order[idx]].second = n;
                        found = true; break;
                    }
                    else idx++;

                    endpts[order[idx]].first = ++ptr + 1;
                }
                else ++ptr;
            }
            if(found) break;

        }while(next_permutation(order.begin() , order.end()));

        if(found) cout << endpts[0].first << " " << endpts[0].second << " " << endpts[1].first << " " << endpts[1].second << " " << endpts[2].first << " " << endpts[2].second << endl;
        else cout << -1 << endl;
    }
}