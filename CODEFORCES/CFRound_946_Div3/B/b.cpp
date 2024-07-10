#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("b.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<char> c(n);
        for(int i=0; i<n; i++) c[i] = s[i];

        sort(c.begin() , c.end());
        c.erase(unique(c.begin() , c.end()) , c.end());
        
        map<char, char> key; key.clear();
        for(int i=0; i<c.size(); i++){
            key[c[i]] = c[c.size() - i - 1];
        }

        for(auto x : s){
            cout << key[x];
        }
        cout << endl;

    }
}