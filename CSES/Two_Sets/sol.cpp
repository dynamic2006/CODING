#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    ll n; cin >> n;
    ll sum = n*(n+1)/2;
    if(sum%2){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    sum /= 2;

    vector<int> used, unused;
    ll curSum = 0;
    for(ll i=n; i>=1; i--){
        if(curSum + i <= sum){
            curSum += i;
            used.push_back(i);
        }
        else unused.push_back(i);
    }

    cout << used.size() << endl;
    for(auto &x : used) cout << x << " ";
    cout << endl;

    cout << unused.size() << endl;
    for(auto &x : unused) cout << x << " ";
    cout << endl;

}