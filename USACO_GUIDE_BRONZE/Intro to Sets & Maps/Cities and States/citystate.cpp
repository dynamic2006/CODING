#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("citystate.in" , "r" , stdin);
    freopen("citystate.out" , "w" , stdout);

    int n; cin >> n;
    int total = 0;
    map<string, int> m;
    string temp, city, state;

    for(int i=0; i<n; i++)
    {
        cin >> temp >> state;
        city = ""; city += temp[0]; city += temp[1];
        m[city + state]++;
        if(m.count(state + city) && state + city != city + state)
            total += m[state + city];
    }

    cout << total << endl;
}