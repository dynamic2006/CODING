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
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        int sum1 = 0, sum2 = 0, max1=0, max2=0;
        for(int i=0; i<n; i++){
            if(i%2){
                sum1++;
                if(a[i] > max1) max1 = a[i];
            }
            else{
                sum2 ++;
                if(a[i] > max2) max2 = a[i];
            }
        }

        cout << max(sum1+max1, sum2+max2) << endl;
    }
}