#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
       int n; cin >> n;
       string str = "";
       bool end = false;
       while(str.size() < n){
            if(end){
                bool substr = false;
                cout << "? " << "1" << str << endl;
                cin >> substr;
                if(substr) str = '1' + str;
                else str = '0' + str;
                continue;
            }

            bool substr = false;
            cout << "? " << str << "1" << endl;
            cin >> substr;
            if(substr){
                str += '1';
            }
            else{
                cout << "? " << str << "0" << endl;
                cin >> substr;
                if(substr){
                    str += '0';
                }
                else if(str[0] == '1'){
                    str = '0' + str;
                    end = true;
                }
                else{
                    str = '1' + str;
                    end = true;
                }
            }
            // cout << "STRSIZE " << str.size() << endl;
       }
       cout << "! " << str << endl;
    }
}