#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("d.in" , "r" , stdin);

    int n, m; cin >> n >> m;
    vector<pair<int, int>> weaponTypes(n);
    vector<int> metalTypes(m);

    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        weaponTypes[i].first = a-b; //positive diff cost
        weaponTypes[i].second = -a; //negative of input cost
    }
    sort(weaponTypes.begin(), weaponTypes.end());

    for(int i=0; i<m; i++) cin >> metalTypes[i];
    sort(metalTypes.begin() , metalTypes.end(), greater<int>());

    int ans = 0;
    int mi = 0, wi = 0;
    while(mi < m){
        auto it = lower_bound(weaponTypes.begin(), weaponTypes.end())
        while(-weaponTypes[wi].second <= metalTypes[mi]){
            ans += 2;
            metalTypes[mi] -= weaponTypes[wi].first;
        }
        else if(mi)
    }

}