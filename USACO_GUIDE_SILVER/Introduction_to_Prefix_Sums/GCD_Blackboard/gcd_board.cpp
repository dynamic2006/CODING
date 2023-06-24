#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("gcd_board.in" , "r" , stdin);
    int n; cin >> n;
    int ans = 0;

    vector<int> pregcd(n+1, 0);
    vector<int> sufgcd(n+2, 0);
    vector<int> arr(n+1, 0);

    for(int i=1; i<=n; i++)
    {
        cin >> arr[i];
        pregcd[i] = __gcd(pregcd[i-1], arr[i]);
    }
    for(int i=n; i>0; i--)
    {
        sufgcd[i] = __gcd(sufgcd[i+1], arr[i]);
    }
    for(int i=1; i<=n; i++)
    {
        ans = max(ans, __gcd(pregcd[i-1] , sufgcd[i+1]));
    }
    cout << ans;
}

/*
This is somewhat mathematical because the gcd of the whole thing is the gcd of the right and left sides
Also, gcd for either side is culmulative, meaning another number can be added be just taking the gcd
of the current prefix sum and the new number
*/