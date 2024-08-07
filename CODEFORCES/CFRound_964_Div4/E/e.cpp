#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("e.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;
        int ans = 0, count = 0;

        int temp = l;
        while(temp > 0){
            temp /= 3;
            count++;
        }
        ans += count;

        int pow3 = pow(3, count);
        int prevPow3 = l;

        int i = min(r+1, pow3);
        while(i <= r+1){
            ans += count*(i - prevPow3);
            count++;
            prevPow3 = pow3;
            pow3 = pow(3, count);
            if(i == r+1) break;
            i = min(r+1, pow3);
        }
        cout << ans << endl;
    }
}