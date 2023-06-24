#include <bits/stdc++.h>
using namespace std;

int intersect(const set<string>& a, const set<string>& b)
{
    int total = 0;
    for(const string& it : a)
    {
        if(b.count(it))
            total++;
    }
    return total;
}

int main()
{
    freopen("guess.in" , "r" , stdin);
    freopen("guess.out" , "w" , stdout);

    int n; cin >> n;
    int cur_max = 0;

    vector<set<string>> animals(n);
    for(int i=0; i<n; i++)
    {
        string name; cin >> name;
        int k; cin >> k;
        string trait;
        for(int j=0; j<k; j++)
        {
            cin >> trait;
            animals[i].insert(trait);
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            cur_max = max(intersect(animals[i] , animals[j]) , cur_max);
        }
    }

    cout << cur_max + 1;
}