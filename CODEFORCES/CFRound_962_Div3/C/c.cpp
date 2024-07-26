#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("c.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        vector<vector<int>> occsA(n+1, vector<int>(26,0)), occsB(n+1, vector<int>(26,0));
        string a, b;
        cin >> a;
        cin >> b;
        vector<int> prefixA(26,0), prefixB(26,0);

        //cout << "CHECK" << endl;

        for(int i=1; i<=n; i++){
            ++prefixA[a[i-1] - 'a'];
            ++prefixB[b[i-1] - 'a'];
            occsA[i] = prefixA;
            occsB[i] = prefixB;
        }

        //cout << "CHECK" << endl;
        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<26; j++){
        //         cout << occsA[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // return 0;
        
        for(int i=0; i<q; i++){
            int diff = 0;
            int l, r; cin >> l >> r;
            for(int j=0; j<26; j++){
                diff += abs((occsA[r][j] - occsA[l-1][j]) - (occsB[r][j] - occsB[l-1][j]));
                //cout << occsA[r][j] << " " << occsA[l-1][j] << " " << occsB[r][j] << " " << occsB[l-1][j] << " CUR DIFF " << diff << endl;
            }
            cout << diff/2 << endl;
        }
        //cout << endl;
    }

}