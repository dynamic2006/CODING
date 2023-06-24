#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    long long total = 0;
    vector<int> arr(n+1, 0);
    vector<int> prefix(n+1, 0);
    map<long long, long long> m; m[0] = 1;
    for(int i=1; i<=n; i++)
    {
        char c; cin >> c;
        arr[i] = c - '0';
        prefix[i] = prefix[i-1] + arr[i];
        m[prefix[i] - i]++;
    }
    for(auto x : m)
    {
        total += x.second*(x.second-1)/2;
    }
    cout << total << endl;
}

int main()
{
    //freopen("goodsub.in" , "r" , stdin);
    int t; cin >> t;
    for(int i=0; i<t; i++)
    {
        solve();
    }
}
//use math to manipulate prefix[i] - prefix[j] = i - j
//to prefix[i] - i = prefix[j] - j = x
//then use map to count y = all occurences of x
//then just do y choose 2