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

    int n; cin >> n;
    vector<int> nums(n+1); nums[0] = -1;
    Tree<int> tree;
    for(int i=1; i<=n; i++){
        cin >> nums[i];
        tree.insert(i);
    }

    vector<int> deletions(n);
    for(int i=0; i<n; i++){
        int delPos; cin >> delPos;
        int idx = *tree.find_by_order(delPos-1);
        cout << nums[idx] << " ";
        tree.erase(idx);
    }
    cout << endl;
}