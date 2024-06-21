#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> diamonds;

int main()
{
    freopen("diamond.in" , "r" , stdin);
    freopen("diamond.out" , "w" , stdout);

    cin >> n >> k;
    diamonds.resize(n);
    for(int i=0; i<n; i++) cin >> diamonds[i];
    sort(diamonds.begin() , diamonds.end());
    
    //prevLargestCase[i] is the largest case size using only up to and including diamonds[i]
    //afterLargestCase[i] is largest case size using only diamonds[i] and afterwards
    vector<int> prevLargestCase(n), afterLargestCase(n);

    int l=0, r=0;
    prevLargestCase[0] = 1;
    while(l<n){
        while(r+1<n && diamonds[r+1] <= diamonds[l] + k){
            r++;
            prevLargestCase[r] = max(prevLargestCase[r-1], r-l+1);
        }
        //prevLargestCase[r] = max(prevLargestCase[r-1], r-l+1);
        l++;
    }

    l=n-1; r=n-1;
    afterLargestCase[n-1] = 1;
    while(r >= 0){
        while(l-1 >= 0 && diamonds[l-1] >= diamonds[r] - k){
            l--;
            afterLargestCase[l] = max(afterLargestCase[l+1], r-l+1);
        }
        //afterLargestCase[l] = max(afterLargestCase[l+1], r-l+1);
        r--;
    }

    //DEBUG
    // for(int i=0; i<n; i++) cout << i << " ";
    // cout << endl;
    // for(auto a : prevLargestCase) cout << a << " ";
    // cout << endl;
    // for(auto b : afterLargestCase) cout << b << " ";

    int ans = max(prevLargestCase[n-1], afterLargestCase[0]);
    for(int i=0; i<n-1; i++){
        ans = max(ans, prevLargestCase[i] + afterLargestCase[i+1]);
        //cout << "ANS " << ans << " i " << i << endl;
    }
    cout << ans << endl;


}