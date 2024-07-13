#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("d.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        //cout << n << " " << m << " " << k << endl;
        vector<vector<int>> heights(n, vector<int>(m)), snowy(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> heights[i][j];
            }
        }
        for(int i=0; i<n; i++){
            string s; cin >> s;
            for(int j=0; j<m; j++){
                snowy[i][j] = s[j] - '0';
            }
        }

        ll netSnowyHeight = 0; //net snowy - not snowy height
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(snowy[i][j]) netSnowyHeight += heights[i][j];
                else netSnowyHeight -= heights[i][j];
            }
        }

        vector<vector<ll>> prefixSnowy(n+1, vector<ll>(m+1, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                prefixSnowy[i+1][j+1] = prefixSnowy[i][j+1] + prefixSnowy[i+1][j] - prefixSnowy[i][j] + snowy[i][j];
            }
        }

        //DEBUG
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout << snowy[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<=m; j++){
        //         cout << prefixSnowy[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        //if(t == 3) cout << netSnowyHeight << endl;
        ll gcd = -1;
        bool valid = false;
        for(int i=k; i<=n; i++){
            for(int j=k; j<=m; j++){
                ll snow = prefixSnowy[i][j] - prefixSnowy[i-k][j] - prefixSnowy[i][j-k] + prefixSnowy[i-k][j-k];
                //if(t == 3)cout << "SNOW " << snow << endl;
                ll netDiff = abs(k*k - 2*snow);
                if(netDiff == 0) continue;

                if(gcd == -1) gcd = netDiff;
                else gcd = __gcd(gcd, netDiff);
                //if(t == 3)cout << "NET DIFF " << netDiff << endl;

                //BEZOUT'S IDENTITY!!
                if(netSnowyHeight % gcd == 0){
                    valid = true; break;
                }
            }
            if(valid) break;
        }

        if(valid || netSnowyHeight == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
        //cout << endl;
        //return 0;
    }
}