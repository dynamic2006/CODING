#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int arr[4];
        for(int i=0; i<4; i++) cin >> arr[i];

        int x = arr[1] + arr[0];
        int ans1 = 1;
        if(x+arr[1] == arr[2]) ans1++;
        if(x+arr[2] == arr[3]) ans1++;

        x = arr[2] - arr[1];
        int ans2 = 1;
        if(arr[0]+arr[1] == x) ans2++;
        if(x+arr[2] == arr[3]) ans2++;

        x = arr[3] - arr[2];
        int ans3 = 1;
        if(arr[0]+arr[1] == x) ans3++;
        if(x+arr[1] == arr[2]) ans3++;

        cout << max(ans3, max(ans1, ans2)) << endl;


    }
}