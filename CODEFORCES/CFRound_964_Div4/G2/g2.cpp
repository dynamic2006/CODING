#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("g2.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int lo = 333, hi = 666;
        int loBound = 1, hiBound = 1000;
        while(loBound<hiBound){
            cout << "? " << lo << " " << hi << endl;
            int response; cin >> response;
            if(response == lo*hi){
                int delta = (hiBound-hi)/3;
                loBound = hi+1;
                lo = loBound + delta;
                hi = hiBound - delta;
            }
            else if(response == lo*(hi+1)){
                int delta = (hi - lo)/3;
                loBound = lo+1;
                hiBound = hi;
                lo = loBound + delta;
                hi = hiBound - delta;
            }
            else{
                int delta = (lo - loBound)/3;
                hiBound = lo;
                lo = loBound + delta;
                hi = hiBound - delta;
            }
        }
        cout << "! " << loBound << endl;
    }
}