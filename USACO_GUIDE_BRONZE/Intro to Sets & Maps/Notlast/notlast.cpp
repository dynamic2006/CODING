#include <bits/stdc++.h>
using namespace std;

int main()
{
    string names[7] = {"Bessie" , "Elsie" , "Daisy" , "Gertie" , "Annabelle" , "Maggie" , "Henrietta"};
    map<string , int> produce;
    vector<int> sorted(7);
    
    freopen("notlast.in" , "r" , stdin);
    freopen("notlast.out" , "w" , stdout);
    
    int n; cin >> n;
    string name; int milk;
    for(int i=0; i<7; i++)
    {
        produce[names[i]] = 0;
    }

    for(int i=0; i<n; i++)
    {
        cin >> name >> milk;
        produce[name] += milk;
    }
    for(int i=0; i<7; i++)
    {
        sorted[i] = produce[names[i]];
    }
    sort(sorted.begin() , sorted.end());

    int second_last = sorted[0]; int k = 0;
    while(second_last == sorted[0])
    {
        second_last = sorted[k++];
    }
    if(second_last == sorted[k])
    {
        cout << "Tie" << endl;
        return 0;
    }

    for(auto& x : produce)
    {
        if(x.second == second_last)
        {
            cout << x.first << endl;
            return 0;
        }
    }

}