//hint: a better sol uses a stars & bars perspective

#include <bits/stdc++.h>
using namespace std;

int n;

bool sorter(vector<int>& cows)
{
    int a = n;
    while (cows[a] <= a)
    {
        a--;
        if(a == -1)
            return false;
    }
    int b = n;
    while(cows[1] <= cows[b])
    {
        b--;
    }
    int i = max(a,b);

    for(int j=1; j<=i; j++)
    {
        cows[j-1] = cows[j];
    }
    cows[i] = cows[0];
    cows[0] = 0;
    return true;
}

int main()
{
    freopen("sleepy.in" , "r" , stdin);
    freopen("sleepy.out" , "w" , stdout);

    cin >> n;
    vector<int> starting_order(n+1);
    for(int i=1; i<=n; i++)
    {
        cin >> starting_order[i];
    }

    int total = 0;

    while(sorter(starting_order))
    {
        total++;
    }

    cout << total;

}