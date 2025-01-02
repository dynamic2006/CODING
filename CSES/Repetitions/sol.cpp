#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    string s; cin >> s;

    char prev = s[0];
    int ans = 1, curAns = 1;

    for(int i=1; i<s.size(); i++){
        if(s[i] == prev){
            curAns++;
        }
        else{
            prev = s[i];
            ans = max(ans, curAns);
            curAns = 1;
        }
    }
    cout << max(ans, curAns) << endl;
}