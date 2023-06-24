#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n+1);
    vector<int> b(n+1);
    vector<int> c(n+1);

    long long total = 0;

    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin >> b[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin >> c[i];
    }

    map<int,int> poss_values;
    for(int j=1; j<=n; j++)
    {
        poss_values[b[c[j]]]++;
    }

    for(int i=1; i<=n; i++)
    {
        if(poss_values.count(a[i]))
            total += poss_values[a[i]];
        // to optimize further, note that the if condition isn't needed
        // using just total += poss_values[a[i]] will get rid of O(log n) time count function
        // replacing it with just a O(n) search function
    }

    cout << total;
}