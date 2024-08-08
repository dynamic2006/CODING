#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("b.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        ll oneCount = 0;
        ll ans = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0' && oneCount > 0){
                ans += (oneCount+1);
            }
            else if(s[i] == '1') oneCount++;
        }
        cout << ans << endl;
    }
}