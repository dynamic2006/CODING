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

        string result = "";
        char c = s[0]; result += c;
        for(int i=1; i<n; i++){
            if(s[i] == '1') result += '1';
            else if(s[i] == '0' && c == '1') result += '0';
            c = s[i];
        }

        int count0 = 0, count1 = 0;
        for(auto& c : result){
            if(c == '1') count1++;
            else count0++;
        }

        if(count0 >= count1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}