#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

struct Ranges
{
    int l, r, t;
};
bool cmp(Ranges &a, Ranges &b){
    if(a.r < b.r) return true;
    if(a.r == b.r && a.l < b.l) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        set<int> pos;
        vector<Ranges> ranges(k);
        for(int i=0; i<n; i++){
            int a; cin >> a; pos.insert(a);
        }
        for(int i=0; i<k; i++){
            int l, r, t; cin >> l >> r >> t;
            ranges[i].l = l;
            ranges[i].r = r;
            ranges[i].t = t;
        }
        pos.insert(1e9 + 1);
        sort(ranges.begin(), ranges.end(), cmp);

        int ans = 0;
        Tree<int> tree;
        for(int i = 0; i < k; i++){
            int curCount = tree.order_of_key(ranges[i].r + 1) - tree.order_of_key(ranges[i].l);
            auto it = prev(pos.upper_bound(ranges[i].r));
            // cout << *it << " ";
            for(int j=0; j<(ranges[i].t - curCount); j++, ans++){
                tree.insert(*it);
                pos.erase(*it);
                it = prev(pos.upper_bound(ranges[i].r));
                // cout << *it << " ";
            }
        }
        cout << n - ans << endl;
    }
}