#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("breed_id.in" , "r" , stdin);
    // freopen("breed_id.out" , "w" , stdout);

    int n; cin >> n;
    int temp;
    int evens = 0, odds = 0;
    for(int i=0; i<n; i++)
    {
        cin >> temp;
        if(temp % 2)
            odds++;
        else evens++;
    }

    if(odds < evens)
    {
        cout << 2*odds + 1 << endl;
        return 0;
    }
    else if(odds == evens)
    {
        cout << 2*odds << endl;
        return 0;
    }
    else
    {
        int ans = 2 * (evens - 1);
        int new_size = odds - evens + 1; // atleast 2 odds, 1 even
        int x = new_size / 3;
        if(new_size % 3 == 0 || new_size % 3 == 2)
            ans += 2*x + 1;
        else ans += 2*x + 2;
        cout << ans << endl;
        return 0;
    }
}