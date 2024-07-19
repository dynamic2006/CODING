#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("b.in" , "r" , stdin);
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        string s, t; cin >> s >> t;
        if(s[0] == '1'){
            cout << "YES" << endl;
            continue;
        }

        int firstOneIdx = n;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                firstOneIdx = i;
                break;
            }
        }

        bool valid = true;
        for(int i=0; i<firstOneIdx; i++){
            if(t[i] != s[i]){
                valid = false;
                break;
            }
        }

        if(valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}