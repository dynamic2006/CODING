#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("g1.in", "r", stdin);
    int t; cin >> t;
    while(t--){
        int lo = 2, hi = 999;
        while(lo<hi){
            int mid = (hi+lo)/2;
            cout << "? 1 " << mid << endl;
            int num; cin >> num;
            if(num > mid){
                hi = mid;
            }
            else lo = mid+1;
        }
        cout << "! " << lo << endl;
    }
}