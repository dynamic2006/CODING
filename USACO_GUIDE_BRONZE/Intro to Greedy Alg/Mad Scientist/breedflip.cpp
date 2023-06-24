#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("breedflip.in" , "r" , stdin);
    freopen("breedflip.out" , "w" , stdout);

    int n; cin >> n;
    string a, b; cin >> a >> b;
    int total = 0;

    bool new_range = true;
    
    for(int i=0; i<n; i++)
    {
        if(a[i] != b[i])
        {
            if(new_range)
            {
                new_range = false;
                total++;
            }
        }
        else
        {
            new_range = true;
        }
    }

    cout << total;
}