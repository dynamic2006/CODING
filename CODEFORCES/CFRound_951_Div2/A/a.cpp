#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("a.in" , "r" , stdin);

    int t; cin >> t;
    for(int tc=0; tc<t; tc++){
        int n; cin >> n;
        vector<int> a(n);
        int minMax = 1e9 + 1;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n-1; i++){
            minMax = min(minMax, max(a[i], a[i+1]));
        }
        cout << minMax - 1 << endl;
    }
}