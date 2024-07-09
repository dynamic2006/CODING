#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        string s; cin >> s;

        map<char, int> diffCounts;
        for(auto c : s) diffCounts[c]++;

        int ans = m-min(m, diffCounts['A']);
        ans += m-min(m, diffCounts['B']);
        ans += m-min(m, diffCounts['C']);
        ans += m-min(m, diffCounts['D']);
        ans += m-min(m, diffCounts['E']);
        ans += m-min(m, diffCounts['F']);
        ans += m-min(m, diffCounts['G']);

        cout << ans << endl;
    }
}