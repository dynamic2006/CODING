#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("subsum.in" , "r" , stdin);
    int n; cin >> n;
    int x; cin >> x;
    long long total = 0;
    vector<long long> prefix(n+1); prefix[0] = 0;
    map<long long, long long> prefix_occurences;
    prefix_occurences[0] = 1;
    for(int i=1; i<=n; i++)
    {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];

        //prefix[i] sum can be paired with prefix[i] - x to give x
        //add number of occurences of prefix[i] - x before this
        total += prefix_occurences[prefix[i] - x];

        prefix_occurences[prefix[i]]++;

    }
    cout << total;
}