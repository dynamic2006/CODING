#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;

    char c = s[0];
    int p = n;
    for(int i=0; i<n; i++){
        if(s[i] != c){
            p = i-1;
            break;
        }
        if((i+1)%k == 0){
            if(c == '0') c = '1';
            else c = '0';
        }
    }

    cout << "PVAL " << p << endl;

    if(p == n){
        cout << n << endl;
        return;
    }

    int counter = 0;
    c = s[p+1];
    for(int i=p+1; i<n; i++){
        if(s[i] != c){
            cout << "-1" << endl;
            return;
        }
        if((++counter)%k == 0){
            if(c == '0') c = '1';
            else c = '0';
        }
    }
    for(int i=p-1; i>=0; i--){
        if(s[i] != c){
            cout << "-1" << endl;
            return;
        }
        if(++counter%k == 0){
            if(c == '0') c = '1';
            else c = '0';
        }
    }

    cout << p+1 << endl;
}

int main()
{
    freopen("d.in" , "r" , stdin);

    int t; cin >> t;
    while(t--) solve();
}