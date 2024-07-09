#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("stacking.in" , "r" , stdin);
    // freopen("stacking.out" , "w" , stdout);

    int n, k; cin >> n >> k;
    vector<int> diff(n, 0);
    vector<int> prefix(n);

    for(int i=0; i<k; i++){
        int a, b; cin >> a >> b;
        diff[a-1]++;
        if(b != n) diff[b]--;
    }

    prefix[0] = diff[0];
    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] + diff[i];
    }

    sort(prefix.begin(), prefix.end());
    cout << prefix[n/2] << endl;

}