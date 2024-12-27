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
        vector<ll> cakes(n);
        ll total = 0;
        for(int i=0; i<n; i++){
            cin >> cakes[i];
            total += cakes[i];
        }
        int windowSize = n/2; windowSize++;

        ll minBessie = 0;
        ll curBessie = 0;
        for(int i=0; i<windowSize; i++){
            minBessie += cakes[i];
        }

        curBessie = minBessie;
        for(int i=0; i+windowSize<n; i++){
            curBessie -= cakes[i];
            curBessie += cakes[i+windowSize];
            minBessie = min(curBessie, minBessie);
        }

        cout <<  minBessie << " " << total - minBessie << endl;
    }
}