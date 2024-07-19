#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("c.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> heights(n);
        for(int i=0; i<n; i++) cin >> heights[i];

        int prevTime = heights[n-1];
        for(int i=n-2; i>=0; i--){
            prevTime = max(heights[i], prevTime+1);
        }
        cout << prevTime << endl;
    }
}