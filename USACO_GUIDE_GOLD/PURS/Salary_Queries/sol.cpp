#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    int n, q; cin >> n >> q;

}
//segtree is coord-compressed values of a,b salaries
//set of a's and b's. Also make map for each a, b to idx
//keep vector of current salaries
//for update ! k x go to vector, get value p = salary[k]
//and update salary[k] = x;
//the following logic is probably incorrect:
//then get map[set.lowerbound(p)] = idx i in segtree. update(i, -1)
//also get map[set.lowerbound(x)] = idx j in segtree. update(j, +1)
//likely also need to consider diff update for a vs b

//for query ? a b print segtree.query(a,b+1)

//from solution
//instead of storing a,b as the segtree things
//store all possible salary values instead (ie, all intial p vals + x vals)
