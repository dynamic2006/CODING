#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("towers.in" , "r" , stdin);

    int n, block; cin >> n;
    vector<int> blocks(n);
    multiset<int> top_sizes;

    cin >> block;
    top_sizes.insert(block);

    for(int i=1; i<n; i++){

        cin >> block;

        if(top_sizes.upper_bound(block) != top_sizes.end()) top_sizes.erase(top_sizes.upper_bound(block));
        top_sizes.insert(block);

    }

    cout << top_sizes.size() << endl;
}