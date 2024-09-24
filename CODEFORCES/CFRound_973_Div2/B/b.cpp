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
        vector<ll> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        ll diff = a[n-2];
        for(int i=n-3; i>=0; i--){
            diff -= a[i];
        }
        cout << a[n-1] - diff << endl;
    }
}