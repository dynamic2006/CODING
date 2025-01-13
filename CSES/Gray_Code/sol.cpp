#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    
    vector<string> code;
    string a = "";
    for(int i=0; i<n; i++) a += '0';

    code.push_back(a);
    code.push_back(a); code[code.size()-1][n-1] = '1';

    for(int i=2; i<=n; i++){
        int curSize = code.size();
        for(int j=curSize-1; j>=0; j--){
            code.push_back(code[j]);
            code[code.size()-1][n-i] = '1';
        }
    }

    for(auto& x : code) cout << x << endl;

}