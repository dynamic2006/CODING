#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    string s; cin >> s;
    string str = "";
    int delCount = 0;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] == '<') delCount++;
        else if(delCount > 0) delCount--;
        else str += s[i];
    }
    for(int i=0; i<str.size(); i++) cout << str[str.size()-1-i];
    cout << endl;
}