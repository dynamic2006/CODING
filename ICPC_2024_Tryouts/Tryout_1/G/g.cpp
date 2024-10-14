#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    map<int, vector<int>> groups;
    for(int i=0; i<n; i++){
        int s, c; cin >> s >> c;
        groups[s].push_back(c);
    }

    for(auto &x : groups){
        sort(x.second.begin(), x.second.end(), greater<int>());
    }

    double ans = 0;
    for(auto &x : groups){
        int size = x.second.size();
        for(int i=0; i<size/2; i++){
            ans += log((double)x.second[i]);
            // cout << i << " " << x.second[i] << " ";
            ans -= log((double)x.second[size-i-1]);
            // cout << i << " " << x.second[size-i-1] << endl;
        }
    }

    cout << setprecision(10) << ans << endl;
}