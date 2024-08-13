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
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        bool valid = true;
        int lo = a[0], hi = a[0];
        for(int i=1; i<n; i++){
            if(a[i] == hi+1){
                hi = a[i];
            }
            else if(a[i] == lo-1){
                lo = a[i];
            }
            else{
                valid = false;
                break;
            }

            // cout << lo << " " <<  hi << endl;
        }

        if(valid){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}