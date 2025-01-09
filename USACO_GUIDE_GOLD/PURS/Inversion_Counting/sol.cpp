#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll ans = 0;
        Tree<int> t;
        for(int i=0; i<n; i++){
            int a; cin >> a;
            t.insert(a);
            ans += i - t.order_of_key(a);
        }
        cout << ans << endl;
    }
}