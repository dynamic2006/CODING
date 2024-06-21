#include <bits/stdc++.h>
using namespace std;

const int MAXNUM = 1e9 + 1;

int n, m;
vector<int> cities, towers;

int main()
{
    //freopen("cellular.in" , "r" , stdin);

    cin >> n >> m;

    int a = MAXNUM;
    for(int i=0; i<n; i++){
        int b; cin >> b;
        if(b == a) continue;
        cities.push_back(b);
        a = b;
    }

    a = MAXNUM;
    for(int i=0; i<m; i++){
        int b; cin >> b;
        if(b == a) continue;
        towers.push_back(b);
        a = b;
    }

    int ans = 0;
    for(auto city : cities){
        auto nextTower = lower_bound(towers.begin(), towers.end(), city);
        auto prevTower = prev(nextTower);
        if(nextTower == towers.end()) nextTower = prevTower;
        if(nextTower == towers.begin()) prevTower = nextTower;
        //cout << "OLD ANS " << ans << " NEXT DIFF " << *nextTower - city  << " PREV DIFF " << city - *prevTower << endl;
        ans = max(ans, min(abs(*nextTower - city), abs(city - *prevTower)));
        //cout << ans << endl;
    }

    cout << ans << endl;

}