#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cowqueue.in" , "r" , stdin);
    freopen("cowqueue.out" , "w" , stdout);

    int n; cin >> n;
    vector<pair<int, int>> record(n);
    
    int t1, t2;
    for(int i=0; i<n; i++)
    {
        cin >> t1 >> t2;
        record[i].first = t1;
        record[i].second = t2;
    }
    sort(record.begin() , record.end());

    int total = 0, start, end;
    for(int i=0; i<n; i++)
    {
        start = max(record[i].first , total);
        total = start + record[i].second;
    }
    cout << total << endl;

}