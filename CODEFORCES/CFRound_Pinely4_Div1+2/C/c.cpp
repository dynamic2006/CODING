#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("c.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        bool valid = true;
        for(int i=1; i<n; i++){
            if((a[i] - a[0]) % 2 != 0){
                valid = false; break;
            }
        }

        if(!valid){
            cout << -1 << endl;
            continue;
        }

        sort(a.begin(), a.end());
        //this makes sure every number is divisible by 2, a[0] = 0;
        cout << 32 << endl;
        cout << a[0] << " ";
        for(int i=n-1; i>=0; i--) a[i] -= a[0];
        for(int i=29; i>=0; i--){
            cout << (1<<i) << " ";
        }
        cout << 1 << endl;
    }
}