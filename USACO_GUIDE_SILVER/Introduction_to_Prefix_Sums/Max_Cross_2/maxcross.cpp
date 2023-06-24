#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("maxcross.in" , "r" , stdin);
    freopen("maxcross.out" , "w" , stdout);
    int n, k, b; cin >> n >> k >> b;
    int ans = n;
    vector<int> lights(n+1, 0); // stores 1 if light is borken at index (1-idx)
    vector<int> prefix_borken(n+1, 0);
    for(int i=1; i<=b; i++)
    {
        int id; cin >> id;
        lights[id] = 1;
    }
    for(int i=1; i<=n; i++)
    {
        //prefix counts borken lights so far including cur light if borken
        prefix_borken[i] = prefix_borken[i-1] + lights[i];
    }
    for(int i=0; i<=(n-k); i++)
    {
        //take min of all borken lights between any two indices separated by k lights
        //(since you need to fix that many lights, we minimize it)
        ans = min(ans, prefix_borken[i+k] - prefix_borken[i]);
    }
    cout << ans;
}

//overall, use large sized arrays and naively implement
//similar to using array to represent each unit of time