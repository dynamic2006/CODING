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
        ll n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        ll totPresses = 0;
        ll cansBought = 0;
        ll lastSlotAmt = 0;
        for(int i=0; i<n; i++){
            if(lastSlotAmt == a[i]){
                //already emptied this slot
                totPresses++;
            }
            else{
                ll extra = (a[i]-lastSlotAmt)*(n-i);
                if(extra + cansBought >= k){
                    totPresses += k - cansBought;
                    cout << totPresses << endl;
                    break;
                }
                else{
                    totPresses += extra+1;
                    cansBought += extra;
                    lastSlotAmt = a[i];
                }

            }
        }
    }
}