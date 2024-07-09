#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("c.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];

        int m; cin >> m;
        vector<int> d(m);
        map<int, int> numCounts;
        for(int i=0; i<m; i++){
            cin >> d[i];
            numCounts[d[i]]++;
        }

        bool valid = false;
        for(auto bi : b){
            if(d[m-1] == bi){
                valid = true;
                break;
            }
        }

        if(!valid){
            cout << "NO" << endl;
            continue;
        }

        for(int i=0; i<n; i++){
            if(a[i] == b[i]) continue;
            else if(numCounts[b[i]] == 0){
                valid = false;
                break;
            }
            else{
                numCounts[b[i]]--;
            }
        }

        if(valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}