#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

using Tree = tree<pair<int, int> , null_type, less_equal<pair<int, int>> , rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        Tree tree;
        vector<int> complement(n, 0);
        for(int i=n-1; i>=0; i--){
            tree.insert({a[i], i});
            complement[i] = tree.order_of_key({a[i], i});
        }

        for(int i=0; i<n; i++){
            cout << i << " " << complement[i] << endl;
        }
        cout << endl;

        int ans = n;
        for(int i=0; i<n; i++){
            ans = min(ans, n - complement[i] - i);
        }
        cout << ans << endl;
    }
}