#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("c.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        string s; cin >> s;
        vector<int> idx(m);
        for(int i=0; i<m; i++) cin >> idx[i];
        string c; cin >> c;

        sort(c.begin(), c.end(), greater<char>());
        sort(idx.begin(), idx.end(), greater<int>());
        idx.erase(unique(idx.begin(), idx.end()), idx.end());

        for(int i = m - idx.size(), j = 0; i<m, j<idx.size(); i++, j++){
            s[idx[j] - 1] = c[i];
        }
        cout << s << endl;
    }
}