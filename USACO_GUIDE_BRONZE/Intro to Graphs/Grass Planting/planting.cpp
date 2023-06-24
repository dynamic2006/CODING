#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("planting.in" , "r" , stdin);
    freopen("planting.out" , "w" , stdout);

    int n; cin >> n;
    vector<int> deg(n+1);
    for(int i=1; i<n ; i++)
    {
        int f1, f2; cin >> f1 >> f2;
        deg[f1]++; deg[f2]++;
    }
    sort(deg.begin() , deg.end());
    cout << deg[n] + 1 << endl;
}