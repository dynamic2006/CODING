#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n, d, k; cin >> n >> d >> k;
        vector<int> jobDiffTable(n+d+2, 0);
        for(int i=0; i<k; i++){
            int l, r; cin >> l >> r;
            jobDiffTable[l]++;
            jobDiffTable[r+d+1]--;
        }

        int minDay = 1, maxDay = 1;
        int minCount = jobDiffTable[1], maxCount = jobDiffTable[1];
        vector<int> jobCount(n+d+2, 0);
        for(int i=1; i<n+d+1; i++){
            jobCount[i] = jobCount[i-1] + jobDiffTable[i];
            cout << jobCount[i] << " ";
            if(jobCount[i] < minCount){
                minDay = max(1, i-d+1);
                minCount = jobCount[i];
            }
            if(jobCount[i] > maxCount){
                maxDay = max(1, i-d+1);
                maxCount = jobCount[i];
            }
        }
        cout << endl;
        cout << maxDay << " " << minDay << endl;
    }
}