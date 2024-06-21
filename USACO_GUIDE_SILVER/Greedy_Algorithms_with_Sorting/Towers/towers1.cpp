#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("towers.in" , "r" , stdin);

    int n; cin >> n;
    vector<int> blocks(n);
    for(int i=0; i<n; i++) cin >> blocks[i];

    vector<int> towerTops;
    for(auto block : blocks){
        auto it = upper_bound(towerTops.begin(), towerTops.end(), block);
        if(it == towerTops.end()){
            towerTops.push_back(block);
        }
        else{
            *it = block;
        }
    }
    cout << towerTops.size() << endl;
}