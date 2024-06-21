#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("haybales.in" , "r" , stdin);
    freopen("haybales.out" , "w" , stdout);

    int n, q;
    cin >> n >> q;
    vector<int> locations(n);

    for(int i=0; i<n; i++){
        cin >> locations[i];
    }
    sort(locations.begin() , locations.end());

    for(int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;

       int ans = upper_bound(locations.begin(), locations.end(), b) - lower_bound(locations.begin(), locations.end(), a);
       cout << ans << endl;
    }
}