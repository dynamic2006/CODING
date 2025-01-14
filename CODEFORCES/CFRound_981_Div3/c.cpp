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
        vector<int> topics(n);
        for(int i=0; i<n; i++) cin >> topics[i];

        for(int i=n/2; i<n; i++){
            int j = n-i-1;
            if(topics[i] == topics[j]) continue;
            if(i-1 >= 0 && topics[i-1] == topics[i] || j+1 < n && topics[j+1] == topics[j]){
                int tmp = topics[i];
                topics[i] = topics[j];
                topics[j] = tmp;
            }
        }

        int ans = 0;
        for(int i=1; i<n; i++){
            if(topics[i] == topics[i-1]) ans++;
        }
        cout << ans << endl;
    }
}