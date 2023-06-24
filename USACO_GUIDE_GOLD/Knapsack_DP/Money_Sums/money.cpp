#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

bool sums[MAXN+1];

int main() {

    //freopen("money.in" , "r" , stdin);

    int n; cin >> n;

    for(int i=0; i<n; i++){
        int coin; cin >> coin;
        for(int j=MAXN; j>coin; j--){
            if(sums[j-coin]) sums[j] = true;
        }
        sums[coin] = true;
    }

    int ans = 0;
    string allSums = "";

    for(int i=0; i<=MAXN; i++){
        if(sums[i]){
            ans++;
            allSums += to_string(i) + " ";
        }
    }

    cout << ans << endl << allSums << endl;
    return 0;

}