#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    string s; cin >> s;
    vector<char> firstPerm;
    for(int i=0; i<s.size(); i++) firstPerm.push_back(s[i]);
    sort(firstPerm.begin(), firstPerm.end());

    vector<string> perms;
    do{
        string z = "";
        for(int i=0; i<s.size(); i++) z += firstPerm[i];
        perms.push_back(z);
    }while(next_permutation(firstPerm.begin(), firstPerm.end()));

    cout << perms.size() << endl;
    for(auto &perm : perms) cout << perm << endl;

}