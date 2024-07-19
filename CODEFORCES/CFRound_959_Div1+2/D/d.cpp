#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("d.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int, bool>> a(n, {0,true});
        for(int i=0; i<n; i++) cin >> a[i].first;

        vector<int> mods;
        vector<pair<int, int>> ops(n-1);
        cout << "YES" << endl;
        for(int m=n-1; m>=1; m--){
            mods.clear();
            mods.resize(m, -1);
            for(int i=0; i<n; i++){
                if(a[i].second){
                    int mod = a[i].first % m;
                    if(mods[mod] != -1){
                        //cout << "CHECK " << mods[mod]+1 << " " << i+1 << endl;
                        ops[m-1] = {mods[mod]+1, i+1};
                        a[i].second = false;
                        break;
                    }
                    else mods[a[i].first % m] = i;
                }
            }
        }

        for(auto p : ops) cout << p.first << " " << p.second << endl;
    }
}