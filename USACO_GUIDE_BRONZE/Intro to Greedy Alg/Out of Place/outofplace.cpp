#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("outofplace.in" , "r" , stdin);
    freopen("outofplace.out" , "w" , stdout);

    vector<int> cows;
    vector<int> cows_sorted;
    int n; cin >> n;
    int cur = 0, prev = 0;
    for(int i=0; i<n; i++)
    {
        cin >> cur;
        if(cur != prev)
        {
            cows.push_back(cur);
            cows_sorted.push_back(cur);
        }
        prev = cur;
    }
    sort(cows_sorted.begin() , cows_sorted.end());

    int wrong_order = 0;
    for(int i=0; i<cows.size(); i++)
    {
        if(cows.at(i) != cows_sorted.at(i))
        {
            wrong_order++;
        }
    }

    cout << wrong_order - 1 << endl;


}