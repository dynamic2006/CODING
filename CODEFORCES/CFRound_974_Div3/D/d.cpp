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
        int n, d, k; cin >> n >> d >> k;
        //each day from 1 -> n-d+1 can be start day
        //so job from l to r affects start days l-d+1 to r
        vector<int> diffTable(n+2, 0);
        for(int i=0; i<k; i++){
            int l, r; cin >> l >> r;
            diffTable[max(1, l-d+1)]++;
            diffTable[r+1]--;
        }

        int maxDay = 1, minDay = 1;
        vector<int> prefixSum(n+2, 0);
        for(int i=1; i<=n-d+1; i++){
            prefixSum[i] = prefixSum[i-1] + diffTable[i];
            if(prefixSum[i] > prefixSum[maxDay]) maxDay = i;
            if(prefixSum[i] < prefixSum[minDay]) minDay = i;
        }
        cout << maxDay << " " << minDay << endl;
    }
}