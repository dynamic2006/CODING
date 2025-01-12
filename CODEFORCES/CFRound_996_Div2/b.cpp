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
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++){
            int b; cin >> b;
            a[i] -= b;
        }

        bool valid = true;
        bool need = false;
        int needAmt = 0;
        for(int i=0; i<n; i++){
            if(a[i] < 0){
                if(need){
                    cout << "NO" << endl;
                    valid = false;
                    break;
                }
                need = true;
                needAmt = -a[i];
            }
        }
        if(!valid) continue;
        if(!need){
            cout << "YES" << endl;
            continue;
        }

        for(int i=0; i<n; i++){
            if(a[i] >= 0 && a[i] < needAmt){
                cout << "NO" << endl;
                valid = false;
                break;
            }
        }

        if(valid) cout << "YES" << endl;
    }
}