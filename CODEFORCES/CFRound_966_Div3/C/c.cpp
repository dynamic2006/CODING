#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("c.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        int m; cin >> m;
        vector<string> s(m);
        for(int i=0; i<m; i++) cin >> s[i];

        map<char, int> charToInt;
        for(int i=0; i<m; i++){
            if(s[i].size() != a.size()){
                cout << "NO" << endl;
                continue;
            }

            charToInt.clear();
            if()


        }
    }
}