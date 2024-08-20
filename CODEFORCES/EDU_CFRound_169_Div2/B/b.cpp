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
        int al, ar, bl, br; cin >> al >> ar >> bl >> br;
        if(ar < bl || br < al){
            cout << 1 << endl;
            continue;
        }
        int ans = min(ar, br) - max(al, bl);
        if(max(al, bl) != min(al, bl)) ans++;
        if(min(ar, br) != max(ar, br)) ans++;
        cout << ans << endl;
    }
}