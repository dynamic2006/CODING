#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    ll n, k; cin >> n >> k;
    ll digits = 0;
    ll tempN = n;
    while(tempN/k > 0){
        digits++;
        tempN/=k;
    }

    tempN = n;
    vector<int> digs;
    for(int i=0; i<digits; i++){
        digs.push_back(tempN%10);
        tempN /= 10;
    }

    ll ans = 0;
    for(int i=0; i<min(digits, k); i++){
        
    }
}